#include "Jogador.h"

#include "Inimigo.h"
#include "../../Gerenciador/Tempo.h"
#include "../../Gerenciador/Grafico.h"

#include <SFML/Window/Keyboard.hpp>
#include"organiza.h"

using sf::Keyboard;
using sf::Vector2f;
using std::cerr;
using std::endl;

CMD::Entidades::Personagens::Jogador::Jogador():
    Jogador(1, sf::String(""))
{
}

CMD::Entidades::Personagens::Jogador::Jogador(int jogadorX, sf::String texto):
    Personagem(),
    pontos(0),
    jogador(jogadorX),
    nome(),
    recuando(false),
    pegajoso(false),
    tempoInvulneravel(0.f)
{
    num_vida = 6;
    nome.setString(texto);
    if (pGG != NULL)
        nome.setFont(pGG->getFonte());
}

CMD::Entidades::Personagens::Jogador::Jogador(
    int jogadorX,
    const sf::Font& fonte,
    sf::String texto):
    Personagem(),
    pontos(0),
    jogador(jogadorX),
    nome(texto, fonte, 20),
    recuando(false),
    pegajoso(false),
    tempoInvulneravel(0.f)
{
    num_vida = 6;
}

CMD::Entidades::Personagens::Jogador::~Jogador()
{
}


//baseado na colisão de Hilze Vonck
bool CMD::Entidades::Personagens::Jogador::colidir(Personagens::Inimigo* pIn) {
    if (pIn == NULL) {
        cerr << "Inimigo nulo" << endl;
        return false;
    }

    const float dx = pIn->getX() - getX();
    const float dy = pIn->getY() - getY();
    const float interx =
        (getLargura() + pIn->getLargura()) / 2.f - std::abs(dx);
    const float intery =
        (getAltura() + pIn->getAltura()) / 2.f - std::abs(dy);

    if (interx > 0.f && intery > 0.f) {
        if (interx < intery) {
            if (dx > 0.f) {
                setPosicao({ getX() - interx, getY() });
                if (tempoInvulneravel <= 0.f)
                    velocidade.x = 0.f;
                pIn->danificar(this);
            } else {
                setPosicao({ getX() + interx, getY() });
                if (tempoInvulneravel <= 0.f)
                    velocidade.x = 0.f;
                pIn->danificar(this);
            }
        } 
        else {
            if (dy > 0.f) {
                setPosicao({ getX(), getY() - intery });
                esta_no_chao = true; // fazer que nem no mário
                esmagar(pIn);
            } else {
                setPosicao({ getX(), getY() + intery });
                if (tempoInvulneravel <= 0.f)
                    velocidade.y = 0.f;
                pIn->danificar(this);
            }
        }
        return true;
    }
    return false;
}

void CMD::Entidades::Personagens::Jogador::executar() {
    gravitar();
    mover();
}

void CMD::Entidades::Personagens::Jogador::salvar() {

}
int & CMD::Entidades::Personagens::Jogador::operator++(){
    return ++pontos;
}
void CMD::Entidades::Personagens::Jogador::setPegajoso(bool estado) {
    pegajoso = estado;
}

void CMD::Entidades::Personagens::Jogador::receberDanoDeInimigo(
    int dano,
    const sf::Vector2f posicaoInimigo) {
    if (num_vida <= 0 || tempoInvulneravel > 0.f || dano <= 0)
        return;

    num_vida = std::max(0, num_vida - dano);
    tempoInvulneravel = 1.f;

    const float diferencaX = getX() - posicaoInimigo.x;
    const float direcaoEmpurrao = diferencaX == 0.f
        ? (recuando ? 1.f : -1.f)
        : (diferencaX > 0.f ? 1.f : -1.f);
    velocidade.x = direcaoEmpurrao * 350.f;
    velocidade.y = -300.f;
    esta_no_chao = false;
}

void CMD::Entidades::Personagens::Jogador::reiniciar() {
    num_vida = 3;
    velocidade = sf::Vector2f(0.f, 0.f);
    esta_no_chao = false;
    pegajoso = false;
    recuando = false;
    tempoInvulneravel = 0.f;
}

void CMD::Entidades::Personagens::Jogador::mover() {
    sf::Vector2f dv(0, 0);
    float dt = Gerenciador::Tempo::getSegundos();
    tempoInvulneravel = std::max(0.f, tempoInvulneravel - dt);
    const bool movimentoLento = pegajoso;
    pegajoso = false;
    const float aceleracaoHorizontal = movimentoLento ? 100.f : 800.f;
    const float velocidadeMaximaChao = movimentoLento ? 75.f : 400.f;
    const float velocidadeMaximaAr = movimentoLento ? 90.f : 500.f;
    const Keyboard::Key teclaPular = jogador == 1 ? Keyboard::Up : Keyboard::W;
    const Keyboard::Key teclaEsquerda = jogador == 1 ? Keyboard::Left : Keyboard::A;
    const Keyboard::Key teclaDireita = jogador == 1 ? Keyboard::Right : Keyboard::D;
    if (esta_no_chao && Keyboard::isKeyPressed(teclaPular)) {
            velocidade.y -= 600.;
            esta_no_chao = false;
        }

        if (Keyboard::isKeyPressed(teclaEsquerda)){
            dv.x -= aceleracaoHorizontal;
            if(!recuando){
                recuando = true;
                getFig()->setScale(-1,1);
            }
        }
        if (Keyboard::isKeyPressed(teclaDireita)){
            dv.x += aceleracaoHorizontal;
            if(recuando){
                recuando = false;
                getFig()->setScale(1,1);
            }
        }
        velocidade += dv;
        if(esta_no_chao){
            velocidade.x *= 0.85f;

            if (std::abs(velocidade.x) > velocidadeMaximaChao) {

                if(velocidade.x > 0)
                    velocidade.x = velocidadeMaximaChao;
                else
                    velocidade.x = -velocidadeMaximaChao;
                }

                if (std::abs(velocidade.x) < 1.f)
                        velocidade.x = 0.f;
        }
        else {
            velocidade.x *= 0.98f;

            if (std::abs(velocidade.x) > velocidadeMaximaAr) {
                if(velocidade.x > 0)
                        velocidade.x = velocidadeMaximaAr;
                else
                    velocidade.x = -velocidadeMaximaAr;

            }
        }
    //     velocidade.x *= 0.3f;
    //     if (velocidade.x < 1.f)
    //         velocidade.x = 0;
    // else {
    //     velocidade.x *= 0.9993f;
    // }

    //if (dv.x != 0 && dv.y != 0)
        //dv *= (float) 0.7071067811865475244; // 1/sqrt(2)
    //if (dv.x != 0 && velocidade.y < 0)
        //dv.x *= cos(atan(velocidade.y/(float)velocidade.x));

    Entidade::mover(velocidade*dt);
    //std::cout << velocidade.x << "\t" << velocidade.y << "\t"<< std::endl;
}
void CMD::Entidades::Personagens::Jogador::esmagar(Personagens::Inimigo* pIn){
    const int danoDoJog = 3;
    for (int i = 0; i < danoDoJog; ++i) {
        pIn->operator--();
        operator++();//temporario
    }
}
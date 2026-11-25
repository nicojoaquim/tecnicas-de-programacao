#include "Jogador.h"

#include "Inimigo.h"
#include "../../Gerenciador/Tempo.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Tilemap.h"

#include <SFML/Window/Keyboard.hpp>
#include "../../organiza.h"

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
    num_vida = VIDA_INICIAL;
    nome.setString(texto);
    if (pGG != NULL)
        nome.setFont(pGG->getFonte());
}

CMD::Entidades::Personagens::Jogador::Jogador(int jogadorX,
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
    num_vida = VIDA_INICIAL;
}

CMD::Entidades::Personagens::Jogador::~Jogador()
{
    if (getFig() != NULL)
        delete getFig();
}

void CMD::Entidades::Personagens::Jogador::carregarSprite() {
    sf::Sprite* pSprite = new sf::Sprite;

    if (jogador == 1)
        pSprite->setTexture(pGG->getTexJogador1());
    else
        pSprite->setTexture(pGG->getTexJogador2());

    atribuirSprite(pSprite);
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
    const sf::Vector2f posicaoInimigo)
{
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
    num_vida = VIDA_INICIAL;// VIDA_INICIAL/2;
    velocidade = sf::Vector2f(0.f, 0.f);
    esta_no_chao = false;
    pegajoso = false;
    recuando = false;
    tempoInvulneravel = 0.f;
}

void CMD::Entidades::Personagens::Jogador::setJogador(int jogadorX) {
    jogador = jogadorX;
}

void CMD::Entidades::Personagens::Jogador::mover() {
    sf::Vector2f dv(0, 0);
    float dt = Gerenciador::Tempo::getSegundos();
    float ts = Tilemap::getTileSize();
    tempoInvulneravel = std::max(0.f, tempoInvulneravel - dt);
    const bool movimentoLento = pegajoso;
    pegajoso = false;

    const float aceleracaoHorizontal = movimentoLento ? 4*ts : 16*ts;
    const float velocidadeMaximaChao = movimentoLento ? 2*ts : 8*ts;
    const float velocidadeMaximaAr = movimentoLento ? 3.6*ts : 10*ts;

    const Keyboard::Key teclaPular = (jogador == 1) ? Keyboard::Up : Keyboard::W;
    const Keyboard::Key teclaEsquerda = (jogador == 1) ? Keyboard::Left : Keyboard::A;
    const Keyboard::Key teclaDireita = (jogador == 1) ? Keyboard::Right : Keyboard::D;

    if (esta_no_chao && Keyboard::isKeyPressed(teclaPular)) {
            // velocidade.y -= 900.;
            velocidade.y -= 10*Tilemap::getTileSize();
            esta_no_chao = false;
    }

    if (Keyboard::isKeyPressed(teclaEsquerda)){
        dv.x -= aceleracaoHorizontal;
        if(!recuando){
            recuando = true;
            getFig()->scale(-1,1);
        }
    }

    if (Keyboard::isKeyPressed(teclaDireita)){
        dv.x += aceleracaoHorizontal;
        if(recuando){
            recuando = false;
            getFig()->scale(-1,1);
        }
    }

    velocidade += dv;

    if(esta_no_chao)
    {
        velocidade.x *= 0.85f; // Desaceleração no chão, atrito

        if (std::abs(velocidade.x) < 1.f)
                velocidade.x = 0.f;

        if (std::abs(velocidade.x) > velocidadeMaximaChao) {

            if(velocidade.x > 0)
                velocidade.x = velocidadeMaximaChao;
            else
                velocidade.x = -velocidadeMaximaChao;
        }
    }
    else
    {
        velocidade.x *= 0.98f; // Desaceleração no ar, arrasto

        if (std::abs(velocidade.x) < 1.f)
                velocidade.x = 0.f;

        if (std::abs(velocidade.x) > velocidadeMaximaAr) {
            if(velocidade.x > 0)
                    velocidade.x = velocidadeMaximaAr;
            else
                velocidade.x = -velocidadeMaximaAr;
        }
    }

    Entidade::mover(velocidade*dt);
    //std::cout << velocidade.x << "\t" << velocidade.y << "\t"<< std::endl;
}

void CMD::Entidades::Personagens::Jogador::esmagar(Personagens::Inimigo* pIn) {
    const int danoDoJog = 3;
    for (int i = 0; i < danoDoJog; ++i) {
        pIn->operator--();
        operator++();//temporario
    }
}

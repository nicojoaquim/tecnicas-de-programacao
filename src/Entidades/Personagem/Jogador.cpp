#include "Jogador.h"

#include "Inimigo.h"
#include "../../Gerenciador/Tempo.h"
#include "../../Gerenciador/Grafico.h"

#include <SFML/Window/Keyboard.hpp>
#include <cmath> // std::abs e trigonométricas

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
    recuando(false)
{
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
    recuando(false)
{
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
    float dx = pIn->getX() - getX();
    float dy = pIn->getY() - getY();
    float interx = std::abs(dx) - (getLargura()/2 + pIn->getLargura()/2) ;
    float intery = std::abs(dy) - (getAltura()/2 + pIn->getAltura()/2);

    if(interx < 0.0f && intery < 0.0f)
    {
        if (interx > intery) {
        if (dx > 0)
            getFig()->setPosition(getX()+interx,getY());
        else
            getFig()->setPosition(getX()-interx,getY());
    }
    else {
        if(dy>0)
            getFig()->setPosition(getX(),getY()+intery);
        else
            getFig()->setPosition(getX(),getY()-intery);
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

void CMD::Entidades::Personagens::Jogador::mover() {
    sf::Vector2f dv(0, 0);
    float dt = Gerenciador::Tempo::getSegundos();
    const Keyboard::Key teclaPular = jogador == 1 ? Keyboard::Up : Keyboard::W;
    const Keyboard::Key teclaEsquerda = jogador == 1 ? Keyboard::Left : Keyboard::A;
    const Keyboard::Key teclaDireita = jogador == 1 ? Keyboard::Right : Keyboard::D;
    if (esta_no_chao && Keyboard::isKeyPressed(teclaPular)) {
            velocidade.y -= 600.;
            esta_no_chao = false;
        }

        if (Keyboard::isKeyPressed(teclaEsquerda)){
            dv.x -= 800.;
            if(!recuando){
                recuando = true;
                getFig()->setScale(-1,1);
            }
        }
        if (Keyboard::isKeyPressed(teclaDireita)){
            dv.x += 800.;
            if(recuando){
                recuando = false;
                getFig()->setScale(1,1);
            }
        }
        velocidade += dv;
        if(esta_no_chao){
            velocidade.x *= 0.85f;

            if (std::abs(velocidade.x) > 400.f) {

                if(velocidade.x > 0)
                    velocidade.x = 400.f;
                else
                    velocidade.x = -400.f;
                }

                if (std::abs(velocidade.x) < 1.f)
                        velocidade.x = 0.f;
        }
        else {
            velocidade.x *= 0.98f;

            if (std::abs(velocidade.x) > 500.f) {
                if(velocidade.x > 0)
                        velocidade.x = 500.f;
                else
                    velocidade.x = -500.f;

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

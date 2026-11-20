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
    nome(texto, pGG->getFonte(), 20)
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
    /*
    float dx = std::abs(pIn->getX() - this->getX());
    float dy = std::abs(pIn->getY() - this->getY());
    float interx = dx - (this->getLargura()/2 + pIn->getLargura()/2) ;
    float intery = dy - (this->getAltura()/2 + pIn->getAltura()/2);

    if(interx < 0.0f && intery < 0.0f)
    {
        if(interx > intery){
            if(dx > 0)
                this->getFig()->move({-1.0f,0.0f});
            else
                this->getFig()->move({1.0f,0.0f});
            }
        else {
            if(dy>0)
                this->getFig()->move({0.0f,-1.0f});
            else
                this->getFig()->move({0.0f,1.0f});
        }
        return true;
    }*/
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
    if (esta_no_chao && Keyboard::isKeyPressed(Keyboard::Up)) {
            velocidade.y -= 600.;
            esta_no_chao = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            dv.x -= 800.;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            dv.x += 800.;
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

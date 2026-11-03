#include "Jogador.h"
#include "Inimigo.h"
#include <SFML/Window/Keyboard.hpp>

using sf::Keyboard;
using sf::Vector2f;
using std::cerr;
using std::endl;

Jogador::Jogador():Personagem(),pontos(0)
{
}

Jogador::~Jogador()
{
}
//baseado na colisão de Hilze Vonck
bool Jogador::colidir(Inimigo* pIn){
    if (pIn == NULL) {
        cerr << "Inimigo nulo" << endl;
        return false;
    }

    float dx = pIn->getFig()->getPosition().x- getFig()->getPosition().x;
    float dy = pIn->getFig()->getPosition().y- getFig()->getPosition().y;
    float interx = abs(dx)-(getFig()->getGlobalBounds().width/2 + pIn->getFig()->getGlobalBounds().width/2) ;
    float intery = abs(dy)-(getFig()->getGlobalBounds().height/2 + pIn->getFig()->getGlobalBounds().height/2);
    if(interx < 0.0f && intery < 0.0f){
        if(interx > intery){
            if(dx > 0)
                getFig()->move({-1.0f,0.0f});
            else
                getFig()->move({1.0f,0.0f});
            }
        else {
            if(dy>0)
                getFig()->move({0.0f,-1.0f});
            else
                getFig()->move({0.0f,1.0f});
        }
        return true;
    }
    return false;
}

void Jogador::executar(){

}
void Jogador::salvar(){

}

void Jogador::mover(){
    Vector2f movimento = {0, 0}; // Vector2<float>

    if (Keyboard::isKeyPressed(Keyboard::Up))
        movimento.y -= 1;
    if (Keyboard::isKeyPressed(Keyboard::Down))
        movimento.y += 1;
    if (Keyboard::isKeyPressed(Keyboard::Left))
        movimento.x -= 1;
    if (Keyboard::isKeyPressed(Keyboard::Right))
        movimento.x += 1;

    if (movimento.x != 0 && movimento.y != 0)
        movimento *= (float) 0.7071067811865475244; // 1/sqrt(2)

    pFig->move(movimento);
}

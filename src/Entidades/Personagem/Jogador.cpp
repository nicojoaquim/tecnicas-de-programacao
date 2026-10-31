#include "Jogador.h"

#include <SFML/Window/Keyboard.hpp>
using sf::Keyboard;
using sf::Vector2f;

Jogador::Jogador():Personagem(),pontos(0)
{
}

Jogador::~Jogador()
{
}
bool Jogador::colidir(Inimigo* pIn){
    if (pIn == NULL) {
        cerr << "Inimigo nulo" << endl;
        return false;
    }
    else return false;
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

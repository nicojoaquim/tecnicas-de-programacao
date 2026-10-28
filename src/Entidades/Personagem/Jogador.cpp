#include "Jogador.h"

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
    else ;
}
void Jogador::executar(){

}
void Jogador::salvar(){

}
void Jogador::mover(){
    if(Keyboard::isKeyPressed(Keyboard::Up))
        pFig->move(0,-2);
    if(Keyboard::isKeyPressed(Keyboard::Left))
        pFig->move(-2,0);
    if(Keyboard::isKeyPressed(Keyboard::Right))
        pFig->move(2,0);
}

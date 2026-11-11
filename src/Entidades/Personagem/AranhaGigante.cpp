#include "AranhaGigante.h"
#include "../../Gerenciador/Grafico.h"

using sf::Vector2f;
using sf::Vector2u;
using sf::Keyboard;

AranhaGigante::AranhaGigante():Inimigo(),raio(1),indoParaFrente(1){

}

AranhaGigante::~AranhaGigante(){

}
void AranhaGigante::executar(){

}
void AranhaGigante::salvar(){
    salvarDataBuffer();
}
void AranhaGigante::mover(){
    float movimento = 0; // Vector2<float>
    Vector2u  janela = pGG->getJanela().getSize();

    if (indoParaFrente){
        movimento+= 0.5;
        if(pFig->getGlobalBounds().left + pFig->getGlobalBounds().width> janela.x )
            indoParaFrente=0;
    }
    else{
        movimento -= 0.5;
        if(pFig->getGlobalBounds().left <0 )
            indoParaFrente=1;
    }

    if (movimento != 0)
        movimento *= (float) 0.7071067811865475244; // 1/sqrt(2)

    pFig->move(movimento,0);
}
void AranhaGigante::danificar(Jogador* pJog){

}

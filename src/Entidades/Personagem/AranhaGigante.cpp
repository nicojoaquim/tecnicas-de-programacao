#include "AranhaGigante.h"
#include "../../Gerenciador/Grafico.h"

using sf::Vector2f;
using sf::Vector2u;
using sf::Keyboard;

CMD::Entidades::Personagens::AranhaGigante::AranhaGigante():
    Inimigo(),
    raio(true),
    indoParaFrente(true)
{
    sf::Sprite* pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexAranhaGigante());
    atribuirSprite(pSprite);
    getFig()->scale(4, 4);
}

CMD::Entidades::Personagens::AranhaGigante::~AranhaGigante() {
    delete getFig();
}

void CMD::Entidades::Personagens::AranhaGigante::executar(){
    gravitar();
    mover();

    if (mudou_direcao) {
        mudou_direcao = false;
        getFig()->scale(-1.f, 1.f);
    }
}

void CMD::Entidades::Personagens::AranhaGigante::salvar(){
    salvarDataBuffer();
}

void CMD::Entidades::Personagens::AranhaGigante::mover(){
    Vector2f movimento = {0.f, 0.f};
    //Vector2u janela = pGG->getTamanhoJanela();

    if (indoParaFrente) {
        movimento.x += 0.5;
        //if(pFig->getGlobalBounds().left + pFig->getGlobalBounds().width > janela.x ) {
        if (getLargura()/2 + getX() >= pGG->getTamanhoJanela().x) {
            indoParaFrente = false;
            mudou_direcao = true;
        }
    }
    else {
        movimento.x -= 0.5;
        //if(pFig->getGlobalBounds().left < 0 ) {
        if (getX() <= 0) {
            indoParaFrente = true;
            mudou_direcao = true;
        }
    }

    //if (movimento != 0)
        //movimento *= (float) 0.7071067811865475244; // 1/sqrt(2)

    Entidade::mover(movimento);
}

void CMD::Entidades::Personagens::AranhaGigante::danificar(Jogador* pJog){

}

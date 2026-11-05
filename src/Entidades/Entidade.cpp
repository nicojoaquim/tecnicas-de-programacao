#include "../organiza.h"
#include "Entidade.h"

using std::cout;
using sf::Vector2f;

Entidade::Entidade(): coord(0.f, 0.f), buffer(cout)
{
}

Entidade::~Entidade()
{
    coord = Vector2f(0.f, 0.f);
}
void Entidade::inicializaPosicao(float x, float y)
{
    if(pFig != NULL)
        pFig->setPosition({x,y});
}

void Entidade::desenhar(sf::Sprite* Fig, float x, float y){
    if(Fig == NULL){
        std::cerr << "Nulidade em desenhar" << std::endl;
        return;
    }
    setFig(Fig);
    centralizar();
    inicializaPosicao(x + Fig->getLocalBounds().width/2.0f,y+ Fig->getLocalBounds().height/2.0f);
}

void Entidade::centralizar(){
    if(pFig == NULL){
        std::cerr << "Nulidade em centraliza" << std::endl;
        return;
    }
    sf::FloatRect cent = pFig->getLocalBounds();
    pFig->setOrigin(cent.width/2.0f,cent.height/2.0f);
}

void Entidade::salvarDataBuffer(){
    buffer << getCoord().x << " " << getCoord().y;
}

void Entidade::setCoord(sf::Vector2f novas_coord)
{
    coord = novas_coord;
    if (pFig != NULL)
        pFig->setPosition(coord); // Para o desenho
}

const sf::Vector2f Entidade::getCoord() const
{
    return coord;
}

void Entidade::setTamanho(sf::Vector2f novo_tam)
{
    tamanho = novo_tam;
}

const sf::Vector2f Entidade::getTamanho() const
{
    return tamanho;
}

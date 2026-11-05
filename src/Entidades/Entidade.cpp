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

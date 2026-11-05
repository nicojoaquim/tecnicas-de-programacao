#pragma once

#include <SFML/Graphics.hpp>
#include "organiza.h"

class GerenciadorGrafico;

class Ente
{
protected:
    int id;
    static GerenciadorGrafico* pGG;
    sf::Sprite* pFig;
    // sf::Sprite possui coordenadas

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    static void setGG(GerenciadorGrafico* pG);

    void desenhar();

    void setId(int idO);
    int getId();

    void setFig(sf::Sprite * Fig);
    sf::Sprite* getFig();
};


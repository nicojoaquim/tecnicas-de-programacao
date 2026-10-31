#pragma once

#include <SFML/Graphics.hpp>
#include "organiza.h"

using sf::Sprite;

class GerenciadorGrafico;

class Ente
{
protected:
    int id;
    static GerenciadorGrafico* pGG;
    Sprite * pFig;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void inicializaPosicao(float x, float y);
    virtual void desenhar();
    static void setGG(GerenciadorGrafico* pG);
    void setFig(Sprite * Fig);
    Sprite* getFig();
    void setId(int idO);
    int getId();
};


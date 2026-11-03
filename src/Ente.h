#pragma once

#include <SFML/Graphics.hpp>
#include "organiza.h"

class GerenciadorGrafico;

class Ente
{
protected:
    int id;
    static GerenciadorGrafico* pGG;
    sf::Sprite * pFig;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void inicializaPosicao(float x, float y);
    void desenhar(sf::Sprite* Fig,float x, float y);
    void centralizar(sf::Sprite* Fig);
    static void setGG(GerenciadorGrafico* pG);
    void setFig(sf::Sprite * Fig);
    sf::Sprite* getFig();
    void setId(int idO);
    int getId();
};


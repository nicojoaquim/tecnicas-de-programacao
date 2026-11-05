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
    // sf::Sprite possui coordenadas também, mas são geridas pela coord em Entidade

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    static void setGG(GerenciadorGrafico* pG);

    void setId(int idO);
    int getId();

    void setFig(sf::Sprite * Fig);
    sf::Sprite* getFig();

    // Mudar/mover esses métodos para Entidade
    void inicializaPosicao(float x, float y);
    void desenhar(sf::Sprite* Fig,float x, float y);
    void centralizar(sf::Sprite* Fig);
};


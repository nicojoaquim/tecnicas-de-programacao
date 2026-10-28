#pragma once

// #include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Janela.h"

#include <vector>

using sf::Window;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::RenderWindow;

using std::vector;

class Ente;

class GerenciadorGrafico
{
private:
    RenderWindow janela;
    //vector<Ente*> graficos;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    void desenharEnte(Ente* pE);
    bool aberto();
    void renderiza();
    void limpar();
    void executar();
};

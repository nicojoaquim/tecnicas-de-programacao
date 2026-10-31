#pragma once

// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
#include "Janela.h"
#include <vector>

#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
#define GATO "assets/imagens/blanche100x100.png"

using std::vector;
// using sf::Window;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::RenderWindow;

class Ente;
class GerenciadorGrafico
{
private:
    RenderWindow janela;
    //Janela janela;
    Event evento; // Atributo usado em executar()
    //vector<Ente*> graficos;


public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    void desenharEnte(Ente* pE);
    const bool aberto() const;
    void renderizar();
    void limpar();
    void executar();

    void temporario_desenharTexto(sf::Text text) { janela.draw(text); }
};

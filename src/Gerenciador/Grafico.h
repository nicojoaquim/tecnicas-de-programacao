#pragma once

// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
//#include "Janela.h"

#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
#define GATO "assets/imagens/blanche100x100.png"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> // inclui sf::RenderWindow
#include <SFML/System.hpp> // inclui sf::String



// Temporários
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

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    void desenharEnte(Ente* pE);
    void desenharTexto(const sf::Text & texto);
    const bool aberto() const;
    void renderizar();
    void limpar();
    void executar();
    bool eventoM(sf::Event& evento);
    void fechar();
    RenderWindow & getJanela() { return janela; }
};

#pragma once

// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
#include "Janela.h"

#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
#define GATO "assets/imagens/blanche100x100.png"

class Ente;
class GerenciadorGrafico
{
private:
    sf::RenderWindow janela;
    //Janela janela;
    // Event evento; // Atributo usado em executar()

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    void desenharEnte(Ente* pE);
    void desenharTexto(const sf::Text & texto);
    const bool aberto() const;
    void renderizar();
    void limpar();
    // void executar();
    bool getEvento(sf::Event& evento);
    void fechar();

    sf::RenderWindow & getJanela() { return janela; }
};

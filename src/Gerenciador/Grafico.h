#pragma once

#include <SFML/Graphics.hpp> // inclui sf::RenderWindow

#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
#define GATO "assets/imagens/blanche100x100.png"

class Ente;
class GerenciadorGrafico
{
private:
    sf::RenderWindow janela;
    sf::Image imgJogador;
    sf::Image imgChao;
    sf::Image imgInimigos;
    // sf::Image img...;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    void desenharEnte(Ente* pE);
    void desenharTexto(const sf::Text & texto);
    const bool aberto() const;
    void renderizar();
    void limpar();
    bool getEvento(sf::Event& evento);
    void fechar();

    sf::RenderWindow & getJanela() { return janela; }

    const sf::Image getImgJogador() const;
    const sf::Image getImgChao() const;
    const sf::Image getImgInimigos() const;

private:
    void inicializarImagens();
};

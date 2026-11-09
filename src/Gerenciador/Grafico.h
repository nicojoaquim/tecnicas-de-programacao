#pragma once

#include <SFML/Graphics.hpp> // inclui sf::RenderWindow

#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
#define GATO "assets/imagens/blanche100x100.png"
#define CHAO "assets/imagens/Retro-Lines-16x16/Environment.png"

class Ente;
class GerenciadorGrafico
{
private:
    sf::RenderWindow janela;

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

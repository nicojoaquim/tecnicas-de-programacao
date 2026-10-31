#pragma once

#include "Gerenciador/Grafico.h"
#include "Entidades/Personagem/Jogador.h"

class Jogo
{
private:
    GerenciadorGrafico GG;
    Jogador primeiro;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text text;
    sf::Text text2;

public:
    Jogo();
    ~Jogo();
    void executar(); // Loop de execução: preparar, desenar, repetir
    void preparar(); // Mudanças no jogo que ocorrem a cada frame
    void desenhar(); // Desenho do novo frame
};

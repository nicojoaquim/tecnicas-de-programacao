#pragma once

#include "Gerenciador/Grafico.h"
#include "Entidades/Personagem/Jogador.h"
#include "Entidades/Personagem/InimigoMedio.h"
#include "Gerenciador/Colisoes.h"//temporario
#include "Menu.h"

class Jogo
{
private:
    GerenciadorGrafico GG;
    GerenciadorColisoes GC;//temporario
    Jogador primeiro;
    Menu menu;
    InimigoMedio teste;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    sf::Font font;
    sf::Text text;
    sf::Text text2;

public:
    Jogo();
    ~Jogo();
    void executar(); // Loop de execução: preparar, desenar, repetir
    void telaInicial(sf::Event* evento);
    void preparar(); // Mudanças no jogo que ocorrem a cada frame
    void desenhar(); // Desenho do novo frame
};

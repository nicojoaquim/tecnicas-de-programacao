#pragma once

#include "Gerenciador/Grafico.h"
#include "Entidades/Personagem/Jogador.h"
#include "Entidades/Personagem/InimigoMedio.h"
#include "Gerenciador/Colisoes.h"//temporario
#include "Menu.h"

// Usado para telaAtual
enum Tela {
    MENU, FASE1, FASE2
};

class Jogo
{
private:
    Tela telaAtual;
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
    void executar();
    void telaInicial(); // Loop de execução do menu
    void telaTeste(); // Loop de execução de teste: preparar, desenar
    void preparar(); // Mudanças no jogo que ocorrem a cada frame
    void desenhar(); // Desenho do novo frame
};

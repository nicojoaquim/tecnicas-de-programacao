#pragma once

#include "Gerenciador/Grafico.h"
#include "Entidades/Personagem/Jogador.h"
#include "Entidades/Personagem/AranhaGigante.h"
#include "Gerenciador/Colisoes.h"//temporario
#include "Entidades/Chao.h"//temporario
#include "Menu.h"
#include "Fases/Fase.h"
// #include "Fases/Fase.h"

// Usado para telaAtual
enum Tela {
    MENU, FASE1, FASE2
};

class Jogo
{
private:
    Tela telaAtual;
    GerenciadorGrafico GG;
    GerenciadorColisoes GC; // TEMPORÁRIO
    Jogador jogador1;

    Menu menu;
    Chao chao;
//    AranhaGigante teste;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    sf::Font font;
    sf::Text text;
    sf::Text text2;

public:
    Jogo();
    ~Jogo();
    void executar();
    void telaInicial(); // Loop de execução do menu
    // void preparar(); // Mudanças no jogo que ocorrem a cada frame
    // void desenhar(); // Desenho do novo frame
};

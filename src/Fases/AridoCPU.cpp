#include "AridoCPU.h"
#include "../Tilemap.h"

#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
using sf::Event;
using sf::Keyboard;

CMD::Fases::AridoCPU::AridoCPU():
    Fase(),
    maxBruxas(4),
    maxCogumelos(5)
{
    criarAmbiente();
    criarInimigos();
    criarObst();
    tilemap.incluir(JOG1, {0, 0});
    tilemap.incluir(JOG2, {0, 0});
}

CMD::Fases::AridoCPU::~AridoCPU()
{}

void CMD::Fases::AridoCPU::criarInimigos()
{
    // sf::Vector2u espacos_possiveis_aranha [5] = {}
    sf::Vector2u espacos_possiveis_bruxa [5] = {
        {23, 5}, {15, 5}, {31, 5}, {19, 6}, {27, 6}
    };

    int numAranha = rand() % maxAranhasGigantes;
    int numBruxa = rand() % maxBruxas;
    if(numAranha < 3)
        numAranha = 3;
    if(numBruxa < 3)
        numBruxa = 3;

    for(int i = 0; i < numAranha; i++)
        criarAranhaGigante({tilemap.getLargura()/2-i, 0});

    for(int i = 0; i < numBruxa; i++) {
        criarBruxa(espacos_possiveis_bruxa[i%5]);
    }
}

void CMD::Fases::AridoCPU::criarObst()
{
    sf::Vector2u espacos_possiveis_cogumelo [5] = {
        {19, 22}, {28, 22}, {23, 18}, {24, 10}, {23, 23}
    };

    int numPlataforma = rand() % maxPlataformas;
    int numCogumelo = rand() % maxCogumelos;
    if(numPlataforma < 3)
        numPlataforma = 3;
    if(numCogumelo < 3)
        numCogumelo = 3;

    for(int i = 0; i < numPlataforma; i++)
        criarPlataforma({tilemap.getLargura()/2 - i, tilemap.getAltura()/5 + i});

    // Pega uma posição aleatória entre as possíveis
    // e marca ela para não usar novamente
    for(int i = 0; i < numCogumelo && i < 5; i++) {
        int p;
        do {
            p = rand() % 5;
        } while (espacos_possiveis_cogumelo[p].x == 0);
        criarCogumelo(espacos_possiveis_cogumelo[p]);
        espacos_possiveis_cogumelo[p].x = 0;
    }
}

void CMD::Fases::AridoCPU::criarAmbiente()
{
    // Aqui que define o chão da fase
    unsigned int i, j;
    // Paredes, chão e teto
    for (i = 14; i <= 33; i++)
        tilemap.incluir(CPU0, {i, 23});
    for (i = 14; i <= 33; i++)
        tilemap.incluir(CPU1, {i, 2});
    for (i = 3; i <= 22; i++)
        tilemap.incluir(CPU2, {34, i});
    for (i = 3; i <= 22; i++)
        tilemap.incluir(CPU3, {13, i});
    // Plataformas
    for (i = 11; i <= 19; i += 4) {
        tilemap.incluir(CPU0, {22, i});
        tilemap.incluir(CPU0, {23, i});
        tilemap.incluir(CPU0, {24, i});
        tilemap.incluir(CPU0, {25, i});
    }

    // Decoração da fase AridoCPU
    // Cantos
    tilemap.incluir(CPU8, {13, 2});
    tilemap.incluir(CPU9, {34, 2});
    tilemap.incluir(CPU10, {13, 23});
    tilemap.incluir(CPU11, {34, 23});
    tilemap.incluir(CPU11, {12, 1});
    tilemap.incluir(CPU10, {35, 1});
    tilemap.incluir(CPU9, {12, 24});
    tilemap.incluir(CPU8, {35, 24});
    // Externo de cima
    tilemap.incluir(CPU4, {12, 0});
    tilemap.incluir(CPU5, {35, 0});
    for (i = 13; i <= 34; i++)
        tilemap.incluir(CPU0, {i, 0});
    // Externo da esquerda
    tilemap.incluir(CPU4, {11, 1});
    tilemap.incluir(CPU6, {11, 24});
    for (i = 2; i <= 23; i++)
        tilemap.incluir(CPU2, {11, i});
    // Externo da direita
    tilemap.incluir(CPU5, {36, 1});
    tilemap.incluir(CPU7, {36, 24});
    for (i = 2; i <= 23; i++)
        tilemap.incluir(CPU3, {36, i});
    // Externo de baixo
    tilemap.incluir(CPU6, {12, 25});
    tilemap.incluir(CPU7, {35, 25});
    tilemap.incluir(CPU1, {13, 25});
    for (i = 14; i <= 32; i += 3) { // 14, 17, 20, 23, 26, 29, 32
        tilemap.incluir(CPU9, {i, 25});
        tilemap.incluir(CPU6, {i, 26});
        tilemap.incluir(CPU7, {i+1, 26});
        tilemap.incluir(CPU8, {i+1, 25});
        tilemap.incluir(CPU1, {i+2, 25});
    }
    // Fios
    for (j = 3; j <= 21; j += 3) {
        for (i = 0; i <= 9; i++) {
            tilemap.incluir(CPU0, {i, j});
            tilemap.incluir(CPU1, {i, j+1});
        }
        for (i = 36; i <= 47; i++) {
            tilemap.incluir(CPU0, {i, j});
            tilemap.incluir(CPU1, {i, j+1});
        }
    }
    for (j = 3; j <= 21; j += 6) {
        for (i = 0; i <= 36; i += 36) {
            tilemap.incluir(VAZIO, {i+1, j+1});
            tilemap.incluir(VAZIO, {i+4, j});
            tilemap.incluir(VAZIO, {i+7, j+1});
        }
        for (i = 0; i <= 36; i += 36) {
            tilemap.incluir(VAZIO, {i+2, j+3});
            tilemap.incluir(VAZIO, {i+5, j+4});
            tilemap.incluir(VAZIO, {i+8, j+3});
        }
    }
}

void CMD::Fases::AridoCPU::executar() {
    Event evento;
    bool jogando;

    criarCenario(); // Passa pelo tilemap carregando chão, teleportando jog etc

    jogando = true;
    while (jogando) {
        // Marca o relógio para 0 e armazena
        // tempo decorrido desde o último frame
        pGT->reiniciarRelogio();

        // Verificar eventos ocorridos desde o último frame
        while (pGG->getEvento(evento)) {
            if (evento.type == Event::Closed) {
                pGG->fechar();
                jogando = false;
                return;
            }
            else if (evento.type == Event::KeyPressed
                     && evento.key.code == Keyboard::Escape) {
                // num_vida = 0;
                jogando = false;
                return;
            }
        }

        pGG->limpar();
        executarEntidades();
        GC.executar();
        removerInimigosMortos();
        if (GC.todosJogadoresMortos() || GC.todosInimigosMortos())
            return;
        desenhar();
        desenharVidas();
        pGG->renderizar();
    }
}

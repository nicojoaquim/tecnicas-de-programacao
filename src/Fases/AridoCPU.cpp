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
    int numAranha = rand()%maxAranhasGigantes;
    int numBruxa = rand()%maxBruxas;
    if(numAranha < 3)
        numAranha = 3;
    if(numBruxa < 3)
        numBruxa = 3;
    for(int i = 0; i < numAranha; i++)
        criarAranhaGigante({tilemap.getLargura()/2-i, 0});
    for(int i = 0; i < numBruxa; i++)
        criarBruxa({tilemap.getLargura()/2 + i, tilemap.getAltura()/2 - 1});
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


void CMD::Fases::AridoCPU::criarObst()
{
    int numPlataforma = rand()%maxPlataformas;
    int numCogumelo = rand()%maxCogumelos;
    if(numPlataforma < 3)
        numPlataforma = 3;
    if(numCogumelo < 3)
        numCogumelo = 3;
    for(int i = 0; i < numPlataforma; i++)
        criarPlataforma({tilemap.getLargura()/2 - i, tilemap.getAltura()/5 + i});
    for(int i = 0; i < numCogumelo; i++)
        criarCogumelo({tilemap.getLargura()/3 + static_cast<unsigned int>(i), tilemap.getAltura()/2 - 1});
}

void CMD::Fases::AridoCPU::criarAmbiente()
{
    // Aqui que definie o chão da fase
    sf::Vector2u pos = {0, 0};
    //const float tam_tile = tilemap.getTileSize();
    pos.y = tilemap.getAltura() - 5;
    while (pos.x < tilemap.getLargura()) {
        tilemap.incluir(CPU0, pos);
        pos.x++;
    }
}

#include "MemoriaRAM.h"
#include "../Tilemap.h"

#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
using sf::Event;
using sf::Keyboard;

CMD::Fases::MemoriaRam::MemoriaRam():
    Fase(),
    maxOlhosVoadores(5),
    maxAboboras(5)
{
    criarAmbiente();
    criarInimigos();
    criarObst();
    tilemap.incluir(JOG1, {2, 20});
    tilemap.incluir(JOG2, {5, 21});

    criarCenario();
}

CMD::Fases::MemoriaRam::~MemoriaRam() {
    // lista_ents.percorrer(); // Não da pra usar? Percorrer só passa por todos os elem.
}

void CMD::Fases::MemoriaRam::criarInimigos() {
    int numAranha = rand()%maxAranhasGigantes;
    int numOlho = rand()%maxOlhosVoadores;
    if(numAranha < 3)
        numAranha = 3;
    for(int i = 0; i < numAranha; i++)
        criarAranhaGigante({
            static_cast<unsigned int>(i),
            tilemap.getAltura()-1
        });
    if(numOlho < 3)
        numOlho = 3;
    for(int i = 0; i < numOlho; i++) {
        const unsigned int x = tilemap.getLargura()/2 > static_cast<unsigned int>(i)
            ? tilemap.getLargura()/2 - static_cast<unsigned int>(i)
            : 0;
        criarOlhoVoador({
            x,
            tilemap.getAltura()/3 + static_cast<unsigned int>(i)
        });
    }
}

void CMD::Fases::MemoriaRam::criarObst() {
    int numAbobora = rand()%maxAboboras;
    int numPlataforma = rand()%maxPlataformas;
    if(numPlataforma < 3)
        numPlataforma = 3;
    for(int i = 0; i < numPlataforma; i++) {
        const unsigned int x = tilemap.getLargura()/2 > static_cast<unsigned int>(i)
            ? tilemap.getLargura()/2 - static_cast<unsigned int>(i)
            : 0;
        criarPlataforma({x,tilemap.getAltura()/4 + static_cast<unsigned int>(i)
        });
    }
    if(numAbobora < 3)
        numAbobora = 3;
    for(int i = 0; i < numAbobora; i++)
        criarAbobora({tilemap.getLargura()/3 + static_cast<unsigned int>(i), tilemap.getAltura()/3});
}

void CMD::Fases::MemoriaRam::executar() {
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


void CMD::Fases::MemoriaRam::criarAmbiente()
{
    unsigned int i;
    // Chão da fase
    for (i = 22; i <= 26; i++)
        tilemap.incluir(RAM2, {0, i});
    tilemap.incluir(RAM4, {0, 21});
    tilemap.incluir(RAM0, {1, 21});
    tilemap.incluir(RAM0, {2, 21});
    tilemap.incluir(RAM5, {3, 21});
    tilemap.incluir(RAM10, {3, 22});
    for (i = 4; i <= 7; i++)
        tilemap.incluir(RAM0, {i, 22});
    tilemap.incluir(RAM5, {8, 22});
    tilemap.incluir(RAM3, {8, 23});
    tilemap.incluir(RAM10, {8, 24});
    for (i = 9; i <= 13; i++)
        tilemap.incluir(RAM0, {i, 24});
    tilemap.incluir(RAM11, {14, 24});
    tilemap.incluir(RAM2, {14, 23});
    tilemap.incluir(RAM2, {14, 22});
    tilemap.incluir(RAM4, {14, 21});
    for (i = 15; i <= 17; i++)
        tilemap.incluir(RAM0, {i, 21});
    tilemap.incluir(RAM5, {18, 21});
    tilemap.incluir(RAM3, {18, 22});
    tilemap.incluir(RAM10, {18, 23});
    for (i = 19; i <= 21; i++)
        tilemap.incluir(RAM0, {i, 23});
    tilemap.incluir(RAM11, {22, 23});
    tilemap.incluir(RAM4, {22, 22});
    tilemap.incluir(RAM0, {23, 22});
    tilemap.incluir(RAM0, {24, 22});
    tilemap.incluir(RAM5, {25, 22});
    tilemap.incluir(RAM10, {25, 23});
    for (i = 26; i <= 28; i++)
        tilemap.incluir(RAM0, {i, 23});
    tilemap.incluir(RAM11, {29, 23});
    tilemap.incluir(RAM2, {29, 22});
    tilemap.incluir(RAM4, {29, 21});
    for (i = 30; i <= 32; i++)
        tilemap.incluir(RAM0, {i, 21});
    tilemap.incluir(RAM5, {33, 21});
    tilemap.incluir(RAM3, {33, 22});
    tilemap.incluir(RAM3, {33, 23});
    tilemap.incluir(RAM10, {33, 24});
    for (i = 34; i <= 38; i++)
        tilemap.incluir(RAM0, {i, 24});
    tilemap.incluir(RAM11, {39, 24});
    tilemap.incluir(RAM2, {39, 23});
    tilemap.incluir(RAM4, {39, 22});
    for (i = 40; i <= 43; i++)
        tilemap.incluir(RAM0, {i, 22});
    tilemap.incluir(RAM11, {44, 22});
    tilemap.incluir(RAM4, {44, 21});
    tilemap.incluir(RAM0, {45, 21});
    tilemap.incluir(RAM0, {46, 21});
    tilemap.incluir(RAM5, {47, 21});
    for (i = 22; i <= 26; i++)
        tilemap.incluir(RAM3, {47, i});

    /* // Borda para debug
    const unsigned int altura = tilemap.getAltura();
    const unsigned int largura = tilemap.getLargura();
    sf::Vector2u p;
    for (p = {0, 0}; p.x < largura; p.x++) {
        tilemap.incluir(INVALIDO, p);
    }
    for (p = {0, altura-1}; p.x < largura; p.x++) {
        tilemap.incluir(INVALIDO, p);
    }
    for (p = {0, 0}; p.y < altura; p.y++) {
        tilemap.incluir(INVALIDO, p);
    }
    for (p = {largura-1, 0}; p.y < altura; p.y++) {
        tilemap.incluir(INVALIDO, p);
    }
    */
}
/*void CMD::Fases::MemoriaRam::executar()
{

}*/

#include "MemoriaRAM.h"
#include "../Tilemap.h"

// #include <vector>
// using std::vector;

CMD::Fases::MemoriaRam::MemoriaRam():
    Fase(),
    maxOlhosVoadores(5),
    maxAboboras(5)
{
    //lista_ents.limpar();
    criarAmbiente();
    criarInimigos();
    criarObst();

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

void CMD::Fases::MemoriaRam::criarAmbiente()
{
    // Aqui que definie o chão da fase
    sf::Vector2u pos = {0, 0};
    //const float tam_tile = tilemap.getTileSize();
    pos.y = tilemap.getAltura() - 1;
    while (pos.x < tilemap.getLargura()) {
        tilemap.incluir(RAM0, pos);
        pos.x++;
    }
}
/*void CMD::Fases::MemoriaRam::executar()
{
    
}*/
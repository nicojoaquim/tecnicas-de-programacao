#include "MemoriaRAM.h"
#include "../Tilemap.h"

#include <vector>
using std::vector;

CMD::Fases::MemoriaRam::MemoriaRam():
    Fase(),
    maxOlhosVoadores(1),
    maxCogumelos(4)
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
    criarAranhaGigante({0, 0});
}

void CMD::Fases::MemoriaRam::criarObst() {}

void CMD::Fases::MemoriaRam::criarAmbiente()
{
    // AQUI QUE DIZ O QUE INICIA NO TILEMAP
    sf::Vector2u pos = {0, 0};
    //const float tam_tile = tilemap.getTileSize();
    pos.y = tilemap.getAltura() - 1;
    while (pos.x < tilemap.getLargura()) {
        tilemap.incluir(RAM0, pos);
        pos.x++;
    }
}

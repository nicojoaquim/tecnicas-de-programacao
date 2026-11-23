#include "AridoCPU.h"

CMD::Fases::AridoCPU::AridoCPU():
    Fase(),
    maxBruxas(1),
    maxAboboras(4)
{
    criarAmbiente();
    criarInimigos();
    criarObst();
}

CMD::Fases::AridoCPU::~AridoCPU()
{}

//void CMD::Fases::AridoCPU::executar()
//{
//    Fase::executar();
//}

void CMD::Fases::AridoCPU::criarInimigos()
{
    criarAranhaGigante({0, 0});
    criarBruxa({tilemap.getLargura()/2, tilemap.getAltura()/2});
}

void CMD::Fases::AridoCPU::criarObst()
{
    criarPlataforma({tilemap.getLargura()/2, tilemap.getAltura()/5});
    criarCogumelo({tilemap.getLargura()/3, tilemap.getAltura()/2});
}

void CMD::Fases::AridoCPU::criarAmbiente()
{
    // Aqui que definie o chão da fase
    sf::Vector2u pos = {0, 0};
    //const float tam_tile = tilemap.getTileSize();
    pos.y = tilemap.getAltura() - 5;
    while (pos.x < tilemap.getLargura()) {
        tilemap.incluir(CPU0, pos);
        std::cout << "Criou chão" << std::endl;
        pos.x++;
    }
}

#include "AridoCPU.h"

CMD::Fases::AridoCPU::AridoCPU():
    Fase(),
    maxBruxas(4),
    maxCogumelos(5)
{
    criarAmbiente();
    criarInimigos();
    criarObst();
    criarCenario();
}

CMD::Fases::AridoCPU::~AridoCPU()
{}

//void CMD::Fases::AridoCPU::executar()
//{
//    Fase::executar();
//}

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
    pos.y = tilemap.getAltura() - 1;
    while (pos.x < tilemap.getLargura()) {
        tilemap.incluir(CPU0, pos);
        std::cout << "Criou chão" << std::endl;
        pos.x++;
    }
}

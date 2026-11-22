#include "AridoCPU.h"

CMD::Fases::AridoCPU::AridoCPU():
    Fase(),
    maxBruxas(1),
    maxAboboras(4)
{
    criarInimigos();
    criarObst();
}

CMD::Fases::AridoCPU::~AridoCPU()
{}

void CMD::Fases::AridoCPU::executar()
{
    Fase::executar();
}

void CMD::Fases::AridoCPU::criarInimigos()
{
    criarAranhaGigante();
    criarBruxa();
}

void CMD::Fases::AridoCPU::criarObst()
{
    criarPlataforma();
    criarCogumelo();
}

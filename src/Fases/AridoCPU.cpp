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
    ;
}

void CMD::Fases::AridoCPU::criarInimigos()
{}

void CMD::Fases::AridoCPU::criarObst()
{}

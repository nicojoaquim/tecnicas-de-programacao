#include "MemoriaRAM.h"

CMD::Fases::MemoriaRam::MemoriaRam():
    Fase(),
    maxOlhosVoadores(1),
    maxCogumelos(4)
{
    //lista_ents.limpar();
    criarInimigos();
    criarObst();
}

CMD::Fases::MemoriaRam::~MemoriaRam()
{
    // lista_ents.percorrer(); // Não da pra usar? Percorrer só passa por todos os elem.

}
/*
void MemoriaRam::executar()
{
    ;
}
*//*
void MemoriaRam::gravitar()
{
    ;
}
*//*
void MemoriaRam::mover()
{
    ;
}
*//*
void MemoriaRam::desenhar()
{
    ;
}
*/
void CMD::Fases::MemoriaRam::criarInimigos()
{
    criarAranhaGigante();
}

void CMD::Fases::MemoriaRam::criarObst()
{}

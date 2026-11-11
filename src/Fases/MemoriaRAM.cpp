#include "MemoriaRAM.h"

MemoriaRam::MemoriaRam():
    Fase(),
    maxOlhosVoadores(1)
{
    //lista_ents.limpar();
    criarInimigos();
    criarObst();
}

MemoriaRam::~MemoriaRam()
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
void MemoriaRam::criarInimigos()
{
    criarAranhaGigante();
}

void MemoriaRam::criarObst()
{}

#pragma once

#include "Gerenciador/Grafico.h"
#include "Entidades/Personagem/Jogador.h"

class Jogo
{
private:
    Gerenciador_Grafico GG;
    Jogador primeiro;

public:
    Jogo();
    ~Jogo();
    void executar();
    // void tick();
};

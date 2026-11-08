#pragma once

#include "Personagem.h"

class Inimigo;

class Jogador:public Personagem
{
protected:
    int pontos;
public:
    Jogador();
    ~Jogador();
    bool colidir(Inimigo* pIn);
    void executar();
    void salvar();
    void mover();
};

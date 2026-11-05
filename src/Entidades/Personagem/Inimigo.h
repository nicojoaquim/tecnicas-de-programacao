#pragma once

#include"Personagem.h"

class Jogador;

class Inimigo:public Personagem {
protected:
    int agresividade;

public:
    Inimigo();
    virtual ~Inimigo();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
    virtual void danificar(Jogador*pJog) = 0;
};

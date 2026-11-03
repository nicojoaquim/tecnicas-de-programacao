#pragma once

#include "../Entidade.h"

class Personagem:public Entidade
{
protected:
    int num_vida;
public:
    Personagem();
    virtual ~Personagem();
    void salvarDataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
};


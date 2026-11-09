#pragma once

#include "../Entidade.h"

class Personagem:public Entidade
{
protected:
    int num_vida;
    sf::Vector2f velocidade;

public:
    Personagem();
    virtual ~Personagem();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
};


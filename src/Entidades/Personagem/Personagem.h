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
    void gravitar(const float dt);
    void setVy(float y);
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
    const int getNumVida() const { return num_vida; } // TEMP para Fase em Jogo
};


#pragma once

#include "../Entidade.h"

class Personagem:public Entidade
{
protected:
    int num_vida;
    sf::Vector2f v;
    static sf::Clock relogio;

public:
    Personagem();
    virtual ~Personagem();
    void gravitar(const float dt);
    void setVy(float y);
    static void restartRelogio();
    static const float  getSegundos();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
};


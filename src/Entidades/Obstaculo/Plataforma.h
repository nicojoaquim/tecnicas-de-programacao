#pragma once

#include "Obstaculo.h"

class Plataforma : public Obstaculo
{
private:
    int altura;
public:
    Plataforma();
    ~Plataforma();
    void executar();
    void obstaculizar(Jogador* p);
    void gravitar(const float dt);
    void mover() {}
};

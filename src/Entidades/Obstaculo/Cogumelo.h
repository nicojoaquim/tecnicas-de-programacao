#pragma once

#include "Obstaculo.h"

class Cogumelo : public Obstaculo
{
private:
    int largura;

public:
    Cogumelo();
    ~Cogumelo();
    void executar();
    void obstaculizar(Jogador* p);
    void gravitar(const float dt);
    void mover() {}
};

#pragma once
#include"../Entidade.h"
class Jogador;
class Obstaculo: public Entidade{
    protected:
    bool danoso;
    public:
    Obstaculo();
    virtual ~Obstaculo();
    void salvarDataBuffer();
    virtual void gravidar() = 0;
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void Obstacularizar(Jogador* pJog) = 0;
};
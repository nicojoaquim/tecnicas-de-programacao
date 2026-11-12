#pragma once

#include "Inimigo.h"

//mudar nome da classe depois
class AranhaGigante:public Inimigo{
private:
    float raio;
    bool indoParaFrente;
public:
    AranhaGigante();
    ~AranhaGigante();
    void executar();
    void salvar();
    void mover();
    void danificar(Jogador*pJog);
};

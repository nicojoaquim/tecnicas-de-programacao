#pragma once

#include"Inimigo.h"

//mudar nome da classe depois
class Bruxa:public Inimigo{
private:
    short int forca;
public:
    Bruxa();
    ~Bruxa();
    void executar();
    void salvar();
    void mover();
    void danificar(Jogador*pJog);
};

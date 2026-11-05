#pragma once

#include"Inimigo.h"

//mudar nome da classe depois
class InimigoMedio:public Inimigo{
private:
    int tamanho;
public:
    InimigoMedio();
    ~InimigoMedio();
    void executar();
    void salvar();
    void mover();
    void danificar(Jogador*pJog);
};

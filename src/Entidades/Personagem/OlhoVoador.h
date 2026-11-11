#pragma once

#include"Inimigo.h"

//mudar nome da classe depois
class OlhoVoador:public Inimigo{
private:
    int tamanho;
public:
    OlhoVoador();
    ~OlhoVoador();
    void executar();
    void salvar();
    void mover();
    void danificar(Jogador*pJog);
};

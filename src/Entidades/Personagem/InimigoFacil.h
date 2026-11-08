#pragma once

#include"Inimigo.h"

//mudar nome da classe depois
class InimigoFacil:public Inimigo{
private:
    float raio;
    bool indoParaFrente;
public:
    InimigoFacil();
    ~InimigoFacil();
    void executar();
    void salvar();
    void mover();
    void danificar(Jogador*pJog);
};

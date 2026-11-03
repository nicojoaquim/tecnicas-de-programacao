#pragma once
#include"Inimigo.h"
//mudar nome da classe depois
class Chefao:public Inimigo{
private:
short int forca;
public:
Chefao();
~Chefao();
void executar();
void salvar();
void mover();
void danificar(Jogador*pJog);
};
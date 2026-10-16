#pragma once
#include "Ente.h"

class Jogo;

class Menu: public Ente
{
private:
    Jogo* pJog;
    ;

public:
    Menu();
    ~Menu();
    void executar();
    ;
};

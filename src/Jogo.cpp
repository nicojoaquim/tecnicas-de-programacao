#include "Jogo.h"

Jogo::Jogo()
{
    Jogo::executar();
}

Jogo::~Jogo()
{}

#include <iostream>
void Jogo::executar()
{
    std::cout << "Oi" << std::endl;
}

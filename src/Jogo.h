#pragma once

// #include "Gerenciador/Gráfico.h"
#include "Gerenciador/Janela.h"
// #include "Gerenciador/Tempo.h"

// #include "Personagem/Jogador.h"
#include "Gerenciador\Grafico.h"
#include"Entidades/Personagem/Jogador.h"
class Jogo
{
private:
    Gerenciador_Grafico GG;
    Jogador primeiro;

public:
    Jogo();
    ~Jogo();
    void executar();
    
};

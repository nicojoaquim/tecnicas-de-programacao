#pragma once

#include "Fase.h"

#include "../Entidades/Personagem/AranhaGigante.h"
#include "../Entidades/Personagem/OlhoVoador.h"
#include "../Entidades/Obstaculo/Cogumelo.h"

class MemoriaRam : public Fase
{
private:
    const int maxOlhosVoadores;
    void criarInimigos();
    void criarObst();

public:
    MemoriaRam();
    ~MemoriaRam();
    // void desenhar();
    // void gravitar();
    // void mover();
};

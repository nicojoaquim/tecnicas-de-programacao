#pragma once

#include "Fase.h"

// #include "../Entidades/Personagem/AranhaGigante.h"
// #include "../Entidades/Personagem/OlhoVoador.h"
// #include "../Entidades/Obstaculo/Cogumelo.h"

namespace CMD
{
    namespace Fases {
        class MemoriaRam : public Fase
        {
        private:
            const int maxOlhosVoadores;
            const int maxCogumelos;
            void criarAmbiente();
            void criarInimigos();
            void criarObst();
        public:
            MemoriaRam();
            ~MemoriaRam();
            // void desenhar();
            // void gravitar();
            // void mover();
            // void executar();
        };
    }
}

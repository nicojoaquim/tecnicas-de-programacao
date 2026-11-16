#pragma once

#include "Fase.h"

#include "../Entidades/Personagem/Bruxa.h"
#include "../Entidades/Projetil.h"
namespace trabalhoJogo{
    namespace Fases{
        class AridoCPU : public Fase
        {
        private:
            const int maxBruxas;

        public:
            AridoCPU();
            ~AridoCPU();
            void executar();
            void criarInimigos();
            void criarObst();
        };
    }
}
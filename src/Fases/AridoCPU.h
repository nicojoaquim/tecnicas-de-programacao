#pragma once

#include "Fase.h"

namespace CMD
{
    namespace Fases {
        class AridoCPU : public Fase
        {
        private:
            const int maxBruxas;
            const int maxCogumelos;
            void criarAmbiente();
            void criarInimigos();
            void criarObst();
        public:
            AridoCPU();
            ~AridoCPU();
            void executar();
        };
    }
}

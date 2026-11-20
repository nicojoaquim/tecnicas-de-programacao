#pragma once

#include "Fase.h"

#include "../Entidades/Personagem/Bruxa.h"
#include "../Entidades/Projetil.h"
namespace CMD{
    namespace Fases{
        class AridoCPU : public Fase
        {
        private:
            const int maxBruxas;
            const int maxAboboras;
        public:
            AridoCPU();
            ~AridoCPU();
            void executar();
            void criarInimigos();
            void criarObst();
        };
    }
}

#pragma once

#include "Fase.h"

namespace CMD
{
    namespace Fases {
        class MemoriaRam : public Fase
        {
        private:
            const int maxOlhosVoadores;
            const int maxAboboras;
            void criarAmbiente();
            void criarInimigos();
            void criarObst();
        public:
            MemoriaRam();
            ~MemoriaRam();
            void executar();
        };
    }
}

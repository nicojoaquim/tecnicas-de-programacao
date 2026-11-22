#pragma once

#include "Obstaculo.h"
namespace CMD{
    namespace Entidades{
        namespace Obstaculos{
            class Cogumelo : public Obstaculo
            {
            private:
                short int densidade;

            public:
                Cogumelo();
                ~Cogumelo();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void salvar();
            };
        }
    }
}

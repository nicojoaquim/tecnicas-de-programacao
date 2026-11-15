#pragma once

#include "Obstaculo.h"
namespace trabalhoJogo{
    namespace Entidades{
        namespace Obstaculos{
            class Cogumelo : public Obstaculo
            {
            private:
                int largura;

            public:
                Cogumelo();
                ~Cogumelo();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void gravitar(const float dt);
                void mover() {}
            };
        }
    }
}
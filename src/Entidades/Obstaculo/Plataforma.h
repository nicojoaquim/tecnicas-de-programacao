#pragma once

#include "Obstaculo.h"
namespace CMD{
    namespace Entidades{
        namespace Obstaculos{
            class Plataforma : public Obstaculo
            {
            private:
                int altura;
            public:
                Plataforma();
                ~Plataforma();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void gravitar(const float dt);
                void mover() {}
            };
        }
    }
}

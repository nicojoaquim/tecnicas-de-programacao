#pragma once

#include"../Entidade.h"
namespace trabalhoJogo{
    namespace Entidades{
        namespace Personagens{
        class Jogador;
        }
        namespace Obstaculos{
            class Obstaculo: public Entidade
            {
            protected:
                bool danoso;
            public:
                Obstaculo();
                virtual ~Obstaculo();
                void salvarDataBuffer();
                // virtual void gravitar(const float dt) = 0;
                // virtual void mover() = 0;
                virtual void executar() = 0;
                virtual void salvar() = 0;
                virtual void obstaculizar(Personagens::Jogador* pJog) = 0;
            };
        }
    }
}
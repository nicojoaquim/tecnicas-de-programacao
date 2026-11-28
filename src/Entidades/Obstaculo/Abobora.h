#pragma once

#include"Obstaculo.h"

namespace CMD {
    namespace Entidades {
        namespace Obstaculos {
            class Abobora : public Obstaculo
            {
            private:
                int largura;
                float tempoCor;

            public:
                Abobora();
                ~Abobora();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void salvar();
                void carregar();
                void acao();
            };
        }
    }
}

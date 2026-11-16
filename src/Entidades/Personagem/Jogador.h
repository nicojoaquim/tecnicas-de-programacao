#pragma once

#include "Personagem.h"
namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class Inimigo;
            class Jogador:public Personagem
            {
            protected:
                int pontos;
            public:
                Jogador();
                ~Jogador();
                bool colidir(Personagens::Inimigo* pIn);
                void executar();
                void salvar();
                void mover();
            };
        }
    }
}

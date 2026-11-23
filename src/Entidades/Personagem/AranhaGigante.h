#pragma once

#include "Inimigo.h"


namespace CMD {
    namespace Entidades {
        namespace Obstaculos {
            class Plataforma;
        }
        namespace Personagens {
            class AranhaGigante: public Inimigo
            {
            private:
                float raio;
                bool indoParaFrente;
                bool mudou_direcao;
                Obstaculos::Plataforma* plataformaSuporte;//ponteiro para plataforma de suporte da aranha, a aranha é o inimigo que pode ficar em cima, já que os outros dois voam
            public:
                AranhaGigante();
                ~AranhaGigante();
                void executar();
                void salvar();
                void mover();
                void danificar(Jogador*pJog);
                bool colidirPlataforma(Obstaculos::Plataforma* plataforma);
                void perderPlataforma();
            private:
                void morder(Jogador* pJog);
            };
        }
    }
}

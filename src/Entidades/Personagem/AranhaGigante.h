#pragma once

#include "Inimigo.h"


namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class AranhaGigante:public Inimigo{
            private:
                float raio;
                bool indoParaFrente;
            public:
                AranhaGigante();
                ~AranhaGigante();
                void executar();
                void salvar();
                void mover();
                void danificar(Jogador*pJog);
            };
        }
    }
}

#pragma once

#include"Inimigo.h"
namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class OlhoVoador:public Inimigo{
            private:
                int tamanho;
            public:
                OlhoVoador();
                ~OlhoVoador();
                void executar();
                void salvar();
                void mover();
                void danificar(Jogador*pJog);
            };
        }
    }
}

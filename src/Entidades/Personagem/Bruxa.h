#pragma once

#include"Inimigo.h"
namespace trabalhoJogo{
    namespace Entidades{
        namespace Personagens{
            class Bruxa:public Inimigo{
            private:
                short int forca;
            public:
                Bruxa();
                ~Bruxa();
                void executar();
                void salvar();
                void mover();
                void danificar(Jogador*pJog);
            };
        }
    }
}
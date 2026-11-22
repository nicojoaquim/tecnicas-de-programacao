#pragma once

#include"Inimigo.h"
namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class OlhoVoador:public Inimigo{
            private:
                int tamanho;
                bool indoParaFrente;
                bool mudou_direcao;
                float tempoSen;
                float yBase;
                bool yBaseInicializada;
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

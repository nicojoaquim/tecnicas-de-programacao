#pragma once

#include "../Entidade.h"

namespace CMD
{
    namespace Entidades{
        namespace Personagens{
            class Personagem:public Entidade
            {
            protected:
                int num_vida;
                bool esta_no_chao;

            public:
                Personagem();
                virtual ~Personagem();
                void setEstaNoChao(bool no_chao);
                //void setVy(float y);
                //void gravitar();
                virtual void executar() = 0;
                virtual void salvar() = 0;
                virtual void mover() = 0; // Sobrecarga do método de Entidade: mover(Vector2f)
                const int getNumVida() const ;// TEMP para Fase em Jogo
                void operator--();
            };
        }
    }
}

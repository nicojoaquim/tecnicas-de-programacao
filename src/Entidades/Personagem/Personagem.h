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
                sf::Vector2f velocidade;
                bool esta_no_chao;

            public:
                Personagem();
                virtual ~Personagem();
                void gravitar();
                void setVy(float y);
                void setEstaNoChao(bool no_chao);
                virtual void executar() = 0;
                virtual void salvar() = 0;
                virtual void mover() = 0; // Sobrecarga do método de Entidade: mover(Vector2f)
                const int getNumVida() const { return num_vida; } // TEMP para Fase em Jogo
            };
        }
    }
}

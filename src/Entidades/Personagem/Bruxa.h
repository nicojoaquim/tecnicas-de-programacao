#pragma once

#include"Inimigo.h"
        namespace CMD{
            namespace Entidades{
                class Projetil;
            }
        }
namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class Bruxa:public Inimigo{
            private:
                short int forca;
                float tempoParada;
                float tempoParaMover;
                sf::Vector2f posicaoAlvo;//ponto do espaço no qual ela vai
                bool estaSeMovendo;
                float tempoDisparo;
                const float intervaloDisparo;
                Projetil* projetil;
                Jogador* jogador1;
                Jogador* jogador2;
            public:
                Bruxa();
                ~Bruxa();
                void executar();
                void salvar();
                void carregar();
                void mover();
                void danificar(Jogador*pJog);
                void criarProjetil();
                void setProjetil(Projetil* pProjetil);
                void setAlvos(Jogador* pJog1, Jogador* pJog2);
            private:
                void tapaMagico(Jogador*pJog);
            };
        }
    }
}

#pragma once

#include "Personagem.h"

#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>

namespace CMD
{
    namespace Entidades {
        namespace Personagens {
            class Inimigo;
            class Jogador:public Personagem
            {
            protected:
                int pontos;
                int jogador;
                sf::String nome;
            public:
                Jogador();
                Jogador(int jogadorX, sf::String str);
                ~Jogador();
                bool colidir(Personagens::Inimigo* pIn);
                void executar();
                void salvar();
                void mover(); // Sobrecarga do método de Entidade: mover(Vector2f)
                //void setNome(sf::String str);
                void carregarSprite();
            };
        }
    }
}

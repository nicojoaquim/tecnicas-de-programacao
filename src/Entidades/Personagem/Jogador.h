#pragma once

#include "Personagem.h"

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
                sf::Text nome;
                bool recuando;
            public:
                Jogador();
                Jogador(int jogadorX, sf::String texto = "");
                Jogador(int jogadorX, const sf::Font& fonte, sf::String texto = "");
                ~Jogador();
                bool colidir(Personagens::Inimigo* pIn);
                void executar();
                void salvar();
                void mover(); // Sobrecarga do método de Entidade: mover(Vector2f)
            };
        }
    }
}

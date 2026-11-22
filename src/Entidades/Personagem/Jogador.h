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
                bool pegajoso;
                float tempoInvulneravel;
            public:
                Jogador();
                Jogador(int jogadorX, sf::String texto = "");
                Jogador(int jogadorX, const sf::Font& fonte, sf::String texto = "");
                ~Jogador();
                bool colidir(Personagens::Inimigo* pIn);
                void executar();
                void salvar();
                void mover(); // Sobrecarga do método de Entidade: mover(Vector2f)
                void setPegajoso(bool estado);
                void receberDanoDeInimigo(int dano,
                    const sf::Vector2f posicaoInimigo);
                void reiniciar();
                int & operator++();
            private:
                void esmagar(Personagens::Inimigo* pIn);
            };
        }
    }
}

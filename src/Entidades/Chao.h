#pragma once

#include "Entidade.h"

#include "../Tilemap.h"
#include <SFML/Graphics/Texture.hpp>

namespace CMD {
    namespace Entidades {
        namespace Personagens {
            class Personagem;
        }
        namespace Obstaculos {
            class Obstaculo;
        }
        class Projetil;

        class Chao : public Entidade
        {
        private:
            const Tile tipo;
            float largura;
            float altura;

        public:
            Chao(Tile t);
            ~Chao();
            // void inicializaChao(sf::Sprite * chao);
            // void tamanhoChao();
            void executar();
            void salvar();
            void impedirQuedaPSG(Personagens::Personagem* pP);
            void impedirQuedaOBS(Obstaculos::Obstaculo* pO);
            void impedirQuedaPJT(Projetil* pPj);
        private:
            const sf::Texture& getTex() const; // Pega a textura correta de acordo com atributo tipo
        };
    }
}

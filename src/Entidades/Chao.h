#pragma once

#include "Entidade.h"

#include "../Tilemap.h"
#include <SFML/Graphics/Texture.hpp>

namespace CMD {
    namespace Entidades {
        class Chao : public Entidade
        {
        private:
            const Tile tipo;
            float largura;
            float altura;
        public:
            Chao(Tile t);
            ~Chao();
            void inicializaChao(sf::Sprite * chao);
            void tamanhoChao();
            void executar();
            void salvar();
        private:
            const sf::Texture& getTex() const; // Pega a textura correta de acordo com atributo tipo
        };
    }
}

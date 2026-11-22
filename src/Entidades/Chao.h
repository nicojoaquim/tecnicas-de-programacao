#pragma once

#include "Entidade.h"

// Chão será formado por várias
namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class Personagem;
        }
        class Chao : public Entidade
        {
        private:
            float largura;
            float altura;
        public:
            Chao();
            ~Chao();
            void inicializaChao(sf::Sprite * chao);
            void tamanhoChao();
            void executar();
            void salvar();
            void impedirQuedaPSG(Personagens::Personagem* pP);
        };
    }
}

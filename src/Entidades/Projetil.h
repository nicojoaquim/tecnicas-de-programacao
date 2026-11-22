#pragma once

#include "Entidade.h"
namespace CMD{
    namespace Entidades{
        namespace Personagens{
            class Jogador;}
        class Projetil : public Entidade
        {
        protected:
            bool ativo;// se foi disparado

        public:
            Projetil();
            ~Projetil();
            void mover();
            //const sf::Vector2f getV() const;
            //void setV(const sf::Vector2f v);
            //void gravitar();
            void executar();
            void salvar();
            void disparar(const sf::Vector2f origem, const sf::Vector2f alvo);
            void desativar();
            bool estaAtivo() const;
            void perfurar(Personagens::Jogador* pJ);
        };
    }
}

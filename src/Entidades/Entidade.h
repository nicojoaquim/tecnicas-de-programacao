#pragma once

#include "../Ente.h"
#include "../Coordenadas.h"
#include <SFML/System/Vector2.hpp>

// Usado para testar se é um vetor válido
#define INEXISTENTE (Vector2f(-99999999.f,-99999999.f))

namespace CMD
{
    namespace Entidades {
        class Entidade: public Ente
        {
        protected:
            std::ostream & buffer;
            bool dinamico;

        public:
            Entidade();
            virtual ~Entidade();

            virtual void executar() = 0;
            virtual void salvar() = 0;

            void atribuirSprite(sf::Sprite* Fig);

            const sf::Vector2f getPosicao() const;
            void setPosicao(const sf::Vector2f posicao);
            const float getX() const;
            const float getY() const;

            const sf::Vector2f getTamanho() const;
            const float getLargura() const;
            const float getAltura() const;

            void setDinamico(bool dim);
            const bool getDinamico() const;

            //sf::Vector2f& operator+=(sf::Vector2f& movimento);
            void mover(sf::Vector2f movimento);

        protected:
            virtual void salvarDataBuffer();
        };
    }
}

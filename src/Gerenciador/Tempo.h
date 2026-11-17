#pragma once

#include <SFML/System.hpp>

// Tempo é uma classe singleton

namespace CMD
{
    namespace Gerenciador
    {
        class Tempo
        {
        public:
            static Tempo* getInstancia();
            static void reiniciarRelogio();
            static const float getSegundos();

        private:
            Tempo();
            ~Tempo();
            static Tempo* pInstancia;
            static sf::Clock relogio;
            static sf::Time tempo;
        };
    }
}

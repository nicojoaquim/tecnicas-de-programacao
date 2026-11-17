#pragma once

#include <SFML/System/Vector2.hpp>

// #include "organiza.h"
#include <vector>

namespace CMD
{
    class Coordenadas
    {
    private:
//        sf::Vector2f coordenadas;
        std::vector<std::vector<int>> coordenadas;

    public:
        Coordenadas();
        ~Coordenadas();
//        const float getX() const { return coordenadas.x; }
//        const float getY() const { return coordenadas.y; }
    };
}

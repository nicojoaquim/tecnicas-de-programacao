#pragma once

#include <SFML/System.hpp>

class Tempo
{
private:
    static sf::Clock relogio;

public:
    Tempo();
    ~Tempo();
    static void restartRelogio();
    static const float getSegundos();
};

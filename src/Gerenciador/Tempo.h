#pragma once

// #include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

class Tempo
{
public:
    Tempo();
    ~Tempo();
    const sf::Time deltaTempo(); // Mesma coisa que chamar delta = relogio.restart();

private:
    sf::Time tempo;
    sf::Clock relogio;
};

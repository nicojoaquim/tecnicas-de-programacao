#pragma once

// #include <SFML/System.hpp>
#include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp> // inclui sf::RenderWindow
using sf::Window;
using sf::VideoMode;
using sf::Event;
#include <iostream>

class Janela
{
private:
    Window janela;

public:
    Janela();
    ~Janela();
};


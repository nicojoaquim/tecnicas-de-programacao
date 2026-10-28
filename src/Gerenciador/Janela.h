#pragma once

#include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp> // inclui sf::RenderWindow
#include <SFML/System/String.hpp>

#include <iostream>

using sf::String;
using sf::Window;
using sf::VideoMode;
using sf::Event;

class Janela
{
private:
    const String nome_janela;
    Window janela;

public:
    Janela();
    ~Janela();
    const bool aberta() const;
    // const sf::Event evento();
};


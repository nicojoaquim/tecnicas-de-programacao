#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> // inclui sf::RenderWindow
#include <SFML/System.hpp> // inclui sf::String

using sf::String;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

// Usado por GerenciadorGrafico
class Janela
{
private:
    RenderWindow janela; // sf::RenderWindow
    String nome; // sf::String

public:
    Janela(const char* nome_janela = "Jogo");
    ~Janela();

    const bool aberta() const;
    // const sf::Event evento();
};


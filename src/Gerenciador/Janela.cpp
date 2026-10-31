#include "Janela.h"
// #include "../organiza.h"

using sf::VideoMode;

Janela::Janela(const char* nome_janela):
    janela(),
    nome(nome_janela)
{
    // Pega as dimensões da tela
    VideoMode mode = VideoMode::getDesktopMode();

    janela.create(mode, nome_janela); // sf::Style::Default
}

Janela::~Janela()
{
    // janela.close();
}

const bool Janela::aberta() const
{
    return janela.isOpen();
}


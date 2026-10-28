#include "Janela.h"

#include "../organiza.h"

Janela::Janela():janela(),nome_janela("Jogo")
{
    VideoMode mode = VideoMode::getDesktopMode();

    cout << mode.width << " por " << mode.height << endl;
    cout << "tem " << mode.bitsPerPixel << " bits por pixel" << endl;

    janela.create(mode, nome_janela); // sf::Style::Default
    // No Jogo
    // while (janela.isOpen())
    // {
    //     // check all the window's events that were triggered since the last iteration of the loop
    //     Event evento;
    //     while (janela.pollEvent(evento))
    //     {
    //         // "close requested" event: we close the window
    //         if (evento.type == Event::Closed)
    //             janela.close();
    //     }
    // }
}

Janela::~Janela()
{
    // janela.close();
}

const bool Janela::aberta() const
{
    return janela.isOpen();
}

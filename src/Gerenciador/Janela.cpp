#include "Janela.h"
#include "../organiza.h"
// Por algum motivo, não dá para implementar aqui:

Janela::Janela():janela(VideoMode(900,600),"Jogo")
{
    VideoMode mode = VideoMode::getDesktopMode();

    cout << mode.width << " por " << mode.height << endl;
    cout << "tem " << mode.bitsPerPixel << " bits por pixel" << endl;
 // apartir daqui foi adaptado do tutorial do SFML 2.6
    while (janela.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            Event evento;
            while (janela.pollEvent(evento))
            {
                // "close requested" event: we close the window
                if (evento.type == Event::Closed)
                    janela.close();
            }
        }
}


Janela::~Janela(){}

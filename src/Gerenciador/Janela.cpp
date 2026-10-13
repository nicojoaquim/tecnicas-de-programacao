#include "Janela.h"

// Por algum motivo, não dá para implementar aqui:
Janela::Janela()
{
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << mode.size.x << " por " << mode.size.y << std::endl;
    std::cout << "tem " << mode.bitsPerPixel << " bits por pixel" << std::endl;
}

Janela::~Janela(){}

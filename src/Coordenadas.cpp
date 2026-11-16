#include "Coordenadas.h"

#include <SFML/Window/VideoMode.hpp>

CMD::Coordenadas::Coordenadas():
    coordenadas()
{
    const auto tela = sf::VideoMode::getDesktopMode();
    coordenadas.resize(tela.height,std::vector<int>(tela.width));
}

CMD::Coordenadas::~Coordenadas() {

}

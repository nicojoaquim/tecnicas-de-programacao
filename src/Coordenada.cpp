#include"Coordenada.h"
Coordenada::Coordenada(): coordenada(){
const auto tela = sf::VideoMode::getDesktopMode();
coordenada.resize(tela.height,std::vector<int>(tela.width));
}
Coordenada::~Coordenada(){
    
}
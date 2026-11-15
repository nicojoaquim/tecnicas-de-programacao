#include"Coordenada.h"
trabalhoJogo::Coordenada::Coordenada(): coordenada(){
const auto tela = sf::VideoMode::getDesktopMode();
coordenada.resize(tela.height,std::vector<int>(tela.width));
}
trabalhoJogo::Coordenada::~Coordenada(){
    
}
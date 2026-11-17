#include "Tempo.h"

using namespace CMD::Gerenciador;

// static, devemos declarar
Tempo* Tempo::pInstancia = NULL;
sf::Clock Tempo::relogio;
sf::Time Tempo::tempo;

Tempo* Tempo::getInstancia() {
    if (pInstancia == NULL)
        pInstancia = new Tempo;
    return pInstancia;
}

Tempo::Tempo() {
}

Tempo::~Tempo() {
}

void Tempo::reiniciarRelogio(){
    tempo = relogio.restart();
}

const float Tempo::getSegundos(){
    return tempo.asSeconds();
}

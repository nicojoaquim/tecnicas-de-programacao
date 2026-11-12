#include "Tempo.h"

// Relógio é static
sf::Clock Tempo::relogio;

Tempo::Tempo() {
}

Tempo::~Tempo() {
}

void Tempo::restartRelogio(){
    relogio.restart();
}

const float Tempo::getSegundos(){
    return relogio.restart().asSeconds();
}

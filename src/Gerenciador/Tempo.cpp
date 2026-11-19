#include "Tempo.h"

using namespace CMD::Gerenciador;

Tempo* Tempo::pInstancia(NULL);
sf::Clock Tempo::relogio;
sf::Time Tempo::tempo(sf::Time::Zero);

Tempo* Tempo::getInstancia() {
    if (pInstancia == NULL)
        pInstancia = new Tempo;
    return pInstancia;
}

Tempo::Tempo() {
}

Tempo::~Tempo() {
}

void Tempo::reiniciarRelogio() {
    tempo = relogio.restart();
}

const float Tempo::getSegundos() {
    return tempo.asSeconds();
}

const sf::Int64 Tempo::getMicrosegundos() {
    return tempo.asMicroseconds();
}

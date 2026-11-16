#include "Tempo.h"

// Relógio é static
sf::Clock CMD::Tempo::relogio;

CMD::Tempo::Tempo() {
}

CMD::Tempo::~Tempo() {
}

void CMD::Tempo::restartRelogio(){
    relogio.restart();
}

const float CMD::Tempo::getSegundos(){
    return relogio.restart().asSeconds();
}

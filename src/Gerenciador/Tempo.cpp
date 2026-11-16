#include "Tempo.h"

// Relógio é static
sf::Clock trabalhoJogo::Tempo::relogio;

trabalhoJogo::Tempo::Tempo() {
}

trabalhoJogo::Tempo::~Tempo() {
}

void trabalhoJogo::Tempo::restartRelogio(){
    relogio.restart();
}

const float trabalhoJogo::Tempo::getSegundos(){
    return relogio.restart().asSeconds();
}

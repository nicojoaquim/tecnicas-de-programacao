#include "Tilemap.h"

#include <iostream>

CMD::Tilemap::Tilemap(int lar, int alt):
    largura(lar),
    altura(alt),
    tile_size(0),
    matriz(largura, std::vector<int>(altura))
{
}

CMD::Tilemap::~Tilemap() {
}

const float CMD::Tilemap::getTileSize() const {
    return tile_size;
}

void CMD::Tilemap::calcularTileSize(sf::Vector2u tam_janela) {
    if (tam_janela.x == 0 || tam_janela.y == 0) {
        std::cerr << "Zero em Tilemap::calcularTileSize" << std::endl;
        return;
    }

    float razao = tam_janela.x / (float)tam_janela.y;

    if (razao > 16.f/9.f)
        tile_size = tam_janela.y / (float)altura;
    else
        tile_size = tam_janela.x / (float)largura;
}

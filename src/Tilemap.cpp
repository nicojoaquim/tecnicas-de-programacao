#include "Tilemap.h"

#include <vector>
#include <iostream>

CMD::Tilemap::Tilemap(unsigned int lar, unsigned int alt):
    largura(lar),
    altura(alt),
    tile_size(0),
    matriz(largura, std::vector<CMD::Tile>(altura)),
    origem({0, 0})
{
}

//CMD::Tilemap::Tilemap(std::vector<std::vector<int>>& m):
//    largura(m.size()),
//    altura(),
//    tile_size(0),
//    matriz(m)
//{
//    if (m.size() > 0)
//        altura = m[0].size();
//}

CMD::Tilemap::~Tilemap() {
}

const unsigned int CMD::Tilemap::getLargura() const {
    return largura;
}

const unsigned int CMD::Tilemap::getAltura() const {
    return altura;
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

    if (razao > 16.f/9.f) {
        tile_size = tam_janela.y / (float)altura;
        origem.x = (tam_janela.x - (tile_size * largura)) / 2.0f;
        origem.y = 0;
    }
    else {
        tile_size = tam_janela.x / (float)largura;
        origem.x = 0;
        origem.y = (tam_janela.y - (tile_size * altura)) / 2.0f;
    }
}

void CMD::Tilemap::incluir(Tile tipo, sf::Vector2u pos) {
    if (pos.x >= largura || pos.y >= altura) {
        std::cerr << "Posição inválida em Tilemap::incluir(): "
                  << pos.x << ", " << pos.y
                  << ", largura: " << largura << ", altura: " << altura
                  << std::endl;
        return;
    }
    matriz[pos.x][pos.y] = tipo;
}

const CMD::Tile CMD::Tilemap::getTile(sf::Vector2u pos) const {
    if (pos.x >= largura || pos.y >= altura) {
        std::cerr << "Posição inválida em Tilemap::get()" << std::endl;
        return VAZIO;
    }
    return matriz[pos.x][pos.y];
}

const sf::Vector2f CMD::Tilemap::getCentroTile(sf::Vector2u pos) const {
    const sf::Vector2f centro((pos.x+0.5f)*getTileSize(), (pos.y+0.5f)*getTileSize());
    return origem+centro;
}
//void CMD::Tilemap::setMatriz(vector<vector<int>>& m) {
//    matriz = m;
//}

//std::vector<std::vector<int>>& CMD::Tilemap::getMatriz() {
//    return matriz;
//}

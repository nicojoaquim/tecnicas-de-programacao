#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

namespace CMD
{
    class Tilemap {
    private:
        const int largura; // n.º de tiles no eixo x
        const int altura; // no eixo y
        float tile_size; // Um único valor pro lado, pois são quadrados
        std::vector<std::vector<int>> matriz; // trocar int por estrutura Coordenadas?

    public:
        Tilemap(int lar = 80, int alt = 45);
        ~Tilemap();
        void executar();
        const float getTileSize() const;
        void calcularTileSize(sf::Vector2u tam_janela);
    };
}

#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

namespace CMD
{
    enum Tile {
        VAZIO = 0,
        JOG1, JOG2,
        ARANHA, OLHO, BRUXA, PROJ, PLAT, ABOBORA, COGUMELO,
        RAM0, RAM1, RAM2, RAM3, RAM4, RAM5, RAM6, RAM7, RAM8, RAM9, RAM10, RAM11,
        CPU0, CPU1, CPU2, CPU3, CPU4, CPU5, CPU6, CPU7, CPU8, CPU9, CPU10, CPU11
    };

    class Tilemap {
    private:
        const unsigned int largura; // n.º de tiles no eixo x
        const unsigned int altura; // no eixo y
        float tile_size; // Um único valor pro lado, pois são quadrados
        std::vector<std::vector<Tile>> matriz; // CMD::Tile é enum
        sf::Vector2f origem;

    public:
        Tilemap(unsigned int lar = 32, unsigned int alt = 18);
        ~Tilemap();
        void executar();
        const unsigned int getLargura() const;
        const unsigned int getAltura() const;
        const float getTileSize() const;
        void calcularTileSize(sf::Vector2u tam_janela);
        void incluir(Tile tipo, sf::Vector2u pos);
        const Tile getTile(sf::Vector2u pos) const;
        const sf::Vector2f getCentroTile(sf::Vector2u pos) const;
        //void setMatriz(std::vector<std::vector<int>>& m);
        //std::vector<std::vector<int>>& getMatriz();
    };
}

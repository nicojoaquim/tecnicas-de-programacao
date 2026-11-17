#include <vector>

/*
namespace CMD
{
    class Tile // Tile poderia ser namespace
    {
    private:
        int tipo;
    public:
        Tile(): tipo(0) {} // 0: void, 1: ... usamos enum{}, #define ou o quê?
        ~Tile();
        void set(int t) { tipo = t; }
        const int get() const { return tipo; }
    };

    class Tilemap
    {
    private:
        const int largura; // n.º de tiles no eixo x
        const int altura; // no eixo y
        const float tile_size; // Um único valor pro lado, pois são quadrados
        std::vector<std::vector<Tile>> matriz; // trocar int por estrutura Coordenadas?

    public:
        Tilemap(int lar = 80, int alt = 45);
        ~Tilemap();
        const float getTileSize() const { return tile_size; }
    };
}
*/

#pragma once

#include"organiza.h"
#include<SFML/Window.hpp>
#include<vector>
namespace trabalhoJogo{
    class Coordenada
    {
    private:
        std::vector<std::vector<int>> coordenada;

    public:
        Coordenada();
        ~Coordenada();
    };
}
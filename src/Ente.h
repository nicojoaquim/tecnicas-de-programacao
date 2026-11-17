#pragma once

#include <SFML/Graphics.hpp>
#include "organiza.h"
namespace CMD{
    namespace Gerenciador{
        class Grafico;
    }
    class Ente
    {
    protected:
        int id;
        static Gerenciador::Grafico* pGG;
        sf::Sprite* pFig;
        // sf::Sprite possui coordenadas

    public:
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;

        static void setGG(Gerenciador::Grafico* pG);

        void desenhar();

        void setId(int idO);
        int getId();

        void setFig(sf::Sprite * Fig);
        sf::Sprite* getFig();
    };
}

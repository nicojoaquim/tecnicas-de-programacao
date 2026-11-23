#pragma once

#include "Ente.h"
#include "organiza.h"

namespace CMD
{
    class Jogo;
    //class Grafico;

    class Menu: public Ente
    {
    private:
        Jogo* pJogo;
        const sf::Font fonte;
        std::vector<const char*> opcoes;
        std::vector<sf::Vector2f> coordes;
        std::vector<sf::Text> texts;
        std::vector<std::size_t> tams;
        sf::Vector2i mousePosi;
        sf::Vector2f mouseCoorde;

    public:
        Menu(Jogo* pJ);
        ~Menu();
        void tratarClique(const sf::Event& evento, bool& ativo);
        void desenha();
        void executar();
        void setMousePosi(sf::Vector2i mou);
        sf::Vector2i getMousePosi();
        void setMouseCoorde(sf::Vector2f mou);
        sf::Vector2f getMouseCoorde();
        void coordenadaMouse();
        bool textoMouse(sf::Text& texto);
    };
}

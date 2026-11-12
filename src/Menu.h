#pragma once
#include "Ente.h"
#include"organiza.h"
//#include "Gerenciador/Janela.h"
class Jogo;
class GerenciadorGrafico;
//baseando no menu do site terminal root
class Menu: public Ente
{
private:
    Jogo* pJog;
    //sf::Text textoM;
    sf::Font fontM;
    std::vector<const char*> opcoes;
    std::vector<sf::Vector2f> coordes;
    std::vector<sf::Text> texts;
    std::vector<std::size_t>tams;
    sf::Vector2i mousePosi;
    sf::Vector2f mouseCoorde;

public:
    Menu();
    ~Menu();
    void tratarEvento(const sf::Event& evento, int& ativo);
    void desenha();
    void executar();
    void setMousePosi(sf::Vector2i mou);
    sf::Vector2i getMousePosi();
    void setMouseCoorde(sf::Vector2f mou);
    sf::Vector2f getMouseCoorde();
    void coordenadaMouse();
    bool textoMouse(sf::Text& texto);
};

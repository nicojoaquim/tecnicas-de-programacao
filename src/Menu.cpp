#include"Menu.h"
#include "Gerenciador/Grafico.h"
#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
Menu::Menu():
    Ente(),
    pJog(NULL),
    //textoM(),
    fontM(),
    opcoes(),
    coordes(),
    texts(),
    tams(),
    mousePosi({0,0}),
    mouseCoorde({0,0})
{
if (!fontM.loadFromFile(FONTE)) {
        std::cerr << "Error loading font: " << FONTE << std::endl;
        exit(1);
    }
    std::cout << "Success to load font" << std::endl;

    /*textoM.setFont(fontM);
    textoM.setString("Jogar");
    textoM.setCharacterSize(100);
    textoM.setPosition({400.0f,400.0f});*/
    opcoes = {"Jogo","Jogar","Rankim"};
    coordes = {{530,-100},{550,250},{550,350}};
    tams = {200,100,100};
    texts.resize(2);
    for(size_t i = 0;i < texts.size();i++){
        texts[i].setFont(fontM);
        texts[i].setOutlineColor(sf::Color::White);
        texts[i].setString(opcoes[i]);
        texts[i].setPosition(coordes[i]);
        texts[i].setCharacterSize(tams[i]);
    }
}
Menu::~Menu(){

}
void Menu::executar(){

}
void Menu::tratarEvento(const sf::Event& evento, int& ativo){
    if(evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left){
        mousePosi = {evento.mouseButton.x,evento.mouseButton.y};
        if(textoMouse(texts[1]))
            ativo = 0;
    }
}
void Menu::desenha(){
    if(pGG == NULL){
        std::cerr << "nulidade do gerenciador granfico no menu" << std::endl;
        return;
    }
    for(unsigned int i = 0; i < texts.size(); i++)
        pGG->desenharTexto(texts[i]);
}
void Menu::setMousePosi(sf::Vector2i mou){
    mousePosi = mou;
}
sf::Vector2i Menu::getMousePosi(){
    return mousePosi;
}
void Menu::setMouseCoorde(sf::Vector2f mou){
    mouseCoorde = mou;
}
sf::Vector2f Menu::getMouseCoorde(){
    return mouseCoorde;
}
void Menu::coordenadaMouse(){
    mousePosi = sf::Mouse::getPosition(pGG->getJanela());
    mouseCoorde = pGG->getJanela().mapPixelToCoords(mousePosi);

}
bool Menu::textoMouse(sf::Text& texto){
    if(texto.getGlobalBounds().contains(pGG->getJanela().mapPixelToCoords(mousePosi)))
        return true;
    return false;
}

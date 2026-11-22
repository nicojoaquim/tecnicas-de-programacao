#include"Menu.h"
#include "Gerenciador/Grafico.h"
#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
CMD::Menu::Menu():
    Ente(),
    pJog(NULL),
    fontM(),
    opcoes(),
    coordes(),
    texts(),
    tams(),
    mousePosi({0,0}),
    mouseCoorde({0,0}),
    numeroJogadores(1),
    faseInicial(1)
{
    if (!fontM.loadFromFile(FONTE)) {
        std::cerr << "Error loading font: " << FONTE << std::endl;
        exit(1);
    }
    std::cout << "Success to load font" << std::endl;

    opcoes = {
        "Caos Magico Digital",
        "- Realidade em Colapso",
        "1 Jogador - Fase 1",
        "1 Jogador - Fase 2",
        "2 Jogadores - Fase 1",
        "2 Jogadores - Fase 2"
    };
    coordes = {
        {155,-90},
        {155,15},
        {450,250},
        {450,350},
        {450,450},
        {450,550}
    };
    tams = {150,125,75,75,75,75};
    texts.resize(opcoes.size());
    for(size_t i = 0;i < texts.size();i++){
        texts[i].setFont(fontM);
        texts[i].setOutlineColor(sf::Color::White);
        texts[i].setString(opcoes[i]);
        texts[i].setPosition(coordes[i]);
        texts[i].setCharacterSize(tams[i]);
    }
}
CMD::Menu::~Menu(){

}
void CMD::Menu::executar(){

}
void CMD::Menu::tratarEvento(const sf::Event& evento, int& ativo){
    if(evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left){
        mousePosi = {evento.mouseButton.x,evento.mouseButton.y};
        if(textoMouse(texts[2])) {
            numeroJogadores = 1;
            faseInicial = 1;
            ativo = 0;
        }
        else if(textoMouse(texts[3])) {
            numeroJogadores = 1;
            faseInicial = 2;
            ativo = 0;
        }
        else if(textoMouse(texts[4])) {
            numeroJogadores = 2;
            faseInicial = 1;
            ativo = 0;
        }
        else if(textoMouse(texts[5])) {
            numeroJogadores = 2;
            faseInicial = 2;
            ativo = 0;
        }
    }
}
void CMD::Menu::desenha(){
    if(pGG == NULL){
        std::cerr << "nulidade do gerenciador granfico no menu" << std::endl;
        return;
    }
    for(unsigned int i = 0; i < texts.size(); i++)
        pGG->desenharTexto(texts[i]);
}
void CMD::Menu::setMousePosi(sf::Vector2i mou){
    mousePosi = mou;
}
sf::Vector2i CMD::Menu::getMousePosi(){
    return mousePosi;
}
void CMD::Menu::setMouseCoorde(sf::Vector2f mou){
    mouseCoorde = mou;
}
sf::Vector2f CMD::Menu::getMouseCoorde(){
    return mouseCoorde;
}
int CMD::Menu::getNumeroJogadores() const{
    return numeroJogadores;
}
int CMD::Menu::getFaseInicial() const{
    return faseInicial;
}
void CMD::Menu::coordenadaMouse(){
    mousePosi = sf::Mouse::getPosition(pGG->getJanela());
    mouseCoorde = pGG->getJanela().mapPixelToCoords(mousePosi);

}
bool CMD::Menu::textoMouse(sf::Text& texto){
    if(texto.getGlobalBounds().contains(pGG->getJanela().mapPixelToCoords(mousePosi)))
        return true;
    return false;
}

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
    numeroJogadores(1)
{
    if (!fontM.loadFromFile(FONTE)) {
        std::cerr << "Error loading font: " << FONTE << std::endl;
        exit(1);
    }
    std::cout << "Success to load font" << std::endl;

    opcoes = {"Caos Magico Digital","- Realidade em Colapso","Um Jogador","Dois Jogadores"};
    coordes = {{155,-90},{155,15},{550,250},{550,350}};
    tams = {150,125,100,100};
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
            ativo = 0;
        }
        else if(textoMouse(texts[3])) {
            numeroJogadores = 2;
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
void CMD::Menu::coordenadaMouse(){
    mousePosi = sf::Mouse::getPosition(pGG->getJanela());
    mouseCoorde = pGG->getJanela().mapPixelToCoords(mousePosi);

}
bool CMD::Menu::textoMouse(sf::Text& texto){
    if(texto.getGlobalBounds().contains(pGG->getJanela().mapPixelToCoords(mousePosi)))
        return true;
    return false;
}

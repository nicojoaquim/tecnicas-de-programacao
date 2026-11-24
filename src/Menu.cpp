#include "Menu.h"

#include "Jogo.h"
#include "Gerenciador/Grafico.h"

using sf::Event;
using sf::Keyboard;

CMD::Menu::Menu(Jogo* pJ):
    Ente(),
    pJogo(pJ),
    fonte(pGG->getFonte()),
    opcoes(),
    coordes(),
    texts(),
    tams(),
    mousePosi({0,0}),
    mouseCoorde({0,0})
{
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
        texts[i].setFont(fonte);
        texts[i].setOutlineColor(sf::Color::White);
        texts[i].setString(opcoes[i]);
        texts[i].setPosition(coordes[i]);
        texts[i].setCharacterSize(tams[i]);
    }
}

CMD::Menu::~Menu(){
}

void CMD::Menu::executar() {
    Event evento;
    bool ativo = true;
    while (ativo)
    {
        pGG->limpar();
        while (pGG->getEvento(evento)) {
            if ((evento.type == Event::Closed)
                || (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape))
            {
                pGG->fechar();
                return;
            }
            if (evento.type == sf::Event::MouseButtonPressed
                && evento.mouseButton.button == sf::Mouse::Left)
            {
                tratarClique(evento, ativo);
            }
        }
        desenha();
        pGG->renderizar();
    }
}

void CMD::Menu::tratarClique(const sf::Event& evento, bool& ativo){
    mousePosi = {evento.mouseButton.x,evento.mouseButton.y};

    if(textoMouse(texts[2])) {
        pJogo->setDoisJogadores(false);
        pJogo->setProximaTela(FASE1);
        ativo = false;
    }
    else if(textoMouse(texts[3])) {
        pJogo->setDoisJogadores(false);
        pJogo->setProximaTela(FASE2);
        ativo = false;
    }
    else if(textoMouse(texts[4])) {
        pJogo->setDoisJogadores(true);
        pJogo->setProximaTela(FASE1);
        ativo = false;
    }
    else if(textoMouse(texts[5])) {
        pJogo->setDoisJogadores(true);
        pJogo->setProximaTela(FASE2);
        ativo = false;
    }
}

void CMD::Menu::desenha(){
    if(pGG == NULL){
        std::cerr << "Nulidade do gerenciador gráfico no menu" << std::endl;
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

void CMD::Menu::coordenadaMouse(){
    mousePosi = sf::Mouse::getPosition(pGG->getJanela());
    mouseCoorde = pGG->getJanela().mapPixelToCoords(mousePosi);
}

bool CMD::Menu::textoMouse(sf::Text& texto){
    return (texto.getGlobalBounds().contains(pGG->getJanela().mapPixelToCoords(mousePosi)));
}

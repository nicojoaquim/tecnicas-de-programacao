#include "Menu.h"

#include "Jogo.h"
#include "Gerenciador/Grafico.h"
#include "Ranking.h"

#include <algorithm>

using sf::Event;
using sf::Keyboard;

CMD::Menu::Menu(Jogo* pJ):
    Ente(),
    pJogo(pJ),
    fonte(pGG->getFonte()),
    opcoes(),
    coordes(),
    texts(),
    rankingTexts(),
    tams(),
    mostrarRanking(false),
    mousePosi({0,0}),
    mouseCoorde({0,0})
{
    opcoes = {
        "Caos Magico Digital",
        "- Realidade em Colapso",
        "1 Jogador - Fase 1",
        "1 Jogador - Fase 2",
        "2 Jogadores - Fase 1",
        "2 Jogadores - Fase 2",
        "Ranking"
    };
    coordes = {
        {155,-100},
        {155,5},
        {450,150},
        {450,250},
        {450,350},
        {450,450},
        {450,550}
    };
    tams = {150,125,75,75,75,75,75};
    texts.resize(opcoes.size());
    for(size_t i = 0;i < texts.size();i++){
        texts[i].setFont(fonte);
        texts[i].setOutlineColor(sf::Color::White);
        texts[i].setFillColor(sf::Color::White);
        texts[i].setString(opcoes[i]);
        texts[i].setCharacterSize(tams[i]);
    }

    const sf::Vector2u tamanho = pGG->getTamanhoJanela();
    const sf::FloatRect titulo = texts[0].getLocalBounds();
    const sf::FloatRect subtitulo = texts[1].getLocalBounds();
    texts[0].setPosition((tamanho.x - titulo.width) / 2.f, tamanho.y * 0.08f);
    texts[1].setPosition((tamanho.x - subtitulo.width) / 2.f, tamanho.y * 0.20f);

    const float larguraOpcao = tamanho.x * 0.30f;
    const float inicioX = (tamanho.x - larguraOpcao) / 2.f;
    for (size_t i = 2; i < texts.size(); ++i)
        texts[i].setPosition(inicioX, tamanho.y * (0.34f + (i - 2) * 0.12f));
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
            if (evento.type == Event::Closed) {
                pGG->fechar();
                return;
            }
            if (evento.type == Event::KeyPressed
                && evento.key.code == Keyboard::Escape) {
                if (mostrarRanking) {
                    mostrarRanking = false;
                    continue;
                }
                pGG->fechar();
                return;
            }
            if (evento.type == Event::KeyPressed) {
                if (mostrarRanking) {
                    if (evento.key.code == Keyboard::Return)
                        mostrarRanking = false;
                    continue;
                }
                if (evento.key.code == Keyboard::Num1
                    || evento.key.code == Keyboard::Numpad1) {
                    pJogo->setDoisJogadores(false);
                    pJogo->setProximaTela(FASE1);
                    ativo = false;
                }
                else if (evento.key.code == Keyboard::Num2
                         || evento.key.code == Keyboard::Numpad2) {
                    pJogo->setDoisJogadores(false);
                    pJogo->setProximaTela(FASE2);
                    ativo = false;
                }
                else if (evento.key.code == Keyboard::Num3
                         || evento.key.code == Keyboard::Numpad3) {
                    pJogo->setDoisJogadores(true);
                    pJogo->setProximaTela(FASE1);
                    ativo = false;
                }
                else if (evento.key.code == Keyboard::Num4
                         || evento.key.code == Keyboard::Numpad4) {
                    pJogo->setDoisJogadores(true);
                    pJogo->setProximaTela(FASE2);
                    ativo = false;
                }
                else if (evento.key.code == Keyboard::Num5
                         || evento.key.code == Keyboard::Numpad5
                         || evento.key.code == Keyboard::R) {
                    carregarTextsRanking();
                    mostrarRanking = true;
                }
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

    if (mostrarRanking)
        return;

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
    else if(textoMouse(texts[6])) {
        carregarTextsRanking();
        mostrarRanking = true;
    }
}

void CMD::Menu::desenha(){
    if(pGG == NULL){
        std::cerr << "Nulidade do gerenciador gráfico no menu" << std::endl;
        return;
    }
    if (mostrarRanking) {
        for (size_t i = 0; i < rankingTexts.size(); ++i)
            pGG->desenharTexto(rankingTexts[i]);
        return;
    }
    for(unsigned int i = 0; i < texts.size(); i++)
        pGG->desenharTexto(texts[i]);
}

void CMD::Menu::carregarTextsRanking() {
    rankingTexts.clear();
    const sf::Vector2u tamanho = pGG->getTamanhoJanela();
    const std::vector<RegistroRanking> registros = carregarRanking();

    sf::Text titulo("RANKING", fonte, 64);
    titulo.setFillColor(sf::Color::White);
    const sf::FloatRect limitesTitulo = titulo.getLocalBounds();
    titulo.setPosition((tamanho.x - limitesTitulo.width) / 2.f,
                       tamanho.y * 0.08f);
    rankingTexts.push_back(titulo);

    const size_t limite = std::min<size_t>(registros.size(), 10);
    for (size_t i = 0; i < limite; ++i) {
        const std::string linha = std::to_string(i + 1) + ". "
            + registros[i].nome + " - "
            + std::to_string(registros[i].pontos) + " pontos";
        sf::Text texto(sf::String::fromUtf8(linha.begin(), linha.end()),
                       fonte,
                       32);
        texto.setFillColor(sf::Color::White);
        const sf::FloatRect limites = texto.getLocalBounds();
        texto.setPosition((tamanho.x - limites.width) / 2.f,
                          tamanho.y * (0.22f + i * 0.065f));
        rankingTexts.push_back(texto);
    }

    if (registros.empty()) {
        sf::Text vazio("Ainda nao ha pontuacoes registradas.", fonte, 32);
        vazio.setFillColor(sf::Color::White);
        const sf::FloatRect limites = vazio.getLocalBounds();
        vazio.setPosition((tamanho.x - limites.width) / 2.f,
                          tamanho.y * 0.42f);
        rankingTexts.push_back(vazio);
    }

    sf::Text voltar("ESC ou ENTER para voltar", fonte, 24);
    voltar.setFillColor(sf::Color::White);
    const sf::FloatRect limitesVoltar = voltar.getLocalBounds();
    voltar.setPosition((tamanho.x - limitesVoltar.width) / 2.f,
                       tamanho.y * 0.91f);
    rankingTexts.push_back(voltar);
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

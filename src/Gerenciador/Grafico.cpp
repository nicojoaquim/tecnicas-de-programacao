#include "Grafico.h"
#include "../Ente.h"

#include "../organiza.h"

using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::RenderWindow;

#define JOGADOR "assets/imagens/Retro-Lines-16x16/Player.png"
#define CHAO "assets/imagens/Retro-Lines-16x16/Environment.png"
#define INIMIGOS "assets/imagens/Retro-Lines-16x16/Enemies.png"

GerenciadorGrafico::GerenciadorGrafico():
    janela(),
    imgJogador(),
    imgChao(),
    imgInimigos()
{
    VideoMode video_mode = VideoMode::getDesktopMode();
    int estilo_janela = sf::Style::Close; // Barra de título e botão de fechar
    janela.create(video_mode, "Jogo", estilo_janela);
    janela.clear(Color::Black);
    janela.display();

    inicializarImagens();
    inicializarTexturas();
}

GerenciadorGrafico::~GerenciadorGrafico(){

}

void GerenciadorGrafico::desenharEnte(Ente *pE)
{
    if (pE == NULL) {
        std::cerr << "Nulidade em GG::desenharEnte" << std::endl;
    }
    else {
        janela.draw(*pE->getFig());
    }
}

void GerenciadorGrafico::desenharTexto(const sf::Text& texto){
    janela.draw(texto);
}

const bool GerenciadorGrafico::aberto() const {
    if(janela.isOpen())
        return true;
    return false;
}

void GerenciadorGrafico::renderizar(){
    janela.display();
}

void GerenciadorGrafico::limpar(){
    janela.clear();
}
/*
void GerenciadorGrafico::executar()
{
    Eent evento;
    // adaptado do tutorial do SFML 2.6
    // para cada evento novo desde a última vez que passou pelo loop
    while (janela.pollEvent(evento))
    {
        // evento de fechar a janela
        if (evento.type == Event::Closed)
            janela.close();
    }
}
*/

bool GerenciadorGrafico::getEvento(sf::Event& evento) {
    return janela.pollEvent(evento);
}

void GerenciadorGrafico::fechar() {
    janela.close();
}

void GerenciadorGrafico::inicializarImagens() {
    if (!imgJogador.loadFromFile(JOGADOR))
        std::cerr << "Falha ao abrir " << JOGADOR << std::endl;

    if (!imgChao.loadFromFile(CHAO))
        std::cerr << "Falha ao abrir " << CHAO << std::endl;

    if (!imgInimigos.loadFromFile(INIMIGOS))
        std::cerr << "Falha ao abrir " << INIMIGOS << std::endl;
}

void GerenciadorGrafico::inicializarTexturas() {
    if (!texAranhaGigante.loadFromImage(getImgInimigos(), sf::IntRect(3, 184, 12, 8))) {
        std::cerr << "Erro ao carregar em GG::inicializarTexturas" << std::endl;
        return;
    }
    texAranhaGigante.setSmooth(false); // Serve para continuar pixelada quando esticada
}

const sf::Image GerenciadorGrafico::getImgJogador() const {
    return imgJogador;
}

const sf::Image GerenciadorGrafico::getImgChao() const {
    return imgChao;
}

const sf::Image GerenciadorGrafico::getImgInimigos() const {
    return imgInimigos;
}

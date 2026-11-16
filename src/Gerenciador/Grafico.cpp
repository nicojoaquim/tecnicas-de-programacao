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


trabalhoJogo::Gerenciador::GerenciadorGrafico::GerenciadorGrafico():
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

trabalhoJogo::Gerenciador::GerenciadorGrafico::~GerenciadorGrafico(){

}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::desenharEnte(Ente *pE)
{
    if (pE == NULL) {
        std::cerr << "Nulidade em GG::desenharEnte" << std::endl;
    }
    else {
        janela.draw(*pE->getFig());
    }
}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::desenharTexto(const sf::Text& texto){
    janela.draw(texto);
}

const bool trabalhoJogo::Gerenciador::GerenciadorGrafico::aberto() const {
    if(janela.isOpen())
        return true;
    return false;
}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::renderizar(){
    janela.display();
}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::limpar(){
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

bool trabalhoJogo::Gerenciador::GerenciadorGrafico::getEvento(sf::Event& evento) {
    return janela.pollEvent(evento);
}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::fechar() {
    janela.close();
}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::inicializarImagens() {
    if (!imgJogador.loadFromFile(JOGADOR))
        std::cerr << "Falha ao abrir " << JOGADOR << std::endl;

    if (!imgChao.loadFromFile(CHAO))
        std::cerr << "Falha ao abrir " << CHAO << std::endl;

    if (!imgInimigos.loadFromFile(INIMIGOS))
        std::cerr << "Falha ao abrir " << INIMIGOS << std::endl;
}

void trabalhoJogo::Gerenciador::GerenciadorGrafico::inicializarTexturas() {
    if (!texAranhaGigante.loadFromImage(getImgInimigos(), sf::IntRect(3, 184, 12, 8))) {
        std::cerr << "Erro ao carregar em GG::inicializarTexturas" << std::endl;
        return;
    }
    texAranhaGigante.setSmooth(false); // Serve para continuar pixelada quando esticada
}

const sf::Image& trabalhoJogo::Gerenciador::GerenciadorGrafico::getImgJogador() const {
    return imgJogador;
}

const sf::Image& trabalhoJogo::Gerenciador::GerenciadorGrafico::getImgChao() const {
    return imgChao;
}

const sf::Image& trabalhoJogo::Gerenciador::GerenciadorGrafico::getImgInimigos() const {
    return imgInimigos;
}

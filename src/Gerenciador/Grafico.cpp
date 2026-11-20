#include "Grafico.h"
#include "../Ente.h"

#include "../organiza.h"

using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::RenderWindow;

#define JOGADOR "assets/imagens/Retro-Lines-16x16/Player.png"
#define AMBIENTE "assets/imagens/Retro-Lines-16x16/Environment.png"
#define INIMIGOS "assets/imagens/Retro-Lines-16x16/Enemies.png"


CMD::Gerenciador::Grafico::Grafico():
    janela(),
    imgJogador(),
    imgChao(),
    imgInimigos()
{
    VideoMode video_mode = VideoMode::getDesktopMode();
    //int estilo_janela = sf::Style::Close; // Barra de título e botão de fechar
    int estilo_janela = sf::Style::Default;
    janela.create(video_mode, "Jogo", estilo_janela);
    janela.clear(Color::Black);
    janela.display();

    inicializarImagens();
    inicializarTexturas();
}

CMD::Gerenciador::Grafico::~Grafico(){

}

void CMD::Gerenciador::Grafico::desenharEnte(Ente *pE)
{
    if (pE == NULL) {
        std::cerr << "Nulidade em GG::desenharEnte" << std::endl;
    }
    else {
        janela.draw(*pE->getFig());
    }
}

void CMD::Gerenciador::Grafico::desenharTexto(const sf::Text& texto){
    janela.draw(texto);
}

const bool CMD::Gerenciador::Grafico::aberto() const {
    if(janela.isOpen())
        return true;
    return false;
}

void CMD::Gerenciador::Grafico::renderizar(){
    janela.display();
}

void CMD::Gerenciador::Grafico::limpar(){
    janela.clear();
}
/*
void Grafico::executar()
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

bool CMD::Gerenciador::Grafico::getEvento(sf::Event& evento) {
    return janela.pollEvent(evento);
}

void CMD::Gerenciador::Grafico::fechar() {
    janela.close();
}

const sf::Image& CMD::Gerenciador::Grafico::getImg() const {
    return imgs;
}

const sf::Vector2u CMD::Gerenciador::Grafico::getTamanhoJanela() const {
    return janela.getSize();
}

sf::RenderWindow& CMD::Gerenciador::Grafico::getJanela() {
    return janela;
}

// ==========================================
// inicializar imagem e texturas

void CMD::Gerenciador::Grafico::inicializarImagens() {
    try {
        bool sucesso = img.
    }
    if (!imgJogador.loadFromFile(JOGADOR))
        std::cerr << "Falha ao abrir " << JOGADOR << std::endl;

    if (!imgChao.loadFromFile(CHAO))
        std::cerr << "Falha ao abrir " << CHAO << std::endl;

    if (!imgInimigos.loadFromFile(INIMIGOS))
        std::cerr << "Falha ao abrir " << INIMIGOS << std::endl;
}

void CMD::Gerenciador::Grafico::inicializarTexturas() {
    if (!texAranhaGigante.loadFromImage(getImgInimigos(), sf::IntRect(3, 184, 12, 8))) {
        std::cerr << "Erro ao carregar em GG::inicializarTexturas" << std::endl;
        return;
    }
    texAranhaGigante.setSmooth(false); // Serve para continuar pixelada quando esticada
}

// ==========================================
// getTex

const sf::Texture& CMD::Gerenciador::Grafico::getTexJogador1() const {
    return texJogador1;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexJogador2() const {
    return texJogador2;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAranhaGigante() const {
    return texAranhaGigante;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexOlhoVoador() const {
    return texOlhoVoador;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexBruxa() const {
    return texBruxa;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexProjetil() const {
    return texProjetil;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexPlataforma() const {
    return texPlataforma;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAbobora() const {
    return texAbobora;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexCogumelo() const {
    return texCogumelo;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAmbienteRAM(int canto) const {
    return texAmbienteRAM[canto];
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAmbienteCPU(int canto) const {
    return texAmbienteCPU[canto];
}


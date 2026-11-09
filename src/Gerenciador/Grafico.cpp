#include "Grafico.h"
#include "../Ente.h"

#include "../organiza.h"
using std::cerr;
using std::endl;

using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::RenderWindow;

GerenciadorGrafico::GerenciadorGrafico(): janela()
{
    VideoMode video_mode = VideoMode::getDesktopMode();
    int estilo_janela = sf::Style::Close; // Barra de título e botão de fechar
    janela.create(video_mode, "Jogo", estilo_janela);
    janela.clear(Color::Black);
    janela.display();
}

GerenciadorGrafico::~GerenciadorGrafico(){

}

void GerenciadorGrafico::desenharEnte(Ente *pE)
{
    if (pE == NULL) {
        cerr << "Nulidade em GG::desenharEnte" << endl;
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

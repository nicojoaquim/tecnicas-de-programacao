#include "Grafico.h"
#include "../Ente.h"

#include "../organiza.h"
using std::cerr;
using std::endl;

GerenciadorGrafico::GerenciadorGrafico(): janela()
{
    // janela.create(VideoMode(900,600),"Jogo");
    janela.create(VideoMode::getDesktopMode(), "Jogo");
    janela.clear(Color::Black);
    janela.display();
    //executar();

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

void GerenciadorGrafico::executar()
{
    // adaptado do tutorial do SFML 2.6
    // para cada evento novo desde a última vez que passou pelo loop
    while (janela.pollEvent(evento))
    {
        // evento de fechar a janela
        if (evento.type == Event::Closed)
            janela.close();
    }
}

bool GerenciadorGrafico::eventoM(sf::Event& evento) {
    return janela.pollEvent(evento);
}

void GerenciadorGrafico::fechar() {
    janela.close();
}

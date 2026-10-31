#include "Grafico.h"
#include "../Ente.h"

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
void GerenciadorGrafico::desenharEnte(Ente *pE){
    pE->desenhar();
    janela.draw(*pE->getFig());
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
    // check all the window's events that were triggered since the last iteration of the loop
    while (janela.pollEvent(evento))
    {
        // "close requested" event: we close the window
        if (evento.type == Event::Closed)
            janela.close();
    }
}


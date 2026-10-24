#include"Grafico.h"
#include "Ente.h"
Gerenciador_Grafico::Gerenciador_Grafico():janela(VideoMode(900,600),"Jogo"){
   janela.clear(Color::Black);
   janela.display();
    //executar();
        
}
Gerenciador_Grafico::~Gerenciador_Grafico(){

}
void Gerenciador_Grafico::desenharEnte(Ente *pE){
    pE->desenhar();
    janela.draw(*pE->getFig());
}
bool Gerenciador_Grafico:: aberto(){
    if(janela.isOpen())
        return true;
    return false;
}
void Gerenciador_Grafico::renderiza(){
    janela.display();
}
void Gerenciador_Grafico::limpar(){
    janela.clear();
}
void Gerenciador_Grafico::executar(){
 // adaptado do tutorial do SFML 2.6
            // check all the window's events that were triggered since the last iteration of the loop
            Event evento;
            while (janela.pollEvent(evento))
            {
                // "close requested" event: we close the window
                if (evento.type == Event::Closed)
                    janela.close();
            }
        
        
}
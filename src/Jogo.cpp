#include "Jogo.h"
#include "organiza.h"
Jogo::Jogo():GG(),primeiro()
{
    primeiro.setGG(&GG);
    executar();
}

Jogo::~Jogo()
{}


void Jogo::executar()
{ RectangleShape reto({100,100});
    primeiro.setFig(&reto);
    cout << "Oi" << endl;
    primeiro.inicializaPosicao(0,500);
    while(GG.aberto()){
    GG.executar();
    primeiro.mover();
    GG.limpar();
     GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&primeiro))));
    GG.renderiza();
    }
}

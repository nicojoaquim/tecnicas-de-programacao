#include "Jogo.h"

#include "organiza.h"

Jogo::Jogo():GG(),primeiro()//,janela()
{
    primeiro.setGG(&GG);
    executar();
}

Jogo::~Jogo()
{}

void Jogo::executar()
{
    // while (janela.aberta())
    // {
    //     evento = janela.evento();
    // }
    // while (janela.isOpen())
        // Jogo::tick();

    RectangleShape reto({100,100});
    primeiro.setFig(&reto);
    cout << "Oi" << endl;
    primeiro.inicializaPosicao(0,500);
    while(GG.aberto())
    {
        GG.executar();
        primeiro.mover();
        GG.limpar();
        GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&primeiro))));
        GG.renderiza();
    }
}

// void Jogo::tick()
// {
//     while (janela.pollEvent(evento))
//     {
//         if (evento.type == sf::Event::Closed)
//             janela.close();
//     }
// }

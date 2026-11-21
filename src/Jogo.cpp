#include "Jogo.h"

#include "Fases/MemoriaRAM.h"
#include "Gerenciador/Tempo.h" // TEMP, mover telaInicial() para Menu

// Uso para debug/erros
#include "organiza.h"
using std::cout;
using std::endl;
using std::cerr;
using sf::Vector2f;
using sf::Event;
using sf::Keyboard;

CMD::Jogo::Jogo():
    telaAtual(MENU),
    GG(),
    jogador1(),
    jogador2()
{
    Ente::setGG(&GG);
    jogador1.carregarSprite();
    executar();
}

CMD::Jogo::~Jogo()
{}

void CMD::Jogo::executar()
{
    while (GG.aberto())
    {
        if (telaAtual == MENU) {
            Menu menu(this);
            menu.executar();
        }
        else if (telaAtual == FASE1) {
            std::cout << "Fase 1" << std::endl;
            CMD::Fases::MemoriaRam fase1;
            fase1.incluirJogador(&jogador1);
            //fase1.incluirJogador(&jogador2);
            fase1.executar();
            if (jogador1.getNumVida() > 0) {
                // Próxima fase
                telaAtual = FASE2;
            }
            else {
                // Jogador perdeu
                telaAtual = MENU;
            }
        }
        else if (telaAtual == FASE2) {
            std::cout << "Fase 2" << std::endl;
            GG.fechar();
        }
    }
}

void CMD::Jogo::setProximaTela(CMD::Tela tela) {
    telaAtual = tela;
}

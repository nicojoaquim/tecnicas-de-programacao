#include "Jogo.h"

#include "Fases/MemoriaRAM.h"
#include"Fases/AridoCPU.h"
#include "Gerenciador/Tempo.h"

using sf::Vector2f;
using sf::Event;
using sf::Keyboard;

// Uso para debug/erros
#include "organiza.h"
using std::cout;
using std::endl;
using std::cerr;

CMD::Jogo::Jogo():
    telaAtual(MENU),
    GG(),
    jogador1(1),
    jogador2(2),
    dois_jogadores(false)
{
    Ente::setGG(&GG);
    jogador1.carregarSprite();
    jogador2.carregarSprite();
    executar();
}

CMD::Jogo::~Jogo() {
}

void CMD::Jogo::executar()
{
    while (GG.aberto())
    {
        if (telaAtual == MENU) {
            Menu menu(this);
            // Loop do menu
            menu.executar();
            // Saiu do loop
            jogador1.reiniciar();
            jogador2.reiniciar();
        }

        else if (telaAtual == FASE1) {
            std::cout << "Fase 1" << std::endl;

            Fases::MemoriaRam fase1;

            fase1.incluirJogador(&jogador1);
            if (dois_jogadores)
                fase1.incluirJogador(&jogador2);

            // Loop de execução da fase
            fase1.executar();

            if (jogador1.getNumVida() > 0
                || (dois_jogadores && jogador2.getNumVida() > 0)) {
                // Próxima fase
                telaAtual = FASE2;
            }
            else {
                // Jogadores perderam
                telaAtual = MENU;
            }
        }

        else if (telaAtual == FASE2) {
            std::cout << "Fase 2" << std::endl;

            CMD::Fases::AridoCPU fase2;

            fase2.incluirJogador(&jogador1);
            if (dois_jogadores)
                fase2.incluirJogador(&jogador2);

            // Loop de execução
            fase2.executar();

            if (jogador1.getNumVida() > 0
                || (dois_jogadores && jogador2.getNumVida() > 0))
            {
                // ::adicionarRank(...);
            }
            telaAtual = MENU;
        }
    }
}

void CMD::Jogo::setProximaTela(CMD::Tela tela) {
    telaAtual = tela;
}

void CMD::Jogo::setDoisJogadores(bool dois) {
    dois_jogadores = dois;
}

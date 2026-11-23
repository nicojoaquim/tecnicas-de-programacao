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
    jogador1(),
    jogador2(),
    dois_jogadores(false)
{
    Ente::setGG(&GG);
    jogador1.setJogador(1);
    jogador2.setJogador(2);
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
            CMD::Fases::MemoriaRam fase1;
            // Mudar linhas para Fase
            // const sf::Vector2u tamanhoJanela = GG.getTamanhoJanela();
            // jogador1.getFig()->setPosition(tamanhoJanela.x / 3.f, tamanhoJanela.y / 3.f);
            // if (menu.getNumeroJogadores() == 2) {
            //     jogador2.getFig()->setPosition(
            //         tamanhoJanela.x * 2.f / 3.f,
            //         tamanhoJanela.y / 3.f
            //     );
            //     fase1.adicionaJog2(&jogador2);
            // }
            fase1.incluirJogador(&jogador1);
            if (dois_jogadores)
                fase1.incluirJogador(&jogador2);

            // Loop da Fase
            fase1.executar();
            if(jogador1.getNumVida() > 0 || jogador2.getNumVida() > 0)
                telaAtual = FASE2;
            else
                telaAtual = MENU;                   
            
        }
        else if (telaAtual == FASE2) {
            std::cout << "Fase 2" << std::endl;
            CMD::Fases::AridoCPU fase2;
            fase2.incluirJogador(&jogador1);
            const sf::Vector2u tamanhoJanela = GG.getTamanhoJanela();
            jogador1.getFig()->setPosition(tamanhoJanela.x / 3.f, tamanhoJanela.y / 3.f);
            if (dois_jogadores) {
                jogador2.getFig()->setPosition(
                    tamanhoJanela.x * 2.f / 3.f,
                    tamanhoJanela.y / 3.f
                );
                fase2.incluirJogador(&jogador2);
            }
            // chao.inicializaChao(&sprite3);
            // chao.getFig()->setPosition(
            //     tamanhoJanela.x / 2.f,
            //     tamanhoJanela.y - chao.getAltura() / 2.f
            // );
            // fase2.adicionaChao(&chao);
            fase2.executar();
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

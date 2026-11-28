#include "Jogo.h"

#include "Fases/MemoriaRAM.h"
#include"Fases/AridoCPU.h"
#include "Gerenciador/Tempo.h"
#include "Ranking.h"

#include <string>
#include <vector>

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

            Fases::MemoriaRam fase1;

            fase1.incluirJogador(&jogador1);
            if (dois_jogadores)
                fase1.incluirJogador(&jogador2);

            // Loop de execução da fase
            fase1.executar();

            if ( jogador1.getNumVida() > 0 || 
            (dois_jogadores && jogador2.getNumVida() > 0)) {
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

            if ( jogador1.getNumVida() > 0 || 
            (dois_jogadores && jogador2.getNumVida() > 0)) {
                cadastrarPontuacoes();
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

bool CMD::Jogo::cadastrarPontuacoes() {
    const std::size_t quantidadeJogadores = dois_jogadores ? 2 : 1;
    std::vector<sf::String> nomes(quantidadeJogadores);
    std::size_t indiceJogador = 0;
    bool concluido = false;

    sf::Text titulo("FASE 2 CONCLUIDA", GG.getFonte(), 56);
    sf::Text instrucao("", GG.getFonte(), 36);
    sf::Text pontuacao("", GG.getFonte(), 30);
    sf::Text entrada("", GG.getFonte(), 36);
    sf::Text ajuda("Digite o nome e pressione ENTER (ESC para cancelar)",
                   GG.getFonte(),
                   24);
    titulo.setFillColor(sf::Color::White);
    instrucao.setFillColor(sf::Color::White);
    pontuacao.setFillColor(sf::Color::White);
    entrada.setFillColor(sf::Color::White);
    ajuda.setFillColor(sf::Color::White);

    const sf::Vector2u tamanho = GG.getTamanhoJanela();
    const auto centralizar = [&tamanho](sf::Text& texto, float y) {
        const sf::FloatRect limites = texto.getLocalBounds();
        texto.setPosition((tamanho.x - limites.width) / 2.f, y);
    };

    while (GG.aberto() && !concluido) {
        Event evento;
        while (GG.getEvento(evento)) {
            if (evento.type == Event::Closed) {
                GG.fechar();
                return false;
            }
            if (evento.type == Event::KeyPressed) {
                if (evento.key.code == Keyboard::Escape)
                    return false;
                if (evento.key.code == Keyboard::Backspace
                    && nomes[indiceJogador].getSize() > 0) {
                    nomes[indiceJogador].erase(
                        nomes[indiceJogador].getSize() - 1);
                }
                else if (evento.key.code == Keyboard::Return
                         && nomes[indiceJogador].getSize() > 0) {
                    if (indiceJogador + 1 < quantidadeJogadores)
                        ++indiceJogador;
                    else
                        concluido = true;
                }
            }
            else if (evento.type == Event::TextEntered
                     && evento.text.unicode >= 32
                     && evento.text.unicode != 127
                     && evento.text.unicode != '|'
                     && nomes[indiceJogador].getSize() < 16) {
                nomes[indiceJogador] += evento.text.unicode;
            }
        }

        if (concluido)
            break;

        const int pontos = indiceJogador == 0
            ? jogador1.getPontos()
            : jogador2.getPontos();
        instrucao.setString(
            "Nome do Jogador " + std::to_string(indiceJogador + 1));
        pontuacao.setString("Pontuacao: " + std::to_string(pontos));
        sf::String textoEntrada = nomes[indiceJogador];
        textoEntrada += '_';
        entrada.setString(textoEntrada);

        centralizar(titulo, tamanho.y * 0.20f);
        centralizar(instrucao, tamanho.y * 0.38f);
        centralizar(pontuacao, tamanho.y * 0.48f);
        centralizar(entrada, tamanho.y * 0.58f);
        centralizar(ajuda, tamanho.y * 0.82f);

        GG.limpar();
        GG.desenharTexto(titulo);
        GG.desenharTexto(instrucao);
        GG.desenharTexto(pontuacao);
        GG.desenharTexto(entrada);
        GG.desenharTexto(ajuda);
        GG.renderizar();
    }

    if (!concluido)
        return false;

    for (std::size_t i = 0; i < quantidadeJogadores; ++i) {
        const std::basic_string<sf::Uint8> nomeUtf8 = nomes[i].toUtf8();
        const std::string nome(nomeUtf8.begin(), nomeUtf8.end());
        const int pontos = i == 0
            ? jogador1.getPontos()
            : jogador2.getPontos();
        salvarResultadoRanking(nome, pontos);
    }
    return true;
}

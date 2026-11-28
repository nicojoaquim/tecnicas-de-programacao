#pragma once

#include "Gerenciador/Grafico.h"
#include "Entidades/Personagem/Jogador.h"
#include "Entidades/Personagem/AranhaGigante.h"
#include "Gerenciador/Colisoes.h"//temporario
#include "Entidades/Chao.h"//temporario
#include "Menu.h"
#include "Fases/Fase.h"

namespace CMD
{
    enum Tela {
        MENU, FASE1, FASE2
    };

    class Jogo
    {
    private:
        Tela telaAtual;
        Gerenciador::Grafico GG;
        Entidades::Personagens::Jogador jogador1;
        Entidades::Personagens::Jogador jogador2;
        bool dois_jogadores;

        sf::Texture texture;
        sf::Sprite sprite;

        bool cadastrarPontuacoes();

    public:
        Jogo();
        ~Jogo();
        void executar();
        void setProximaTela(Tela tela);
        void setDoisJogadores(bool dois);
    };
}

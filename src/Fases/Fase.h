#pragma once

#include "../Ente.h"
#include "../Entidades/Entidade.h"
#include "../Listas/ListaEntidade.h"
#include "../Gerenciador/Colisoes.h"

namespace CMD
{
    namespace Entidades
    {
    class Entidade;
    class Chao;
        namespace Personagens
        {
            class Jogador;
        }
    }

    namespace Fases
    {
    class Fase: public Ente
    {
    protected:
        Gerenciador::Colisoes GC;
        Listas::ListaEntidade lista_ents;
        // sf::Texture texture;
        // sf::Sprite sprite;
        // Jogador* pJog1; Fase(Jogador* jogador1): pJog1(jogador1)

    public:
        Fase();
        virtual ~Fase();
        virtual void executar(); // Polimorfismo
        void adicionaChao(Entidades::Chao* chao);
        void adicionaJog1(Entidades::Personagens::Jogador* joagdor1);

    protected:
        virtual void criarInimigos() = 0;
        virtual void criarObst() = 0;
        void criarCenarios();
        // virtual void desenhar() = 0;
        // virtual void gravitar() = 0;
        // virtual void mover() = 0;
        void gravitar();
        void mover();
        void desenhar();

        void criarAranhaGigante();
        void criarOlhoVoador();
        void criarBruxa();
        void criarPlataforma();
        void criarCogumelo();
        void criarObstDificil();//mudar nome depois

        void destruirEntidade(Entidades::Entidade* pE);
    };
    }
}

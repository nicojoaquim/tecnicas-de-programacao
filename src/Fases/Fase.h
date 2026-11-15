#pragma once

#include <vector>

#include "../Ente.h"
#include "../Listas/ListaEntidade.h"
#include "../Gerenciador/Colisoes.h"
namespace trabalhoJogo{
    namespace Entidades{
        class Entidade;
        class Chao;
        namespace Personagens{
            class Jogador;
        }
    }
    namespace Fases{
    class Fase: public Ente
    {
    protected:
        Gerenciador::GerenciadorColisoes GC;
        Listas::ListaEntidade lista_ents;
        sf::Texture texture;
        sf::Sprite sprite;
        // Jogador* pJog1; Fase(Jogador* jogador1): pJog1(jogador1)

    public:
        Fase();
        virtual ~Fase();
        virtual void executar(); // Polimorfismo
        void adicionaChao(Entidades::Chao* chao);
        void adicionaJog1(Entidades::Personagens::Jogador* joagdor1); 

    protected:
        // talvez remover depois alguns metodos
        void criarAranhaGigante();
        void criarOlhoVoador();
        void criarBruxa();
        void criarPlataforma();
        void criarCogumelo();
        void criarObstDificil();//mudar nome depois
        virtual void criarInimigos() = 0;
        virtual void criarObst() = 0;
        void criarCenarios();
        // virtual void desenhar() = 0;
        // virtual void gravitar() = 0;
        // virtual void mover() = 0;
        void gravitar();
        void mover();
        void desenhar();
    };
    }
}
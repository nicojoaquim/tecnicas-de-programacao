#pragma once

#include <vector>
#include <list>
#include <set>

namespace CMD
{
    namespace Entidades
    {
        class Entidade;
        class Obstaculo;
        class Projetil;
        namespace Personagens
        {
            class Jogador;
            class Inimigo;
        }
        class Chao;
    }
    namespace Gerenciador
    {
        class GerenciadorColisoes
        {
        private:
            std::vector<Entidades::Personagens::Inimigo*> LIs;
            std::list<Entidades::Obstaculo*> LOs;
            std::set<Entidades::Projetil*> LPs;
            std::list<Entidades::Chao*> LCs;
            Entidades::Personagens::Jogador* pJog1;
            std::vector<Entidades::Personagens::Inimigo*>::iterator itIs;
            std::list<Entidades::Obstaculo*>::iterator itOs;
            std::set<Entidades::Projetil*>::iterator itPs;
            std::list<Entidades::Chao*>::iterator itCs;
            float dx;
            float dy;
            float internox; // Usado entre funções, sempre atribuir antes de usar
            float internoy; // ||

        public:
            GerenciadorColisoes();
            ~GerenciadorColisoes();
            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Entidades::Obstaculo* po);
            void incluirProjetil(Entidades::Projetil* pj);
            void incluirChao(Entidades::Chao* pc);
            void incluirJogador1(Entidades::Personagens::Jogador* pPrimeiro);
            void executar();

        private:
            void colisaoJogsInimigo();
            void colisaoJogsChao();
            void colisaoChaoInimigo();
            void tratarColisaoJogsInimigo();
            void tratarColisaoJogsObstaculo();
            void tratarColisaoJogsProjetil();
            void tratarColisaoJogsChao();
            void tratarColisaoChaoInimigo();
            const bool verificarColisao(Entidades::Entidade* p1, Entidades::Entidade* p2);
        };
    }
}

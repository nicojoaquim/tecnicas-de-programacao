#pragma once

#include <vector>
#include <list>
#include <set>

namespace CMD
{
    namespace Entidades
    {
        class Entidade;
        class Projetil;
        namespace Obstaculos
        {
            class Obstaculo;
        }
        namespace Personagens
        {
            class Jogador;
            class Inimigo;
            class AranhaGigante;
        }
        namespace Obstaculos
        {
            class Plataforma;
        }
        class Chao;
    }
    namespace Gerenciador
    {
        class Colisoes
        {
        private:
            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;
            std::vector<Entidades::Personagens::Inimigo*> LIs;
            std::list<Entidades::Obstaculos::Obstaculo*> LOs;
            std::set<Entidades::Projetil*> LPs;
            std::list<Entidades::Chao*> LCs;
            std::vector<Entidades::Personagens::Inimigo*>::iterator itIs;
            std::list<Entidades::Obstaculos::Obstaculo*>::iterator itOs;
            std::set<Entidades::Projetil*>::iterator itPs;
            std::list<Entidades::Chao*>::iterator itCs;
        public:
            Colisoes();
            ~Colisoes();
            void executar();
            void incluirInimigo(Entidades::Personagens::Inimigo* pi);
            void incluirObstaculo(Entidades::Obstaculos::Obstaculo* po);
            void incluirProjetil(Entidades::Projetil* pj);
            void incluirChao(Entidades::Chao* pc);
            void incluirJogador(Entidades::Personagens::Jogador* pJ);
            void removerInimigo(Entidades::Personagens::Inimigo* inimigo);
            bool todosJogadoresMortos() const;
            bool todosInimigosMortos() const;
        private:
            void colisaoJogsInimigo();
            void colisaoJogsObstaculo();
            void colisaoJogsProjetil();
            void colisaoJogsChao();
            void colisaoObstaculoChao();
            void colisaoProjetilChao();
            void colisaoChaoInimigo();
            void colisaoAranhaPlataforma();
            void tratarColisaoJogsInimigo();
            void tratarColisaoJogsObstaculo();
            void tratarColisaoJogsProjetil();
            //aqui tá com passagem de paremetro porque por algum motivo se não tem isso para algum jogador pular é preciso que algum pule
            void tratarColisaoJogsChao(Entidades::Personagens::Jogador* jogador);
            void tratarColisaoInimigoChao();
            void tratarColisaoObstaculoChao();
            void tratarColisaoProjetilChao();
            const bool verificarColisao(Entidades::Entidade* p1, Entidades::Entidade* p2);
        };
    }
}

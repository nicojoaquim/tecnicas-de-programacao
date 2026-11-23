#pragma once

#include "../Ente.h"
#include "../Entidades/Entidade.h"
#include "../Listas/ListaEntidade.h"
#include "../Gerenciador/Colisoes.h"
#include "../Tilemap.h"

namespace CMD
{
    namespace Entidades {
        class Entidade;
        class Chao;
        namespace Personagens {
            class Jogador;
            class Bruxa;
        }
    }

    namespace Fases {
        class Fase: public Ente
        {
        protected:
            Gerenciador::Colisoes GC;
            Listas::ListaEntidade lista_ents;
            Tilemap tilemap;
            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;
            const int maxAranhasGigantes;
            const int maxPlataformas;

        public:
            Fase();
            virtual ~Fase();
            virtual void executar(); // Polimorfismo
            void adicionaChao(Entidades::Chao* chao);
            void incluirJogador(Entidades::Personagens::Jogador* joagdor1);

        protected:
            virtual void criarInimigos() = 0;
            virtual void criarObst() = 0;
            void criarCenario();
            void executarEntidades();
            void desenhar();
            void removerInimigosMortos();
            void atualizarAlvosBruxas();
            void desenharVidas();

            void criarAranhaGigante(sf::Vector2u pos);
            void criarOlhoVoador(sf::Vector2u pos);
            void criarBruxa(sf::Vector2u pos);
            void criarProjetil(sf::Vector2u pos, Entidades::Personagens::Bruxa* pBruxa);
            void criarPlataforma(sf::Vector2u pos);
            void criarAbobora(sf::Vector2u pos);
            void criarCogumelo(sf::Vector2u pos);
            // void criarProjetil(sf::Vector2u pos);

            void destruirEntidade(Entidades::Entidade* pE);
        };
    }
}

#pragma once

#include "Obstaculo.h"
#include <vector>
namespace CMD{
    namespace Entidades{
        namespace Obstaculos{
            class Plataforma : public Obstaculo
            {
            private:
                int altura;
                sf::Vector2f posicaoInicial;
                bool posicaoInicialDefinida;
                std::vector<Personagens::Jogador*> jogadoresSobre;//um vetor para saber qual jogador está em cima da plataforma
            public:
                Plataforma();
                ~Plataforma();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void acao();
                void salvar();
                void carregar();
            };
        }
    }
}

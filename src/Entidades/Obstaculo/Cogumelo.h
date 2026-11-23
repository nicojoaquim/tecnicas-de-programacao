#pragma once

#include "Obstaculo.h"
#include <map>
namespace CMD{
    namespace Entidades{
        namespace Obstaculos{
            class Cogumelo : public Obstaculo
            {
            private:
                short int densidade;
                sf::Vector2f escalaInicial;
                float fatorEscala;
                const float escalaMaxima;
                const float velocidadeCrescimento;
                bool escalaInicializada;
                bool crescendo;
                std::map<Personagens::Jogador*, float> cooldownDano;//um cooldown para os jogadores
                //E melhor ainda já que talvez isso acabe com um requisido

            public:
                Cogumelo();
                ~Cogumelo();
                void executar();
                void obstaculizar(Personagens::Jogador* p);
                void salvar();
                void acao();
            };
        }
    }
}

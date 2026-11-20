#pragma once

#include <SFML/Graphics.hpp> // inclui sf::RenderWindow

#define FONTE "assets/fontes/monogram/monogram-extended.ttf"
#define GATO "assets/imagens/blanche100x100.png"

namespace CMD
{
    class Ente;
    namespace Gerenciador{
        class Grafico
        {
        private:
            sf::RenderWindow janela;
            sf::Image imgJogador;
            sf::Image imgChao;
            sf::Image imgInimigos;
            // sf::Image img...;

            sf::Texture texAranhaGigante;
            // sf::Texture tex...;

        public:
            Grafico();
            ~Grafico();

            void desenharEnte(Ente* pE);
            void desenharTexto(const sf::Text & texto);
            const bool aberto() const;
            void renderizar();
            void limpar();
            bool getEvento(sf::Event& evento);
            void fechar();

            const sf::Vector2u getTamanhoJanela() const;
            sf::RenderWindow & getJanela();

            const sf::Image& getImgJogador() const;
            const sf::Image& getImgChao() const;
            const sf::Image& getImgInimigos() const;
            // Para desenhar corretamente, passamos por referência
            // https://www.sfml-dev.org/tutorials/2.6/graphics/sprite/#the-white-square-problem
            const sf::Texture& getTexAranhaGigante() const { return texAranhaGigante; }

        private:
            void inicializarImagens();
            void inicializarTexturas();
        };
    }
}

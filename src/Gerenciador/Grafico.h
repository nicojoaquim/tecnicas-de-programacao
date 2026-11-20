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
            sf::Image img;
            sf::Texture texJogador1;//[2];
            sf::Texture texJogador2;//[2];
            sf::Texture texAranhaGigante;
            sf::Texture texOlhoVoador;
            sf::Texture texBruxa;
            sf::Texture texProjetil;
            sf::Texture texPlataforma;//[3];
            sf::Texture texAbobora;
            sf::Texture texCogumelo;
            sf::Texture texAmbienteRAM[12];
            sf::Texture texAmbienteCPU[12];

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
            // Para desenhar corretamente, passamos textura por referência
            // https://www.sfml-dev.org/tutorials/2.6/graphics/sprite/#the-white-square-problem
            const sf::Texture& getTexJogador1() const;
            const sf::Texture& getTexJogador2() const;
            const sf::Texture& getTexAranhaGigante() const;
            const sf::Texture& getTexOlhoVoador() const;
            const sf::Texture& getTexBruxa() const;
            const sf::Texture& getTexProjetil() const;
            const sf::Texture& getTexPlataforma() const;
            const sf::Texture& getTexAbobora() const;
            const sf::Texture& getTexCogumelo() const;
            const sf::Texture& getTexAmbienteRAM(int canto) const;
            const sf::Texture& getTexAmbienteCPU(int canto) const;

        private:
            const sf::Image& getImg() const;
            void inicializarImagens();
            void inicializarTexturas();
        };
    }
}

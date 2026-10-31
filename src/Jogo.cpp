#include "Jogo.h"

// Uso para debug/erros
#include "organiza.h"

Jogo::Jogo():
    GG(),
    primeiro(),
    texture(),
    sprite(),
    font(),
    text(),
    text2(L"ç texto acima",font,100)
{
    primeiro.setGG(&GG);

    if (!texture.loadFromFile(GATO)) {
        cerr << "Error loading texture: " << GATO << endl;
        exit(1);
    }
    cout << "Success to load texture" << endl;
    texture.setSmooth(true);

    sprite.setTexture(texture);

    primeiro.setFig(&sprite);
    primeiro.inicializaPosicao(0,0);

    if (!font.loadFromFile(FONTE)) {
        cerr << "Error loading font: " << FONTE << endl;
        exit(1);
    }
    cout << "Success to load font" << endl;

    text.setFont(font);
    text.setString(L"Olá texo embaixo"); // L"" necessário para á
    text.setCharacterSize(100);

    text2.setPosition((sf::Vector2f){0, 100});

    executar();
}

Jogo::~Jogo()
{}

void Jogo::preparar()
{
    GG.executar(); // Eventos
    primeiro.mover();
}

void Jogo::desenhar()
{
    GG.limpar(); // Início

    GG.temporario_desenharTexto(text);
    GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&primeiro))));
    GG.temporario_desenharTexto(text2);

    GG.renderizar(); // Final
}

void Jogo::executar()
{
    while(GG.aberto())
    {
        preparar();
        desenhar();
    }
}


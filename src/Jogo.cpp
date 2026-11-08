#include "Jogo.h"

// Uso para debug/erros
#include "organiza.h"
using std::cout;
using std::endl;
using std::cerr;
using sf::Vector2f;
using sf::Event;

Jogo::Jogo():
    telaAtual(MENU),
    GG(),
    GC(),
    primeiro(),
    menu(),
    teste(),
    texture(),
    sprite(),
    sprite2(),
    font(),
    text(),
    text2(L"ç texto acima",font,100)
{
    Ente::setGG(&GG);

    if (!texture.loadFromFile(GATO)) {
        cerr << "Error loading texture: " << GATO << endl;
        exit(1);
    }
    cout << "Success to load texture" << endl;
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite2.setTexture(texture);

    primeiro.atribuirSprite(&sprite);
    teste.atribuirSprite(&sprite2);
    //teste.setPosicao(Vector2f(105.f,105.f));

    if (!font.loadFromFile(FONTE)) {
        cerr << "Error loading font: " << FONTE << endl;
        exit(1);
    }
    cout << "Success to load font" << endl;

    text.setFont(font);
    text.setString(L"Olá texo embaixo"); // L"" necessário para á
    text.setCharacterSize(100);

    text2.setPosition(Vector2f(0.f, 100.f));

    executar();
}

Jogo::~Jogo()
{}

void Jogo::preparar()
{
    //GG.executar(); // Eventos
    primeiro.mover();

    // Mudar depois para o GC
    primeiro.colidir(static_cast<Inimigo*>(&teste));//a colição
}

void Jogo::desenhar()
{
    GG.limpar(); // Início

    GG.desenharTexto(text);
    // GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&primeiro))));// jogador
    // GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&teste))));//boneco de teste
    primeiro.desenhar();
    teste.desenhar();
    GG.desenharTexto(text2);

    GG.renderizar(); // Final
}

void Jogo::telaInicial()
{
    Event evento;
    int ativo = 1;
    while (ativo) {
        GG.limpar();
        while (GG.getEvento(evento)) {
            if (evento.type == Event::Closed) {
                GG.fechar();
                return;
            }

            menu.tratarEvento(evento, ativo);
        }
        menu.desenha();
        GG.renderizar();
    }
    // Temporário
    if (ativo == 0) telaAtual = FASE1;
}

void Jogo::telaTeste()
{
    bool ativo = true;
    Event evento;
    while (ativo) {
        while (GG.getEvento(evento)) {
            if (evento.type == Event::Closed) {
                GG.fechar();
                ativo = false;
                // return;
            }
            if ((evento.type == Event::KeyPressed)&&(evento.key.code == sf::Keyboard::Escape)) {
                GG.fechar();
                ativo = false;
                // return;
            }
        }
        preparar();
        desenhar();
    }
}

void Jogo::executar()
{
    while (GG.aberto())
    {
        if (telaAtual == MENU) {
            telaInicial();
        }
        else if (telaAtual == FASE1) {
            telaTeste();
        }
        else if (telaAtual == FASE2) {
        }
        // cerr << "Fim do while em executar " << GG.aberto() << endl;
    }
}


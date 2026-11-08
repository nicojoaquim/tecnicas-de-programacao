#include "Jogo.h"

// Uso para debug/erros
#include "organiza.h"
using std::cout;
using std::endl;
using std::cerr;
using sf::Vector2f;

Jogo::Jogo():
    GG(),
    GC(),
    menu(),
    primeiro(),
    chao(),
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
    GC.incluirJogador1(&primeiro);
    GC.incluirInimigo(&teste);
    GC.incluirChao(&chao);
    sprite.setTexture(texture);
    sprite2.setTexture(texture);
    sprite3.setTexture(texture);
    sprite2.setPosition(100,100);
    primeiro.atribuirSprite(&sprite);
    teste.atribuirSprite(&sprite2);
    teste.setPosicaoEsper({105.f, 105.f});
    chao.inicializaChao(&sprite3);
    chao.setPosicaoEsper({0.f,600.f});
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
    teste.mover();
    GC.executar();
    //primeiro.colidir(static_cast<Inimigo*>(&teste));//a colição
}

void Jogo::desenhar()
{
    GG.limpar(); // Início

    GG.desenharTexto(text);
    // GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&primeiro))));// jogador
    // GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&teste))));//boneco de teste
    primeiro.desenhar();
    teste.desenhar();
    chao.desenhar();
    GG.desenharTexto(text2);

    GG.renderizar(); // Final
}

void Jogo::telaInicial(sf::Event* evento)
{
    int ativo = 1;
    while (GG.aberto() && ativo) {
        GG.limpar();
        while (GG.eventoM(*evento)) {
            if (evento->type == sf::Event::Closed)
                GG.fechar();

            menu.tratarEvento(*evento, ativo);
        }
        menu.desenha();
        GG.renderizar();
    }
    Personagem::restartRelogio();
}

void Jogo::executar()
{
    sf::Event evento;
    telaInicial(&evento);
    while (GG.aberto()) {
        while (GG.eventoM(evento)) {
            if (evento.type == sf::Event::Closed)
                GG.fechar();

            //menu.tratarEvento(evento);
        }
        preparar();
        desenhar();
        gravidade();
    }
}

void Jogo::gravidade(){
    float dt = Personagem::getSegundos();
    primeiro.gravitar(dt);
    teste.gravitar(dt);
}
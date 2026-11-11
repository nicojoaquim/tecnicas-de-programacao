#include "Jogo.h"

#include "Fases/MemoriaRAM.h"
#include "Gerenciador/Tempo.h"

// Uso para debug/erros
#include "organiza.h"
using std::cout;
using std::endl;
using std::cerr;
using sf::Vector2f;
using sf::Event;
using sf::Keyboard;

Jogo::Jogo():
    telaAtual(MENU),
    GG(),
    GC(),
    jogador1(),
    menu(),
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
    GC.incluirJogador1(&jogador1);
    GC.incluirInimigo(&teste);
    GC.incluirChao(&chao);
    sprite.setTexture(texture);
    sprite2.setTexture(texture);
    sprite3.setTexture(texture);
    sprite2.setPosition(100,100);
    jogador1.atribuirSprite(&sprite);
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
    text.setString(L"Olá texto embaixo"); // L"" necessário para á
    text.setCharacterSize(100);

    text2.setPosition(Vector2f(0.f, 100.f));

    executar();
}

Jogo::~Jogo()
{}
/*
void Jogo::preparar()
{
    //GG.executar(); // Eventos
    jogador1.mover();
    teste.mover();
    GC.executar();
}

void Jogo::desenhar()
{
    GG.limpar(); // Início

    GG.desenharTexto(text);
    // GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&jogador1))));// jogador
    // GG.desenharEnte(static_cast<Ente*>(static_cast<Entidade*>(static_cast<Personagem*>(&teste))));//boneco de teste
    jogador1.desenhar();
    teste.desenhar();
    chao.desenhar();
    GG.desenharTexto(text2);

    GG.renderizar(); // Final
}
*/
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
    if (ativo == 0)
        telaAtual = FASE1;
    Tempo::restartRelogio();
}
/*
void Jogo::gravidade(){
    float dt = Personagem::getSegundos();
    jogador1.gravitar(dt);
    teste.gravitar(dt);
}
*/

void Jogo::executar()
{
    while (GG.aberto())
    {
        if (telaAtual == MENU) {
            telaInicial();
        }
        else if (telaAtual == FASE1) {
            MemoriaRam fase1;
            fase1.tempAdicionaEnt(&jogador1);
            fase1.tempAdicionaEnt(&chao);
            //fase1.tempAdicionaEnt(&teste); // TEMP Mudar para fase1.criarInimigos()
            fase1.executar();
            if (jogador1.getNumVida() > 0) {
                // Próxima fase
                telaAtual = FASE2;
            }
            else {
                // Perdeu, nenhum ponteiro tem endereço de jogador na memória mais
                telaAtual = MENU;
            }
        }
        else if (telaAtual == FASE2) {
            // telaTeste();
            GG.fechar();
        }
    }
}

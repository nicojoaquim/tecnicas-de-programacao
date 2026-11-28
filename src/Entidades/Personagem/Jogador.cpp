#include "Jogador.h"

#include "Inimigo.h"
#include "../../Gerenciador/Tempo.h"
#include "../../Gerenciador/Grafico.h"

#include <SFML/Window/Keyboard.hpp>
#include "../../organiza.h"

using sf::Keyboard;
using sf::Vector2f;
using std::cerr;
using std::endl;

CMD::Entidades::Personagens::Jogador::Jogador():
    Jogador(1, sf::String(""))
{
}

CMD::Entidades::Personagens::Jogador::Jogador(int jogadorX, sf::String texto):
    Personagem(),
    pontos(0),
    jogador(jogadorX),
    nome(),
    recuando(false),
    pegajoso(false),
    tempoInvulneravel(0.f)
{
    num_vida = VIDA_INICIAL;
    nome.setString(texto);
    if (pGG != NULL)
        nome.setFont(pGG->getFonte());
}

CMD::Entidades::Personagens::Jogador::Jogador(int jogadorX,
                                              const sf::Font& fonte,
                                              sf::String texto):
    Personagem(),
    pontos(0),
    jogador(jogadorX),
    nome(texto, fonte, 20),
    recuando(false),
    pegajoso(false),
    tempoInvulneravel(0.f)
{
    num_vida = VIDA_INICIAL;
}

CMD::Entidades::Personagens::Jogador::~Jogador()
{
    if (getFig() != NULL)
        delete getFig();
}

void CMD::Entidades::Personagens::Jogador::carregarSprite() {
    sf::Sprite* pSprite = new sf::Sprite;

    if (jogador == 1)
        pSprite->setTexture(pGG->getTexJogador1());
    else
        pSprite->setTexture(pGG->getTexJogador2());

    atribuirSprite(pSprite);
}

//baseado na colisão de Hilze Vonck
bool CMD::Entidades::Personagens::Jogador::colidir(Personagens::Inimigo* pIn) {
    if (pIn == NULL) {
        cerr << "Inimigo nulo" << endl;
        return false;
    }

    const float dx = pIn->getX() - getX();
    const float dy = pIn->getY() - getY();
    const float interx =
        (getLargura() + pIn->getLargura()) / 2.f - std::abs(dx);
    const float intery =
        (getAltura() + pIn->getAltura()) / 2.f - std::abs(dy);

    if (interx > 0.f && intery > 0.f) {
        if (interx < intery) {
            if (dx > 0.f) {
                setPosicao({ getX() - interx, getY() });
                if (tempoInvulneravel <= 0.f)
                    velocidade.x = 0.f;
                pIn->danificar(this);
            } else {
                setPosicao({ getX() + interx, getY() });
                if (tempoInvulneravel <= 0.f)
                    velocidade.x = 0.f;
                pIn->danificar(this);
            }
        }
        else {
            if (dy > 0.f) {
                setPosicao({ getX(), getY() - intery });
                esta_no_chao = true; // fazer que nem no mário
                esmagar(pIn);
            } else {
                setPosicao({ getX(), getY() + intery });
                if (tempoInvulneravel <= 0.f)
                    velocidade.y = 0.f;
                pIn->danificar(this);
            }
        }
        return true;
    }
    return false;
}

void CMD::Entidades::Personagens::Jogador::executar() {
    gravitar();
    mover();
}

void CMD::Entidades::Personagens::Jogador::salvarDataBuffer() {
    Personagem::salvarDataBuffer();
    buffer << "Jogador\n"
           << pontos << "\n"
           << jogador << "\n"
           //<< nome.getString().getSize() << "\n"
           << nome.getString().toAnsiString() << "\n"
           << recuando << "\n"
           << pegajoso << "\n"
           << tempoInvulneravel << "\n";
}

void CMD::Entidades::Personagens::Jogador::carregarDataBuffer() {
    Personagem::carregarDataBuffer();
    std::cout << "Leitura do jogador\n";

    std::string str;
    buffer >> str;
    if (str != std::string("Jogador")) {
        std::cerr << "erro: dados inválidos em Jogador::carregarDataBuffer()" << std::endl;
        return;
    }

    int pontos_save, jogX;
    buffer >> pontos_save;
    buffer >> jogX;

    //int size_nome;
    //buffer >> size_nome;
    str.clear();
    std::getline(buffer, str);
    nome.setString(sf::String(str));

    bool b;
    buffer >> b;
    recuando = b;
    buffer >> b;
    pegajoso = b;

    float tempo;
    buffer >> tempo;
    tempoInvulneravel = tempo;
}

void CMD::Entidades::Personagens::Jogador::salvar() {
    std::ofstream arquivo("save/Jogador.txt");//, std::ios::out | std::ios::trunc);
    if (!arquivo) {
        std::cerr << "erro ao salvar arquivo em Jogador::salvar()" << std::endl;
    }

    buffer.clear();
    Jogador::salvarDataBuffer();
    arquivo << buffer.str();
    arquivo.close();
}

void CMD::Entidades::Personagens::Jogador::carregar() {
    std::ifstream arquivo("save/Jogador.txt");
    if (!arquivo) {
        std::cerr << "erro ao carregar arquivo em Jogador::carregar()" << std::endl;
    }

    if (arquivo.get() != '#') { // Primeiro caractere
        std::cerr << "erro: Jogador::carregar não recebeu dados válidos" << std::endl;
        return;
    }
    //std::string linha;
    //while (std::getline(arquivo, linha)) { buffer << linha << '\n'; }

    //buffer.clear();
    //buffer << arquivo.rdbuf();
    //std::cout << buffer.str();
    //std::istringstream str(buffer.str());

    //int id;
    //arquivo >> id;
    //setId(id);

    buffer.clear();
    buffer << arquivo.rdbuf();

    Jogador::carregarDataBuffer();

    arquivo.close();
}

int & CMD::Entidades::Personagens::Jogador::operator++(){
    return ++pontos;
}

void CMD::Entidades::Personagens::Jogador::setPegajoso(bool estado) {
    pegajoso = estado;
}

void CMD::Entidades::Personagens::Jogador::receberDanoDeInimigo(
    int dano,
    const sf::Vector2f posicaoInimigo)
{
    if (num_vida <= 0 || tempoInvulneravel > 0.f || dano <= 0)
        return;

    num_vida = std::max(0, num_vida - dano);
    tempoInvulneravel = 1.f;

    const float diferencaX = getX() - posicaoInimigo.x;
    const float direcaoEmpurrao = diferencaX == 0.f
        ? (recuando ? 1.f : -1.f)
        : (diferencaX > 0.f ? 1.f : -1.f);
    velocidade.x = direcaoEmpurrao * 350.f;
    velocidade.y = -300.f;
    esta_no_chao = false;
}

void CMD::Entidades::Personagens::Jogador::reiniciar() {
    num_vida = VIDA_INICIAL;// VIDA_INICIAL/2;
    velocidade = sf::Vector2f(0.f, 0.f);
    esta_no_chao = false;
    pegajoso = false;
    recuando = false;
    tempoInvulneravel = 0.f;
}

void CMD::Entidades::Personagens::Jogador::setJogador(int jogadorX) {
    jogador = jogadorX;
}

void CMD::Entidades::Personagens::Jogador::mover() {
    sf::Vector2f dv(0, 0);
    float dt = Gerenciador::Tempo::getSegundos();
    tempoInvulneravel = std::max(0.f, tempoInvulneravel - dt);
    const bool movimentoLento = pegajoso;
    pegajoso = false;

    const float aceleracaoHorizontal = movimentoLento ? 100.f : 800.f;
    const float velocidadeMaximaChao = movimentoLento ? 75.f : 400.f;
    const float velocidadeMaximaAr = movimentoLento ? 90.f : 500.f;

    const Keyboard::Key teclaPular = (jogador == 1) ? Keyboard::Up : Keyboard::W;
    const Keyboard::Key teclaEsquerda = (jogador == 1) ? Keyboard::Left : Keyboard::A;
    const Keyboard::Key teclaDireita = (jogador == 1) ? Keyboard::Right : Keyboard::D;

    if (esta_no_chao && Keyboard::isKeyPressed(teclaPular)) {
            velocidade.y -= 900.;
            esta_no_chao = false;
    }

    if (Keyboard::isKeyPressed(teclaEsquerda)){
        dv.x -= aceleracaoHorizontal;
        if(!recuando){
            recuando = true;
            getFig()->scale(-1,1);
        }
    }

    if (Keyboard::isKeyPressed(teclaDireita)){
        dv.x += aceleracaoHorizontal;
        if(recuando){
            recuando = false;
            getFig()->scale(-1,1);
        }
    }

    velocidade += dv;

    if(esta_no_chao)
    {
        velocidade.x *= 0.85f; // Desaceleração no chão, atrito

        if (std::abs(velocidade.x) < 1.f)
                velocidade.x = 0.f;

        if (std::abs(velocidade.x) > velocidadeMaximaChao) {

            if(velocidade.x > 0)
                velocidade.x = velocidadeMaximaChao;
            else
                velocidade.x = -velocidadeMaximaChao;
        }
    }
    else
    {
        velocidade.x *= 0.98f; // Desaceleração no ar, arrasto

        if (std::abs(velocidade.x) < 1.f)
                velocidade.x = 0.f;

        if (std::abs(velocidade.x) > velocidadeMaximaAr) {
            if(velocidade.x > 0)
                    velocidade.x = velocidadeMaximaAr;
            else
                velocidade.x = -velocidadeMaximaAr;
        }
    }

    Entidade::mover(velocidade*dt);
    //std::cout << velocidade.x << "\t" << velocidade.y << "\t"<< std::endl;
}

void CMD::Entidades::Personagens::Jogador::esmagar(Personagens::Inimigo* pIn) {
    const int danoDoJog = 3;
    for (int i = 0; i < danoDoJog; ++i) {
        pIn->operator--();
        operator++();//temporario
    }
}

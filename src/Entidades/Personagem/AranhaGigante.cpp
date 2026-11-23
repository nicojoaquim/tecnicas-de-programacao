#include "AranhaGigante.h"
#include "../Obstaculo/Plataforma.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Gerenciador/Tempo.h"
#include"Jogador.h"
// #include"organiza.h"
using sf::Vector2f;
using sf::Vector2u;
using sf::Keyboard;

CMD::Entidades::Personagens::AranhaGigante::AranhaGigante():
    Inimigo(),
    raio(true),
    indoParaFrente(true),
    mudou_direcao(false),
    plataformaSuporte(NULL)
{
    sf::Sprite* pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexAranhaGigante());
    atribuirSprite(pSprite);
}

CMD::Entidades::Personagens::AranhaGigante::~AranhaGigante() {
    if (getFig() != NULL)
        delete getFig();
}

void CMD::Entidades::Personagens::AranhaGigante::executar(){
    gravitar();
    mover();

    if (mudou_direcao) {
        mudou_direcao = false;
        getFig()->scale(-1.f, 1.f);
    }
}

void CMD::Entidades::Personagens::AranhaGigante::salvar(){
    salvarDataBuffer();
}

void CMD::Entidades::Personagens::AranhaGigante::mover(){
    const float dt = Gerenciador::Tempo::getSegundos();
    const float velocidade = 100.f;
    const sf::Vector2u janela = pGG->getTamanhoJanela();
    float limiteEsquerdo = getLargura() / 2.f;
    float limiteDireito = static_cast<float>(janela.x) - getLargura() / 2.f;

    if (plataformaSuporte != NULL) {
        const float folga = 4.f;
        limiteEsquerdo =
            plataformaSuporte->getX()
            - plataformaSuporte->getLargura() / 2.f
            - getLargura() / 2.f + folga;
        limiteDireito =
            plataformaSuporte->getX()
            + plataformaSuporte->getLargura() / 2.f
            + getLargura() / 2.f - folga;
    }

    float proximaPosicaoX = getX() + (indoParaFrente ? 1.f : -1.f) * velocidade * dt;
    if (proximaPosicaoX >= limiteDireito) {
        proximaPosicaoX = limiteDireito;
        if (indoParaFrente) {
            indoParaFrente = false;
            mudou_direcao = true;
        }
    } else if (proximaPosicaoX <= limiteEsquerdo) {
        proximaPosicaoX = limiteEsquerdo;
        if (!indoParaFrente) {
            indoParaFrente = true;
            mudou_direcao = true;
        }
    }

    Entidade::mover({ proximaPosicaoX - getX(), 0.f });
}
//fazendo a aranha ficar em cima da plataforma
bool CMD::Entidades::Personagens::AranhaGigante::colidirPlataforma(
    Obstaculos::Plataforma* plataforma) {
    if (plataforma == NULL || getV().y < 0.f)
        return false;

    const float sobreposicaoX =
        (getLargura() + plataforma->getLargura()) / 2.f
        - std::abs(getX() - plataforma->getX());
    if (sobreposicaoX <= 0.f)
        return false;

    const float topoPlataforma =
        plataforma->getY() - plataforma->getAltura() / 2.f;
    const float baseAranha = getY() + getAltura() / 2.f;
    const float distanciaVertical = baseAranha - topoPlataforma;
    const float toleranciaSuperior = plataformaSuporte == plataforma ? 12.f : 2.f;
    const float toleranciaInferior = std::max(
        20.f,
        getV().y * Gerenciador::Tempo::getSegundos() + 2.f
    );

    if (distanciaVertical < -toleranciaSuperior
        || distanciaVertical > toleranciaInferior
        || getY() >= plataforma->getY()) {
        return false;
    }

    setPosicao({
        getX(),
        topoPlataforma - getAltura() / 2.f
    });
    setVy(0.f);
    plataformaSuporte = plataforma;
    return true;
}

void CMD::Entidades::Personagens::AranhaGigante::perderPlataforma() {
    plataformaSuporte = NULL;
}

void CMD::Entidades::Personagens::AranhaGigante::danificar(Jogador* pJog){
    morder(pJog);
}

void CMD::Entidades::Personagens::AranhaGigante::morder(Jogador* pJog){
    if (pJog != NULL) {
        const int dano = agresividade + raio;
        pJog->receberDanoDeInimigo(dano, getPosicao());
    }
}

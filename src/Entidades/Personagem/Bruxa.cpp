#include "Bruxa.h"
#include "../Projetil.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Gerenciador/Tempo.h"
#include "Jogador.h"
// #include "../../organiza.h"
#include <cmath>

using sf::Vector2f;
using sf::Vector2u;

CMD::Entidades::Personagens::Bruxa::Bruxa():
    Inimigo(),
    forca(3),
    tempoParada(0.f),
    tempoParaMover(2.0f), // Fica 2 segundos parada
    posicaoAlvo(0.f, 0.f),
    estaSeMovendo(false),
    tempoDisparo(0.f),
    intervaloDisparo(2.5f),
    projetil(NULL),
    jogador1(NULL),
    jogador2(NULL)
{
    agresividade = 3;
    recompenca = 5;
    // Define a primeira posição alvo aleatória assim que ela nasce
    Vector2u tam = pGG->getTamanhoJanela();
    posicaoAlvo = Vector2f(
        rand() % (tam.x - 100) + 50.f,
        rand() % (tam.y - 200) + 50.f
    );

    sf::Sprite* pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexBruxa());
    atribuirSprite(pSprite);
}

CMD::Entidades::Personagens::Bruxa::~Bruxa() {
    if (getFig() != NULL)
        delete getFig();

}
void CMD::Entidades::Personagens::Bruxa::executar(){
    gravitar();
    mover();
    criarProjetil();
}
void CMD::Entidades::Personagens::Bruxa::salvar(){
    salvarDataBuffer();
}
//em resumo ela escolhe uma posição e vai até lá e depois fica parada... susetivamente
void CMD::Entidades::Personagens::Bruxa::mover() {
    const float dt = Gerenciador::Tempo::getSegundos();
    const float velocidadeBruxa = 150.f;
    const float deslocamentoGravidade = getV().y * dt;

    if (!estaSeMovendo) {
        tempoParada += dt;
        Entidade::mover({0.f, -deslocamentoGravidade});


        if (tempoParada >= tempoParaMover) {
            estaSeMovendo = true;

            Vector2u tam = pGG->getTamanhoJanela();
            posicaoAlvo = Vector2f(
                rand() % (tam.x - 100) + 50.f,
                rand() % (tam.y - 200) + 50.f
            );
            /* MUDAR: de ->setScale() para ->scale()
            if (posicaoAlvo.x < getX()) {
                getFig()->setScale(-1.f, 1.f);
            } else {
                getFig()->setScale(1.f, 1.f);
            }
            */
        }
    }
    else {
        Vector2f posicaoAtual = getPosicao();
        Vector2f direcao = posicaoAlvo - posicaoAtual;

        // Lembrando que em GA precisa fazer raiz da soma dos quadrados das coordenadas
        float distancia = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

        if (distancia < 5.f) {
            estaSeMovendo = false;
            tempoParada = 0.f;
            Entidade::mover({0.f, -deslocamentoGravidade});
            tempoParaMover = 1.5f + (rand() % 20) / 10.f; // Entre 1.5s e 3.5s
        }
        else {
            const float distanciaMovida = std::min(distancia, velocidadeBruxa * dt);
            Vector2f deslocamento = (direcao / distancia) * distanciaMovida;
            deslocamento.y -= deslocamentoGravidade;
            Entidade::mover(deslocamento);

            if (distancia <= velocidadeBruxa * dt) {
                estaSeMovendo = false;
                tempoParada = 0.f;
                tempoParaMover = 1.5f + (rand() % 20) / 10.f;
            }
        }
    }
    velocidade.y = 0.f;
}
void CMD::Entidades::Personagens::Bruxa::danificar(Jogador* pJog){
    tapaMagico(pJog);
}
void CMD::Entidades::Personagens::Bruxa::criarProjetil(){
    if (projetil == NULL || projetil->estaAtivo())
        return;

    tempoDisparo += Gerenciador::Tempo::getSegundos();
    if (tempoDisparo < intervaloDisparo)
        return;

    Jogador* alvo = NULL;
    if (jogador1 != NULL && jogador1->getNumVida() > 0)
        alvo = jogador1;

    if (jogador2 != NULL && jogador2->getNumVida() > 0) {
        if (alvo == NULL) {
            alvo = jogador2;
        } else {
            const Vector2f distanciaJogador1 = jogador1->getPosicao() - getPosicao();
            const Vector2f distanciaJogador2 = jogador2->getPosicao() - getPosicao();
            const float distancia1 =
                distanciaJogador1.x * distanciaJogador1.x
                + distanciaJogador1.y * distanciaJogador1.y;
            const float distancia2 =
                distanciaJogador2.x * distanciaJogador2.x
                + distanciaJogador2.y * distanciaJogador2.y;
            if (distancia2 < distancia1)
                alvo = jogador2;
        }
    }

    if (alvo != NULL) {
        projetil->disparar(getPosicao(), alvo->getPosicao());
        tempoDisparo = 0.f;
    }
}

void CMD::Entidades::Personagens::Bruxa::setProjetil(Projetil* pProjetil) {
    projetil = pProjetil;
}

void CMD::Entidades::Personagens::Bruxa::setAlvos(Jogador* pJog1,
    Jogador* pJog2)
     {
    jogador1 = pJog1;
    jogador2 = pJog2;
}

void CMD::Entidades::Personagens::Bruxa::tapaMagico(Jogador* pJog){
    if (pJog != NULL)
        pJog->receberDanoDeInimigo(forca * agresividade, getPosicao());
}

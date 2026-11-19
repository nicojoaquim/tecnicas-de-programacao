#include "Colisoes.h"
#include "../Entidades/Entidade.h"

#include "../Entidades/Personagem/Personagem.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Personagem/Inimigo.h"
#include "../Entidades/Chao.h"
// Projétil
// Obstáculo

#include "../organiza.h"

#include <cmath>
using std::abs;

using std::vector;
using std::set;
using std::list;

using sf::Vector2f;

CMD::Gerenciador::Colisoes::Colisoes():
    LIs(),
    LOs(),
    LPs(),
    LCs(),
    pJog1(NULL),
    dx(0),
    dy(0),
    internox(0),
    internoy(0)
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
    LCs.clear();
}

CMD::Gerenciador::Colisoes::~Colisoes() {
    pJog1 = NULL;
    LIs.clear();
    LOs.clear();
    LPs.clear();
    LCs.clear();
}

void CMD::Gerenciador::Colisoes::incluirJogador1(Entidades::Personagens::Jogador* pPrimeiro){
    if(pPrimeiro != NULL)
        pJog1 = pPrimeiro;

}

void CMD::Gerenciador::Colisoes::incluirInimigo(Entidades::Personagens::Inimigo* pi) {
    if(pi != NULL)
        LIs.push_back(pi);
}

void CMD::Gerenciador::Colisoes::incluirObstaculo(Entidades::Obstaculo* po) {
    if(po != NULL)
        LOs.push_back(po);
}

void CMD::Gerenciador::Colisoes::incluirProjetil(Entidades::Projetil* pj) {
    if(pj != NULL)
        LPs.insert(pj);
}

void CMD::Gerenciador::Colisoes::incluirChao(Entidades::Chao* pc) {
    if(pc != NULL)
        LCs.push_back(pc);
}

const bool CMD::Gerenciador::Colisoes::verificarColisao(Entidades::Entidade* p1, Entidades::Entidade* p2)
{
    if (p1 == NULL || p2 == NULL) {
        std::cerr << "Nulidade em GC::verificarColisao" << std::endl;
        return false;
    }

    Vector2f pos1 = p1->getPosicao();
    Vector2f pos2 = p2->getPosicao();

    dx = pos1.x - pos2.x;
    dy = pos1.y - pos2.y;

    // As linhas a seguir supõem que x e y são do centro, pois retângulos diferentes têm
    // suas pontas sups. esqs. a uma distância diferente do que da dos seus centros.
    internox = abs(dx) - (p1->getLargura() + p2->getLargura())/2;
    internoy = abs(dy) - (p1->getAltura() + p2->getAltura())/2;

    return (internox < 0.0f && internoy < 0.0f);
}

void CMD::Gerenciador::Colisoes::tratarColisaoJogsInimigo() {
    if (LIs.empty()) {
        std::cout << "tentativa de acessar vetor de inimigo vazio" << std::endl;
        return;
    }
    if (internox > internoy) {
        if (dx > 0)
            pJog1->getFig()->setPosition(pJog1->getX()-internox,pJog1->getY());
        else
            pJog1->getFig()->setPosition(pJog1->getX()+internox,pJog1->getY());
    }
    else {
        if(dy>0)
            pJog1->getFig()->setPosition(pJog1->getX(),pJog1->getY()-internoy);
        else
            pJog1->getFig()->setPosition(pJog1->getX(),pJog1->getY()+internoy);
    }
}

void CMD::Gerenciador::Colisoes::tratarColisaoJogsObstaculo() {

}

void CMD::Gerenciador::Colisoes::tratarColisaoJogsProjetil() {

}

// baseado em https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
void CMD::Gerenciador::Colisoes::tratarColisaoJogsChao() {
    if (LCs.empty()) {
        std::cout << "tentativa de acessar lista de chao vazia" << std::endl;
        return;
    }

    if(internox > internoy) {
        if (dx > 0)
            pJog1->setPosicao({pJog1->getX()-internox,pJog1->getY()});//um jeito dinâmico de expilir o jogador
        else
            pJog1->setPosicao({pJog1->getX()+internox,pJog1->getY()});
    }
    else {
        if (dy > 0)
            pJog1->setPosicao({pJog1->getX(),pJog1->getY()-internoy});
        else {
            pJog1->setPosicao({
                pJog1->getX(),
                (*itCs)->getY() - ((*itCs)->getAltura() + pJog1->getAltura())/2.f
            });
            pJog1->setVy(0); //para o jogador não ficar quicando ou atravessar o chão
            pJog1->setEstaNoChao(true);
        }
    }
}

void CMD::Gerenciador::Colisoes::tratarColisaoChaoInimigo(){
    if(LCs.empty() || LIs.empty()){
        std::cout << "tentativa de acessar lista de chao ou vetor de inimigo vazio" << std::endl;
        return;
    }

    if(internox > internoy){
        if(dx > 0)
            (*itIs)->getFig()->setPosition((*itIs)->getX()-internox,(*itIs)->getY());
        else
            (*itIs)->getFig()->setPosition((*itIs)->getX()+internox,(*itIs)->getY());
        }
    else {
        if (dy>0)
            (*itIs)->getFig()->setPosition((*itIs)->getX(),(*itIs)->getY()-internoy);

        else {
            (*itIs)->getFig()->setPosition({
                (*itIs)->getX(),
                (*itCs)->getY() - ((*itCs)->getAltura() + (*itIs)->getAltura())/2.f
            });
            (*itIs)->setVy(0);}
    }
}
void CMD::Gerenciador::Colisoes::executar()
{
    colisaoJogsInimigo();
    colisaoJogsChao();
    colisaoChaoInimigo();
}

void CMD::Gerenciador::Colisoes::colisaoJogsInimigo(){
    for (itIs = LIs.begin(); itIs != LIs.end(); itIs++) {
        if (verificarColisao(
                static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(pJog1)),
                static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(*itIs))))
        {
            tratarColisaoJogsInimigo();
        }
    }
}
void CMD::Gerenciador::Colisoes::colisaoJogsChao(){
    for (itCs = LCs.begin(); itCs != LCs.end(); itCs++) {
        if (verificarColisao(
                static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(pJog1)),
                static_cast<Entidades::Entidade*>((*itCs))))
        {
            tratarColisaoJogsChao();
        }
    }
}
void CMD::Gerenciador::Colisoes::colisaoChaoInimigo(){
    for (itCs = LCs.begin(); itCs != LCs.end(); itCs++) {
        for (itIs = LIs.begin(); itIs != LIs.end(); itIs++)
            if (verificarColisao(
                    static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(*itIs)),
                    static_cast<Entidades::Entidade*>((*itCs))))
            {
                tratarColisaoChaoInimigo();
            }
    }
}

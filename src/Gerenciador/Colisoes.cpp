#include "Colisoes.h"
#include "../Entidades/Entidade.h"

#include "../Entidades/Personagem/Personagem.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Personagem/Inimigo.h"
// Projétil
// Obstáculo

#include "../organiza.h"

#include <cmath>
using std::abs;

using std::vector;
using std::set;
using std::list;

using sf::Vector2f;

GerenciadorColisoes::GerenciadorColisoes():LIs(),LOs(),LPs(),pJog1(NULL) {
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

GerenciadorColisoes::~GerenciadorColisoes() {
    pJog1 = NULL;
}

void GerenciadorColisoes::incluirInimigo(Inimigo* pi) {
    if(pi != NULL)
        LIs.push_back(pi);
}

void GerenciadorColisoes::incluirObstaculo(Obstaculo* po) {
    if(po != NULL)
        LOs.push_back(po);
}

void GerenciadorColisoes::incluirProjetil(Projetil* pj) {
    if(pj != NULL)
        LPs.insert(pj);
}

void GerenciadorColisoes::incluirChao(Chao* pc) {
    if(pc != NULL)
        LCs.push_back(pc);
}

const bool GerenciadorColisoes::verificarColisao(Entidade* p1, Entidade* p2) const
{
    if (p1 == NULL || p2 == NULL) {
        std::cerr << "Nulidade em GC::verificarColisao" << std::endl;
        return false;
    }

    // float dx = p1->getX() - p2->getX();
    // float dy = p1->getY() - p2->getY();

    Vector2f pos1 = p1->getPosicao();
    Vector2f pos2 = p2->getPosicao();

    float dx = pos1.x - pos2.x;
    float dy = pos1.y - pos2.y;
    dx = abs(dx);
    dy = abs(dy);
    // As linhas a seguir supõem que x e y são do centro, pois retângulos diferentes têm
    // suas pontas sups. esqs. a uma distância diferente do que da dos seus centros.
    float internox = dx - (p1->getX() + p2->getX())/2;
    float internoy = dy - (p1->getY() + p2->getY())/2;
    return (internox < 0.0f && internoy < 0.0f);
}

void GerenciadorColisoes::tratarColisaoJogsInimigo() {

}

void GerenciadorColisoes::tratarColisaoJogsObstaculo() {

}

void GerenciadorColisoes::tratarColisaoJogsProjetil() {

}

void GerenciadorColisoes::tratarColisaoJogsChao() {

}

void GerenciadorColisoes::executar()
{
    vector<Inimigo*>::iterator itIs;
    list<Obstaculo*>::iterator itOs;
    set<Projetil*>::iterator itPs;

    for (itIs = LIs.begin(); itIs != LIs.end(); itIs++) {
        if (verificarColisao(
                static_cast<Entidade*>(static_cast<Personagem*>(pJog1)),
                static_cast<Entidade*>(static_cast<Personagem*>(*itIs))))
        {
            tratarColisaoJogsInimigo();
        }
    }
}

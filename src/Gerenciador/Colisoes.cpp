#include "Colisoes.h"
#include "../Entidades/Entidade.h"

#include "../Entidades/Personagem/Personagem.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Personagem/Inimigo.h"
// Projétil
// Obstáculo

#include "../organiza.h"

using std::vector;
using std::set;
using std::list;

GerenciadorColisoes::GerenciadorColisoes():LIs(),LOs(),LPs(),pJog1(NULL){
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

GerenciadorColisoes::~GerenciadorColisoes(){
    pJog1 = NULL;
}

void GerenciadorColisoes::incluirInimigo(Inimigo* pi){
    if(pi != NULL)
        LIs.push_back(pi);
}

void GerenciadorColisoes::incluirObstaculo(Obstaculo* po){
    if(po != NULL)
        LOs.push_back(po);
}

void GerenciadorColisoes::incluirProjetil(Projetil* pj){
    if(pj != NULL)
        LPs.insert(pj);
}

const bool GerenciadorColisoes::verificarColisao(Entidade* p1, Entidade* p2) const
{
    if (p1 == NULL || p2 == NULL) {
        std::cerr << "Nulidade em GC::verificarColisao" << std::endl;
        return false;
    }
    float dx = p1->getCoord().x - p2->getCoord().x;
    float dy = p1->getCoord().y - p2->getCoord().y;
    dx = abs(dx); // if (dx < 0) dx *= -1.f;
    dy = abs(dy);
    // Se getCoord() de Entidade retornará coordenadas do centro,
    // as 2 linhas a seguir são desnecessárias
    //float interx = abs(dx)-(getFig()->getGlobalBounds().width/2 + pIn->getFig()->getGlobalBounds().width/2) ;
    //float intery = abs(dy)-(getFig()->getGlobalBounds().height/2 + pIn->getFig()->getGlobalBounds().height/2);
    // O código a seguir supõe que getCoord é do centro, pois retângulos diferentes têm
    // suas pontas sup. esq. a uma distância diferente do que da dos seus centros.
    float internox = dx - (p1->getTamanho().x + p2->getTamanho().x)/2;
    float internoy = dy - (p1->getTamanho().y + p2->getTamanho().y)/2;

    return (internox < 0.0f && internoy < 0.0f);
}

void GerenciadorColisoes::tratarColisaoJogsInimigo(){

}

void GerenciadorColisoes::tratarColisaoJogsObstaculo(){

}

void GerenciadorColisoes::tratarColisaoJogsProjetil(){

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

#include "Colisoes.h"
#include "../Entidades/Entidade.h"

#include "../Entidades/Personagem/Personagem.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Personagem/Inimigo.h"
#include "../Entidades/Personagem/AranhaGigante.h"
#include "../Entidades/Chao.h"
#include "../Entidades/Projetil.h"
#include "../Entidades/Obstaculo/Obstaculo.h"
#include "../Entidades/Obstaculo/Plataforma.h"

#include "../organiza.h"

#include"organiza.h"
using std::abs;

using std::vector;
using std::set;
using std::list;

using sf::Vector2f;

CMD::Gerenciador::Colisoes::Colisoes():
    pJog1(NULL),
    pJog2(NULL),
    LIs(),
    LOs(),
    LPs(),
    LCs()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
    LCs.clear();
}

CMD::Gerenciador::Colisoes::~Colisoes() {
    LIs.clear();
    LOs.clear();
    LPs.clear();
    LCs.clear();

}

void CMD::Gerenciador::Colisoes::incluirJogador1(Entidades::Personagens::Jogador* jogador){
    if(jogador != NULL)
        pJog1 = jogador;
}
void CMD::Gerenciador::Colisoes::incluirJogador2(Entidades::Personagens::Jogador* jogador){
    if(jogador != NULL)
        pJog2 = jogador;
}
void CMD::Gerenciador::Colisoes::removerInimigo(
    Entidades::Personagens::Inimigo* inimigo) {
    LIs.erase(std::remove(LIs.begin(), LIs.end(), inimigo), LIs.end());
}

bool CMD::Gerenciador::Colisoes::todosJogadoresMortos() const {
    bool temJogador = false;
    if (pJog1 != NULL) {
        temJogador = true;
        if (pJog1->getNumVida() > 0)
            return false;
    }
    if (pJog2 != NULL) {
        temJogador = true;
        if (pJog2->getNumVida() > 0)
            return false;
    }
    return temJogador;
}

bool CMD::Gerenciador::Colisoes::todosInimigosMortos() const {
    for (std::vector<Entidades::Personagens::Inimigo*>::const_iterator it = LIs.begin();
         it != LIs.end(); ++it) {
        if (*it != NULL && (*it)->getNumVida() > 0)
            return false;
    }
    return true;
}

void CMD::Gerenciador::Colisoes::incluirInimigo(Entidades::Personagens::Inimigo* pi) {
    if(pi != NULL)
        LIs.push_back(pi);
}

void CMD::Gerenciador::Colisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* po) {
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

    float dx = pos1.x - pos2.x;
    float dy = pos1.y - pos2.y;

    // As linhas a seguir supõem que x e y são do centro, pois retângulos diferentes têm
    // suas pontas sups. esqs. a uma distância diferente do que da dos seus centros.
    float internox = abs(dx) - (p1->getLargura() + p2->getLargura())/2;
    float internoy = abs(dy) - (p1->getAltura() + p2->getAltura())/2;

    return (internox < 0.0f && internoy < 0.0f);
}

void CMD::Gerenciador::Colisoes::tratarColisaoJogsInimigo() {
    if (LIs.empty()) {
        std::cout << "tentativa de acessar vetor de inimigo vazio" << std::endl;
        return;
    }
    if (pJog1 != NULL)
        pJog1->colidir(*itIs);
    if (pJog2 != NULL)
        pJog2->colidir(*itIs);
}

void CMD::Gerenciador::Colisoes::tratarColisaoJogsObstaculo() {
    if (LOs.empty()) {
        std::cout << "tentativa de acessar lista de objetos vazia" << std::endl;
        return;
    }
    if (pJog1 != NULL )
        (*itOs)->obstaculizar(pJog1);
    if (pJog2 != NULL)
        (*itOs)->obstaculizar(pJog2);
}

void CMD::Gerenciador::Colisoes::tratarColisaoJogsProjetil() {
    if (LPs.empty())
        return;
    if(pJog1 != NULL)
        (*itPs)->perfurar(pJog1);
    if(pJog2 != NULL)
        (*itPs)->perfurar(pJog2);
}


void CMD::Gerenciador::Colisoes::tratarColisaoJogsChao(
    Entidades::Personagens::Jogador* jogador) {
    if (LCs.empty()) {
        std::cout << "tentativa de acessar lista de chao vazia" << std::endl;
        return;
    }

    if (jogador != NULL)
        (*itCs)->impedirQuedaPSG(jogador);
}

void CMD::Gerenciador::Colisoes::tratarColisaoInimigoChao(){
    if(LCs.empty() || LIs.empty()){
        std::cout << "tentativa de acessar lista de chao ou vetor de inimigo vazio" << std::endl;
        return;
    }
    (*itCs)->impedirQuedaPSG(*itIs);
}

void CMD::Gerenciador::Colisoes::tratarColisaoObstaculoChao(){
    if (LCs.empty() || LOs.empty())
        return;

    (*itCs)->impedirQuedaOBS(*itOs);
}

void CMD::Gerenciador::Colisoes::tratarColisaoProjetilChao(){
    if (LCs.empty() || LPs.empty())
        return;
    (*itPs)->desativar();
}

void CMD::Gerenciador::Colisoes::executar()
{
        if (pJog1 != NULL && pJog1->getNumVida() > 0)
            pJog1->setEstaNoChao(false);
       if (pJog2 != NULL && pJog2->getNumVida() > 0)
            pJog2->setEstaNoChao(false); 
    
    colisaoJogsInimigo();
    colisaoJogsObstaculo();
    colisaoJogsProjetil();
    colisaoJogsChao();
    colisaoObstaculoChao();
    colisaoProjetilChao();
    colisaoAranhaPlataforma();
    colisaoChaoInimigo();
}

void CMD::Gerenciador::Colisoes::colisaoJogsInimigo(){
        for (itIs = LIs.begin(); itIs != LIs.end(); itIs++) {
            if (*itIs == NULL || (*itIs)->getNumVida() <= 0)
                continue;
            if (pJog1 != NULL && pJog1->getNumVida() > 0
                && verificarColisao(pJog1, *itIs))
                tratarColisaoJogsInimigo();
            if ((*itIs)->getNumVida() > 0
                && pJog2 != NULL && pJog2->getNumVida() > 0
                && verificarColisao(pJog2, *itIs))
                tratarColisaoJogsInimigo();
        }
}

void CMD::Gerenciador::Colisoes::colisaoJogsChao(){
        for (itCs = LCs.begin(); itCs != LCs.end(); itCs++) {
            if (pJog1 != NULL && pJog1->getNumVida() > 0
                && verificarColisao(pJog1, *itCs))
                tratarColisaoJogsChao(pJog1);
            if (pJog2 != NULL && pJog2->getNumVida() > 0
                && verificarColisao(pJog2, *itCs))
                tratarColisaoJogsChao(pJog2);
        }
}

void CMD::Gerenciador::Colisoes::colisaoJogsObstaculo(){
    for (itOs = LOs.begin(); itOs != LOs.end(); ++itOs) {
        if (pJog1 != NULL && pJog1->getNumVida() > 0 && verificarColisao(pJog1, *itOs)) {
            (*itOs)->obstaculizar(pJog1);
        }
        if (pJog2 != NULL && pJog2->getNumVida() > 0 && verificarColisao(pJog2, *itOs)) {
            (*itOs)->obstaculizar(pJog2);
        }
    }
}

void CMD::Gerenciador::Colisoes::colisaoJogsProjetil(){
    for (itPs = LPs.begin(); itPs != LPs.end(); ++itPs) {
        if (!(*itPs)->estaAtivo())
            continue;
        if (pJog1 != NULL && pJog1->getNumVida() > 0
            && verificarColisao(pJog1, *itPs)) {
            tratarColisaoJogsProjetil();
        }
        if ((*itPs)->estaAtivo() && pJog2 != NULL && pJog2->getNumVida() > 0
            && verificarColisao(pJog2, *itPs)) {
            tratarColisaoJogsProjetil();
        }
    }
}

void CMD::Gerenciador::Colisoes::colisaoObstaculoChao(){
    for (itOs = LOs.begin(); itOs != LOs.end(); ++itOs) {
        for (itCs = LCs.begin(); itCs != LCs.end(); ++itCs) {
            if (verificarColisao(*itOs, *itCs))
                tratarColisaoObstaculoChao();
        }
    }
}

void CMD::Gerenciador::Colisoes::colisaoProjetilChao(){
    for (itPs = LPs.begin(); itPs != LPs.end(); ++itPs) {
        for (itCs = LCs.begin(); itCs != LCs.end(); ++itCs) {
            if ((*itPs)->estaAtivo() && verificarColisao(*itPs, *itCs))
                tratarColisaoProjetilChao();
        }
    }
}

void CMD::Gerenciador::Colisoes::colisaoAranhaPlataforma(){
    for (itIs = LIs.begin(); itIs != LIs.end(); ++itIs) {
        Entidades::Personagens::AranhaGigante* aranha =
            dynamic_cast<Entidades::Personagens::AranhaGigante*>(*itIs);//precisa ser dinamico
        if (aranha == NULL || aranha->getNumVida() <= 0)
            continue;

        bool apoiada = false;
        for (itOs = LOs.begin(); itOs != LOs.end(); ++itOs) {
            Entidades::Obstaculos::Plataforma* plataforma =
                dynamic_cast<Entidades::Obstaculos::Plataforma*>(*itOs);
            if (plataforma != NULL && aranha->colidirPlataforma(plataforma)) {
                apoiada = true;
                break;
            }
        }
        if (!apoiada)
            aranha->perderPlataforma();
    }
}

void CMD::Gerenciador::Colisoes::colisaoChaoInimigo(){
    for (itCs = LCs.begin(); itCs != LCs.end(); itCs++) {
        for (itIs = LIs.begin(); itIs != LIs.end(); itIs++)
            if ((*itIs)->getNumVida() > 0 && verificarColisao(
                    static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(*itIs)),
                    static_cast<Entidades::Entidade*>((*itCs))))
            {
                tratarColisaoInimigoChao();
            }
    }
}
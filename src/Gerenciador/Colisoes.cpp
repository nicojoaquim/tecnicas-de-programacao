#include "Colisoes.h"

using namespace std;

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
const bool GerenciadorColisoes::verificarColisao(Entidade* p1, Entidade* p2){
    return false;
}
void GerenciadorColisoes::tratarColisaoJogsInimigo(){

}
void GerenciadorColisoes::tratarColisaoJogsObstaculo(){

}
void GerenciadorColisoes::tratarColisaoJogsProjetil(){

}
void executar(){

}

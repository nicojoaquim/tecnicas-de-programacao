#include"Colisoes.h"
using namespace std;
Gerenciador_Colisoes::Gerenciador_Colisoes():LIs(),LOs(),LPs(),pJog1(NULL){
    LIs.clear();
    LOs.clear();
    LPs.clear();
}
Gerenciador_Colisoes::~Gerenciador_Colisoes(){
    pJog1 = NULL;
}
void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi){
    if(pi != NULL)
        LIs.push_back(pi);
}
void Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po){
    if(po != NULL)
        LOs.push_back(po);
}
void Gerenciador_Colisoes::incluirProjetil(Projetil* pj){
    if(pj != NULL)
        LPs.insert(pj);
}
const bool Gerenciador_Colisoes::verificarColisao(Entidade* p1, Entidade* p2){
    return false;
}
void Gerenciador_Colisoes::tratarColisaoJogsInimigo(){

}
void Gerenciador_Colisoes::tratarColisaoJogsObstaculo(){

}
void Gerenciador_Colisoes::tratarColisaoJogsProjetil(){

}
void executar(){

}
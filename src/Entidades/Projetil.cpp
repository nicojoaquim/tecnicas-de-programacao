#include"Projetil.h"
trabalhoJogo::Entidades::Projetil::Projetil():Entidade(),v({0,0}),ativo(false){

}
trabalhoJogo::Entidades::Projetil::~Projetil(){

}
const sf::Vector2f trabalhoJogo::Entidades::Projetil::getV() const{
    return v;
}
void trabalhoJogo::Entidades::Projetil::setV(const sf::Vector2f velocidade){
    v = velocidade;
}
void trabalhoJogo::Entidades::Projetil::executar(){

}
void trabalhoJogo::Entidades::Projetil::salvar(){
    
}

void trabalhoJogo::Entidades::Projetil::gravitar(const float dt) {}

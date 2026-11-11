#include"Projetil.h"
Projetil::Projetil():Entidade(),v({0,0}),ativo(false){

}
Projetil::~Projetil(){

}
const sf::Vector2f Projetil::getV() const{
    return v;
}
void Projetil::setV(const sf::Vector2f velocidade){
    v = velocidade;
}
void Projetil::executar(){

}
void Projetil::salvar(){
    
}

void Projetil::gravitar(const float dt) {}

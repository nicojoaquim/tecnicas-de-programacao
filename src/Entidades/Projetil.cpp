#include"Projetil.h"
CMD::Entidades::Projetil::Projetil():Entidade(),v({0,0}),ativo(false){

}
CMD::Entidades::Projetil::~Projetil(){

}
const sf::Vector2f CMD::Entidades::Projetil::getV() const{
    return v;
}
void CMD::Entidades::Projetil::setV(const sf::Vector2f velocidade){
    v = velocidade;
}
void CMD::Entidades::Projetil::executar(){

}
void CMD::Entidades::Projetil::salvar(){

}

void CMD::Entidades::Projetil::gravitar(const float dt) {}

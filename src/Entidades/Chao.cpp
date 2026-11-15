#include"Chao.h"
#include<SFML/Window.hpp>
trabalhoJogo::Entidades::Chao::Chao():largura(0),altura(0){

}
trabalhoJogo::Entidades::Chao::~Chao(){

}
void trabalhoJogo::Entidades::Chao::inicializaChao(sf::Sprite* chao){
    if(chao == NULL){
        std::cerr << "nulidade em inicializar chao" << std::endl;
        return;
    }
    atribuirSprite(chao);
    tamanhoChao();
}
void trabalhoJogo::Entidades::Chao::tamanhoChao(){
    if(pFig == NULL){
        std::cerr << "nulidade em tamanho chao" << std::endl;
        return;
    }
    largura = sf::VideoMode::getDesktopMode().width/getLargura();
    altura = sf::VideoMode::getDesktopMode().height/getAltura();
    pFig->setScale({largura,altura});
}
void trabalhoJogo::Entidades::Chao::executar(){

}
void trabalhoJogo::Entidades::Chao::salvar(){

}
void trabalhoJogo::Entidades::Chao::mover(){
    
}
void trabalhoJogo::Entidades::Chao::gravitar(const float dt){
    
}

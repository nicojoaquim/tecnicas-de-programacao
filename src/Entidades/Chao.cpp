#include"Chao.h"
#include<SFML/Window.hpp>
CMD::Entidades::Chao::Chao():largura(0),altura(0){

}
CMD::Entidades::Chao::~Chao(){

}
void CMD::Entidades::Chao::inicializaChao(sf::Sprite* chao){
    if(chao == NULL){
        std::cerr << "nulidade em inicializar chao" << std::endl;
        return;
    }
    atribuirSprite(chao);
    tamanhoChao();
}
void CMD::Entidades::Chao::tamanhoChao(){
    if(pFig == NULL){
        std::cerr << "nulidade em tamanho chao" << std::endl;
        return;
    }
    largura = sf::VideoMode::getDesktopMode().width/getLargura();
    altura = sf::VideoMode::getDesktopMode().height/getAltura();
    pFig->setScale({largura,altura});
}
void CMD::Entidades::Chao::executar(){

}
void CMD::Entidades::Chao::salvar(){

}

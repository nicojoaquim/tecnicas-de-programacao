#include"Chao.h"
#include<SFML/Window.hpp>
Chao::Chao():altura(0),largura(0){

}
Chao::~Chao(){

}
void Chao::inicializaChao(sf::Sprite* chao){
    if(chao == NULL){
        std::cerr << "nulidade em inicializar chao" << std::endl;
        return;
    }
    atribuirSprite(chao);
    tamanhoChao();
}
void Chao::tamanhoChao(){
    if(pFig == NULL){
        std::cerr << "nulidade em tamanho chao" << std::endl;
        return;
    }
    largura = sf::VideoMode::getDesktopMode().width/getLargura();
    altura = sf::VideoMode::getDesktopMode().height/getAltura();
    pFig->setScale({largura,altura});
}
void Chao::executar(){

}
void Chao::salvar(){

}
void Chao::gravitar(){
    
}
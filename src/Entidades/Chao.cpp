#include"Chao.h"
#include<SFML/Window.hpp>
#include"Personagem/Personagem.h"
#include<algorithm>
#include<cmath>
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
    const sf::Texture* textura = pFig->getTexture();
    if(textura == NULL){
        std::cerr << "textura inexistente em tamanho chao" << std::endl;
        return;
    }

    const sf::VideoMode modoVideo = sf::VideoMode::getDesktopMode();
    const sf::Vector2u tamanhoJanela(modoVideo.width, modoVideo.height);
    const sf::Vector2u tamanhoTile = textura->getSize();
    if(tamanhoJanela.x == 0 || tamanhoJanela.y == 0
        || tamanhoTile.x == 0 || tamanhoTile.y == 0){
        std::cerr << "dimensao invalida em tamanho chao" << std::endl;
        return;
    }

    const float tamanhoTileTela = std::min(
        tamanhoJanela.x / 80.f,
        tamanhoJanela.y / 45.f
    );
    const int quantidadeTiles = static_cast<int>(
        std::ceil(tamanhoJanela.x / tamanhoTileTela)
    );
    const int quantidadeLinhas = 10;
    pFig->setTextureRect(sf::IntRect( 0, 0,
        quantidadeTiles * static_cast<int>(tamanhoTile.x),
        quantidadeLinhas * static_cast<int>(tamanhoTile.y)));

    const sf::FloatRect area = pFig->getLocalBounds();
    pFig->setOrigin(area.width / 2.f, area.height / 2.f);
    largura = tamanhoTileTela / static_cast<float>(tamanhoTile.x);
    altura = tamanhoTileTela / static_cast<float>(tamanhoTile.y);
    pFig->setScale(largura, altura);
}
void CMD::Entidades::Chao::executar(){

}
void CMD::Entidades::Chao::salvar(){

}
void CMD::Entidades::Chao::impedirQuedaPSG(Personagens::Personagem* pP){
    if(pP == NULL){
        std::cerr << "Entidade nula querendo atravessar o chao" << std::endl;
        return;
    }

    float dx = getX() - pP->getX();
    float dy = getY() - pP->getY();
    float interx = std::abs(dx) - (pP->getLargura()/2 + getLargura()/2) ;
    float intery = std::abs(dy) - (pP->getAltura()/2 + getAltura()/2);
    if(interx > intery) {
        if (dx > 0)
            pP->setPosicao({pP->getX()+interx,pP->getY()});
        else
            pP->setPosicao({pP->getX()-interx,pP->getY()});
    }
    else {
        if (dy > 0) {
            pP->setPosicao({
                pP->getX(),
                getY() - (getAltura() + pP->getAltura())/2.f
            });
            pP->setVy(0);
            pP->setEstaNoChao(true);
        }
        else {
            pP->setPosicao({
                pP->getX(),
                getY() + (getAltura() + pP->getAltura())/2.f
            });
            pP->setVy(0);
            pP->setEstaNoChao(false);
        }
    }
}
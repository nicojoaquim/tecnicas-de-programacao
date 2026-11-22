#include "Chao.h"
#include "Personagem/Personagem.h"
#include "Obstaculo/Obstaculo.h"
#include "Projetil.h"
#include <SFML/Window.hpp>
#include "../organiza.h"

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

    const float dx = pP->getX() - getX();
    const float dy = pP->getY() - getY();
    const float interx =
        (pP->getLargura() + getLargura()) / 2.f - std::abs(dx);
    const float intery =
        (pP->getAltura() + getAltura()) / 2.f - std::abs(dy);
    if (interx <= 0.f || intery <= 0.f)
        return;

    if (interx < intery) {
        if (dx < 0.f)
            pP->setPosicao({ pP->getX() - interx, pP->getY() });
        else
            pP->setPosicao({ pP->getX() + interx, pP->getY() });
    } else {
        if (dy < 0.f) {
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
void CMD::Entidades::Chao::impedirQuedaOBS(Obstaculos::Obstaculo* pO){
    if(pO == NULL){
        std::cerr << "Entidade nula querendo atravessar o chao" << std::endl;
        return;
    }

    const float dx = pO->getX() - getX();
    const float dy = pO->getY() - getY();
    const float interx =
        (pO->getLargura() + getLargura()) / 2.f - std::abs(dx);
    const float intery =
        (pO->getAltura() + getAltura()) / 2.f - std::abs(dy);
    if (interx <= 0.f || intery <= 0.f)
        return;

    if (interx < intery) {
        if (dx < 0.f)
            pO->setPosicao({ pO->getX() - interx, pO->getY() });
        else
            pO->setPosicao({ pO->getX() + interx, pO->getY() });
    } else {
        if (dy < 0.f) {
            pO->setPosicao({
                pO->getX(),
                getY() - (getAltura() + pO->getAltura())/2.f
            });
            pO->setVy(0);
        }
        else {
            pO->setPosicao({
                pO->getX(),
                getY() + (getAltura() + pO->getAltura())/2.f
            });
            pO->setVy(0);
        }
    }
}
void CMD::Entidades::Chao::impedirQuedaPJT(Projetil* pPj){
    if(pPj == NULL){
        std::cerr << "Entidade nula querendo atravessar o chao" << std::endl;
        return;
    }

    const float dx = pPj->getX() - getX();
    const float dy = pPj->getY() - getY();
    const float interx =
        (pPj->getLargura() + getLargura()) / 2.f - std::abs(dx);
    const float intery =
        (pPj->getAltura() + getAltura()) / 2.f - std::abs(dy);
    if (interx <= 0.f || intery <= 0.f)
        return;

    if (interx < intery) {
        if (dx < 0.f)
            pPj->setPosicao({ pPj->getX() - interx, pPj->getY() });
        else
            pPj->setPosicao({ pPj->getX() + interx, pPj->getY() });
    } else {
        if (dy < 0.f) {
            pPj->setPosicao({
                pPj->getX(),
                getY() - (getAltura() + pPj->getAltura())/2.f
            });
            pPj->setVy(0);
        }
        else {
            pPj->setPosicao({
                pPj->getX(),
                getY() + (getAltura() + pPj->getAltura())/2.f
            });
            pPj->setVy(0);
        }
    }
}

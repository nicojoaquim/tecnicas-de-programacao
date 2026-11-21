#include "Chao.h"

#include "../Tilemap.h"
#include "../Gerenciador/Grafico.h"
#include<SFML/Window.hpp>

CMD::Entidades::Chao::Chao(Tile t = VAZIO):
    tipo(t),
    largura(0),
    altura(0)
{
    if (tipo != VAZIO) {
        sf::Sprite* pSprite = new sf::Sprite;
        pSprite->setTexture(getTex());
        atribuirSprite(pSprite);
    }
}

CMD::Entidades::Chao::~Chao() {
    if (tipo != VAZIO)
        delete getFig();
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

void CMD::Entidades::Chao::executar() {

}

void CMD::Entidades::Chao::salvar() {

}

const sf::Texture& CMD::Entidades::Chao::getTex() const {
    if (tipo >= RAM0 && tipo <= RAM11)
        return pGG->getTexAmbienteRAM(tipo - RAM0);

    if (tipo >= CPU0 && tipo <= CPU11)
        return pGG->getTexAmbienteCPU(tipo - CPU0);

    std::cerr << "Tipo de tile de chão inválido em Chao::getTex(): "
              << tipo << std::endl;
    return pGG->getTexPlataforma();

//    if (tipo == RAM0) return pGG->getTexAmbienteRAM(0);
//    else if (tipo == RAM1) return pGG->getTexAmbienteRAM(1);
//    else if (tipo == RAM2) return pGG->getTexAmbienteRAM(2);
//    else if (tipo == RAM3) return pGG->getTexAmbienteRAM(3);
//    else if (tipo == RAM4) return pGG->getTexAmbienteRAM(4);
//    else if (tipo == RAM5) return pGG->getTexAmbienteRAM(5);
//    else if (tipo == RAM6) return pGG->getTexAmbienteRAM(6);
//    else if (tipo == RAM7) return pGG->getTexAmbienteRAM(7);
//    else if (tipo == RAM8) return pGG->getTexAmbienteRAM(8);
//    else if (tipo == RAM9) return pGG->getTexAmbienteRAM(9);
//    else if (tipo == RAM10) return pGG->getTexAmbienteRAM(10);
//    else if (tipo == RAM11) return pGG->getTexAmbienteRAM(11);
//    else if (tipo == CPU0) return pGG->getTexAmbienteCPU(0);
//    else if (tipo == CPU1) return pGG->getTexAmbienteCPU(1);
//    else if (tipo == CPU2) return pGG->getTexAmbienteCPU(2);
//    else if (tipo == CPU3) return pGG->getTexAmbienteCPU(3);
//    else if (tipo == CPU4) return pGG->getTexAmbienteCPU(4);
//    else if (tipo == CPU5) return pGG->getTexAmbienteCPU(5);
//    else if (tipo == CPU6) return pGG->getTexAmbienteCPU(6);
//    else if (tipo == CPU7) return pGG->getTexAmbienteCPU(7);
//    else if (tipo == CPU8) return pGG->getTexAmbienteCPU(8);
//    else if (tipo == CPU9) return pGG->getTexAmbienteCPU(9);
//    else if (tipo == CPU10) return pGG->getTexAmbienteCPU(10);
//    else if (tipo == CPU11) return pGG->getTexAmbienteCPU(11);
}

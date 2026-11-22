#include"Abobora.h"
#include "../Personagem/Jogador.h"
CMD::Entidades::Obstaculos::Abobora::Abobora():
Obstaculo(),
largura(2){

}
CMD::Entidades::Obstaculos::Abobora::~Abobora(){

}
void CMD::Entidades::Obstaculos::Abobora::executar(){

}
void CMD::Entidades::Obstaculos::Abobora::obstaculizar(Personagens::Jogador* p){
    if (p== NULL) {
        std::cerr << "Jogador  nulo" << std::endl;
        return;
    }
    
    float dx = getX() - p->getX();
    float dy = getY() - p->getY();
    float interx = std::abs(dx) - (p->getLargura()/2 + getLargura()/2) ;
    float intery = std::abs(dy) - (p->getAltura()/2 + getAltura()/2);

    if(interx < 0.0f && intery < 0.0f)
    {
        if (interx > intery) {
        if (dx > 0)
            getFig()->setPosition(p->getX()+interx,p->getY());
        else
            getFig()->setPosition(p->getX()-interx,p->getY());
    }
    else {
        if(dy>0)
            getFig()->setPosition(p->getX(),p->getY()+intery);
        else
            getFig()->setPosition(p->getX(),p->getY()-intery);
    }
    }
}

void  CMD::Entidades::Obstaculos::Abobora::salvar(){

}
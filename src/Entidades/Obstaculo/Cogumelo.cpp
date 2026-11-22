#include "Cogumelo.h"
#include "../Personagem/Jogador.h"
CMD::Entidades::Obstaculos::Cogumelo::Cogumelo():
    Obstaculo(),
    densidade(-1)
{
}

CMD::Entidades::Obstaculos::Cogumelo::~Cogumelo()
{
}

void CMD::Entidades::Obstaculos::Cogumelo::executar()
{
}

void CMD::Entidades::Obstaculos::Cogumelo::obstaculizar(Personagens::Jogador *p)
{
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
void CMD::Entidades::Obstaculos::Cogumelo::salvar(){

}
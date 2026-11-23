#include "Abobora.h"
#include "../Personagem/Jogador.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Gerenciador/Tempo.h"
#include "../../organiza.h"

CMD::Entidades::Obstaculos::Abobora::Abobora():
    Obstaculo(),
    tempoCor(0.f),
    largura(2)
{
    sf::Sprite* pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexAbobora());
    atribuirSprite(pSprite);
}

CMD::Entidades::Obstaculos::Abobora::~Abobora() {
    if (getFig() != NULL)
        delete getFig();
}

void CMD::Entidades::Obstaculos::Abobora::executar(){
    gravitar();
    acao();
}
void CMD::Entidades::Obstaculos::Abobora::obstaculizar(Personagens::Jogador* p) {
    if (p == NULL) return;

    const float dx = p->getX() - getX();
    const float dy = p->getY() - getY();
    const float interx = (p->getLargura() + getLargura()) / 2.f - std::abs(dx);
    const float intery = (p->getAltura() + getAltura()) / 2.f - std::abs(dy);

    if (interx > 0.f && intery > 0.f) {
        p->setPegajoso(true);
    }
}

void  CMD::Entidades::Obstaculos::Abobora::salvar(){

}
void CMD::Entidades::Obstaculos::Abobora::acao() {
    float dt = Gerenciador::Tempo::getSegundos();
    tempoCor += dt;

    // Fica mudando de cor que nem um seno
    float intensidade = (std::sin(tempoCor * 3.0f) + 1.0f) * 127.5f;

    if (getFig() != NULL) {
        // Escolhi o vermelho porque achei mais com cara de malefico
        getFig()->setColor(sf::Color(255, static_cast<sf::Uint8>(intensidade), 0));
    }
}

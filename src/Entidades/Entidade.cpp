#include "Entidade.h"

#include "../organiza.h"

using sf::Vector2f;
using sf::Sprite;
/*
Entidade::Entidade(bool gravidade):
    buffer(std::cout),
    sofre_gravidade(gravidade)
{
}*/

CMD::Entidades::Entidade::Entidade():
    buffer(std::cout),
    dinamico(false)
{
}

CMD::Entidades::Entidade::~Entidade()
{
}

void CMD::Entidades::Entidade::atribuirSprite(Sprite* Fig) {
    if (Fig == NULL) {
        std::cerr << "Nulidade em atribuirSprite" << std::endl;
        return;
    }
    setFig(Fig);

    Vector2f centro(getLargura()/2.0f, getAltura()/2.0f);

    pFig->setOrigin(centro.x, centro.y);
    setPosicao(getPosicao()+centro);
}

void CMD::Entidades::Entidade::salvarDataBuffer(){
    buffer << getX() << " " << getY();
}
/*
const bool Entidade::sofreGravidade() const {
    return sofre_gravidade;
}
*/
const Vector2f CMD::Entidades::Entidade::getPosicao() const {
    if (pFig != NULL)
        return pFig->getPosition();
    else {
        std::cerr << "Erro: Figura inexistente em getPosicao" << std::endl;
        return INEXISTENTE;
    }
}

const float CMD::Entidades::Entidade::getX() const {
    return Entidade::getPosicao().x;
}

const float CMD::Entidades::Entidade::getY() const {
    return Entidade::getPosicao().y;
}

void CMD::Entidades::Entidade::setPosicao(const Vector2f posicao) {
    if (pFig != NULL)
        pFig->setPosition(posicao);
}

void CMD::Entidades::Entidade::setPosicaoEsper(const Vector2f posicao){
    Vector2f centro(getLargura(),getAltura());
    if (pFig != NULL)
        pFig->setPosition(posicao + centro/2.f);
}

const Vector2f CMD::Entidades::Entidade::getTamanho() const {
    if (pFig != NULL)
        // TODO ver se getSize() == getGlobalBounds().width e .height
        // Estava em atribuirSprite:
        // sf::FloatRect cent = pFig->getGlobalBounds();
        // pFig->setOrigin(cent.width/2.0f,cent.height/2.0f);
        return pFig->getGlobalBounds().getSize();
    else {
        std::cerr << "Erro: Figura inexistente em getTamanho" << std::endl;
        return INEXISTENTE;
    }
}

const float CMD::Entidades::Entidade::getLargura() const {
    return getTamanho().x;
}

const float CMD::Entidades::Entidade::getAltura() const {
    return getTamanho().y;
}
void CMD::Entidades::Entidade::setDinamico(bool dim){
    dinamico = dim;
}
const bool CMD::Entidades::Entidade::getDinamico() const{
    return dinamico;
}
// Pode colocar sobrecarga de operador aqui para mudar posição da entidade
// Entidade e;
// e.setPosicao(Vector2f(1.f, 2.f));
// e += Vector2f(2.f, 3.f);
// e.getPosicao(); // (3., 5.)

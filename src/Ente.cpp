#include "Ente.h"
#include "Gerenciador/Grafico.h"
#include "organiza.h"
using sf::Sprite;
GerenciadorGrafico* Ente::pGG(NULL);

Ente::Ente():id(0)
{
    pFig = NULL;
}
Ente::~Ente()
{
    pFig = NULL;
}
void Ente::inicializaPosicao(float x, float y)
{
    if(pFig != NULL)
        pFig->setPosition({x,y});
}
void Ente::desenhar(sf::Sprite* Fig, float x, float y){
    if(Fig == NULL){
        std::cerr << "Nulidade em desenhar" << std::endl;
        return;
    }
    setFig(Fig);
    centralizar(Fig);
    inicializaPosicao(x + Fig->getLocalBounds().width/2.0f,y+ Fig->getLocalBounds().height/2.0f);
}
void Ente::centralizar(sf::Sprite* Fig){
    if(Fig == NULL){
        std::cerr << "Nulidade em centraliza" << std::endl;
        return;
    }
    sf::FloatRect cent = Fig->getLocalBounds();
    Fig->setOrigin(cent.width/2.0f,cent.height/2.0f);
} 
void Ente::setGG(GerenciadorGrafico* pG)
{
    pGG = pG;
}
void Ente::setFig(Sprite * Fig)
{
    pFig = Fig;
}
Sprite * Ente::getFig()
{
    return pFig;
}
void Ente::setId(int idO)
{
    id = idO;
}
int Ente::getId()
{
    return id;
}

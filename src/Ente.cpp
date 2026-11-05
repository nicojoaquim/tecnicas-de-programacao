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

void Ente::setGG(GerenciadorGrafico* pG)
{
    pGG = pG;
}
void Ente::setFig(Sprite * Fig)
{
    pFig = Fig;
    // pFig->setOrigin(...);
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

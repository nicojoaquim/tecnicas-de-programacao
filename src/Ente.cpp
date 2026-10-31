#include "Ente.h"
#include "Gerenciador/Grafico.h"
#include "organiza.h"

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
void Ente::desenhar()
{

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

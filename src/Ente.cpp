#include "Ente.h"
#include"organiza.h"
#include "Gerenciador/Grafico.h"
Gerenciador_Grafico* Ente::pGG(NULL);
Ente::Ente():id(0)
{
    pFig = NULL;
}
Ente::~Ente()
{
    pFig = NULL;
}
void Ente::inicializaPosicao(float x, float y){
     if(pFig != NULL)
        pFig->setPosition({x,y});
}
void Ente::desenhar()
{
        
}
 void Ente::setGG(Gerenciador_Grafico* pG)
{
    pGG = pG;
}
void Ente::setFig(RectangleShape * Fig){
    pFig = Fig;
}
RectangleShape * Ente::getFig(){
    return pFig;
}
void Ente::setId(int idO){
    id = idO;
}
int Ente::getId(){
    return id;
}
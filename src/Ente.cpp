#include "Ente.h"
int Ente::cont_id(0);
Gerenciador_Grafico* Ente::pGG(NULL);
Ente::Ente():id(cont_id++)
{
    pFig = NULL;
}
Ente::~Ente()
{
    pFig = NULL;
}
void Ente::desenhar()
{
    //if(pGG != NULL)
        //pGG->desenharEnte(this);
}
 void Ente::setGG(Gerenciador_Grafico* pG)
{
    pGG = pG;
}
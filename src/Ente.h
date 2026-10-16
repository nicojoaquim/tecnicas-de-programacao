#pragma once
#include "Gerenciador/Grafico.h"
class Figura;
class Ente
{
protected:
    int id;
    static int cont_id;
    static Gerenciador_Grafico* pGG;
    Figura* pFig;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    static void setGG(Gerenciador_Grafico* pG);
};

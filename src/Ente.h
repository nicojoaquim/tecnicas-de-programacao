#pragma once

#include "Gerenciador/Gráfico.h"

class Ente
{
protected:
    int id;
    static int cont_id;
    static Gerenciador_Grafico* pGG;
    ;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar;
    static void setGG(Gerenciador_Grafico* pG);
    ;
};

int Ente::cont_id(0);

#pragma once
#include <SFML/Graphics.hpp>
using sf:: RectangleShape;
#include "organiza.h"
class Gerenciador_Grafico;
class Ente
{
protected:
    int id;
    static Gerenciador_Grafico* pGG;
    RectangleShape * pFig;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void inicializaPosicao(float x, float y);
    virtual void desenhar();
    static void setGG(Gerenciador_Grafico* pG);
    void setFig(RectangleShape * Fig);
    RectangleShape* getFig();
    void setId(int idO);
    int getId();
};

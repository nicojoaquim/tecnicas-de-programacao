#include "Ente.h"
#include "Gerenciador/Grafico.h"
#include "organiza.h"

using sf::Sprite;

using std::cerr;
using std::endl;

GerenciadorGrafico* Ente::pGG(NULL);

Ente::Ente():id(0)
{
    pFig = NULL;
}
Ente::~Ente()
{
    pFig = NULL;
}

void Ente::desenhar() {
    if (pGG == NULL) {
        cerr << "Erro: tentativa de desenhar ente com GG nulo" << endl;
        return;
    }
    if (pFig == NULL) {
        cerr << "Erro: tentativa de desenhar ente com Sprite nulo" << endl;
        return;
    }
    pGG->desenharEnte(static_cast<Ente*>(this));
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

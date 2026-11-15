#include "Ente.h"
#include "Gerenciador/Grafico.h"
#include "organiza.h"

using sf::Sprite;

using std::cerr;
using std::endl;
trabalhoJogo::Gerenciador::GerenciadorGrafico* trabalhoJogo::Ente::pGG(NULL);

trabalhoJogo::Ente::Ente():id(0)
{
    pFig = NULL;
}
trabalhoJogo::Ente::~Ente()
{
    pFig = NULL;
}

void trabalhoJogo::Ente::desenhar() {
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

void trabalhoJogo::Ente::setGG(trabalhoJogo::Gerenciador::GerenciadorGrafico* pG)
{
    pGG = pG;
}
void trabalhoJogo::Ente::setFig(Sprite * Fig)
{
    pFig = Fig;
    // pFig->setOrigin(...);
}
Sprite * trabalhoJogo::Ente::getFig()
{
    return pFig;
}
void trabalhoJogo::Ente::setId(int idO)
{
    id = idO;
}
int trabalhoJogo::Ente::getId()
{
    return id;
}

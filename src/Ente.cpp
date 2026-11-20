#include "Ente.h"
#include "Gerenciador/Grafico.h"
// #include "Gerenciador/Tempo.h"
#include "organiza.h"

using sf::Sprite;

using std::cerr;
using std::endl;
CMD::Gerenciador::Grafico* CMD::Ente::pGG(NULL);

CMD::Ente::Ente():
    id(0),
    pGT()
{
    pFig = NULL;
}

CMD::Ente::~Ente()
{
    pFig = NULL;
}

void CMD::Ente::desenhar() {
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

void CMD::Ente::setGG(CMD::Gerenciador::Grafico* pG)
{
    pGG = pG;
}
void CMD::Ente::setFig(Sprite * Fig)
{
    pFig = Fig;
    // pFig->setOrigin(...);
}
Sprite * CMD::Ente::getFig()
{
    return pFig;
}
void CMD::Ente::setId(int idO)
{
    id = idO;
}
int CMD::Ente::getId()
{
    return id;
}

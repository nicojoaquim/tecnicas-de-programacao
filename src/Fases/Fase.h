#include "../Ente.h"
#include "../Listas/lista_entidade.h"
#include "../Gerenciador/Colisoes.h"

class Fase:public Ente{
protected:
    Lista_Entidade lista_ents;
    GerenciadorColisoes GC;
public:
    Fase();
    ~Fase();
    virtual void execuar();
    virtual void executar();
protected:
    void criarInimigFaceis();//mudar nome depois
    void criarInimigMedio();//mudar nome depois
    void criarChefe();//mudar nome depois
    void criarPlataforma();//mudar nome depois
    void criarObstMedio();//mudar nome depois
    void criarObstDificil();//mudar nome depois
    virtual void criarInimigos() = 0;
    virtual void criarObsr() = 0;
    void criarCenarios();
};

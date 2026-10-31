#include "../Entidade.h"

class Personagem:public Entidade
{
private:
    int num_vida;
public:
    Personagem();
    ~Personagem();
    void salvardataBuffer();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void mover() = 0;
};


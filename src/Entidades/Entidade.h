#include "../Ente.h"

class Entidade:public Ente
{
private:
protected:
    int x;
    int y;
    ostream &  buffer;
public:
    Entidade();
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;
protected:
    void salvardataBuffer();
};



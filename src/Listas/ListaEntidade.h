#pragma once

#include"lista.h"

class Entidade;
class ListaEntidade {
private:
    Lista<Entidade> LEs;
public:
    ListaEntidade();
    ~ListaEntidade();
    void incluir(Entidade* pE);
    void percorrer();
    void executar(); // TODO implementar
};

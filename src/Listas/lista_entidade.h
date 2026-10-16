#pragma once
#include"lista.h"
class Entidade;
class Lista_Entidade{
    private:
        Lista<Entidade> LEs;
    public:
    Lista_Entidade();
    ~Lista_Entidade();
    void incluir(Entidade* pE);
    void percorre();
};
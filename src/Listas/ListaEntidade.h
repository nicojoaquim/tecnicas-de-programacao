#pragma once

#include"lista.h"

namespace CMD
{
    namespace Entidades
    {
        class Entidade;
    }

    namespace Listas
    {
        class ListaEntidade {
        private:
            Lista<Entidades::Entidade> LEs;
        public:
            ListaEntidade();
            ~ListaEntidade();
            Lista<Entidades::Entidade>::Iterador inicio();
            Lista<Entidades::Entidade>::Iterador fim();
            void incluir(Entidades::Entidade* pE);
            bool remover(Entidades::Entidade* pE);
            void percorrer();
        };
    }
}

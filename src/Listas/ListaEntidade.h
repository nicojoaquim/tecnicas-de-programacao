#pragma once

#include"lista.h"

namespace trabalhoJogo
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
            void percorrer();
            void executar(); // TODO implementar
        };
    }
}

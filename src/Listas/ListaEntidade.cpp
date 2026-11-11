#include "ListaEntidade.h"

ListaEntidade::ListaEntidade(){

}
ListaEntidade::~ListaEntidade(){

}
void ListaEntidade::incluir(Entidade* pE){
    LEs.incluir(pE);
}
void ListaEntidade::percorrer(){
    LEs.percorrer();
}

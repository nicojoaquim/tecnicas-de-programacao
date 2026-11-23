#include "ListaEntidade.h"

CMD::Listas::ListaEntidade::ListaEntidade(){

}
CMD::Listas::ListaEntidade::~ListaEntidade(){

}
void CMD::Listas::ListaEntidade::incluir(CMD::Entidades::Entidade* pE){
    LEs.incluir(pE);
}
bool CMD::Listas::ListaEntidade::remover(CMD::Entidades::Entidade* pE){
    return LEs.remover(pE);
}
void CMD::Listas::ListaEntidade::percorrer(){
    LEs.percorrer();
}
CMD::Listas::Lista<CMD::Entidades::Entidade>::Iterador
CMD::Listas::ListaEntidade::inicio(){
    return LEs.inicio();
 }
 CMD::Listas::Lista<CMD::Entidades::Entidade>::Iterador
CMD::Listas::ListaEntidade::fim(){
    return LEs.fim();
 }

#include "ListaEntidade.h"

trabalhoJogo::Listas::ListaEntidade::ListaEntidade(){

}
trabalhoJogo::Listas::ListaEntidade::~ListaEntidade(){

}
void trabalhoJogo::Listas::ListaEntidade::incluir(trabalhoJogo::Entidades::Entidade* pE){
    LEs.incluir(pE);
}
void trabalhoJogo::Listas::ListaEntidade::percorrer(){
    LEs.percorrer();
}
trabalhoJogo::Listas::Lista<trabalhoJogo::Entidades::Entidade>::Iterador 
trabalhoJogo::Listas::ListaEntidade::inicio(){
    return LEs.inicio();
 }
 trabalhoJogo::Listas::Lista<trabalhoJogo::Entidades::Entidade>::Iterador 
trabalhoJogo::Listas::ListaEntidade::fim(){
    return LEs.fim();
 }
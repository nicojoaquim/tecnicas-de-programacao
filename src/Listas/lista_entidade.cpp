#include"lista_entidade.h"
Lista_Entidade::Lista_Entidade(){

}
Lista_Entidade::~Lista_Entidade(){

}
void Lista_Entidade::incluir(Entidade* pE){
    LEs.incluir(pE);
}
void Lista_Entidade::percorre(){
    LEs.percorrer();
}
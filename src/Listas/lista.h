#pragma once
#include "../organiza.h"
using std::cout;
using std::endl;
namespace trabalhoJogo{
    namespace Listas{
        template <class TL>
        class Lista{
            private:
            template <class TE>
            class Elemento{
                private:
                    TE* pInfo;
                    Elemento<TE>* pProx;
                    //bool dinamico;
                public:
                    Elemento();
                    ~Elemento();
                    void aterraElem();
                    void incluir(TE* p);
                    const TE* getInfo() const;
                    TE* getInfo();
                    void setProx(Elemento<TE>* pP);
                    Elemento<TE>* getProximo()const;
            };
            public:
            class Iterador{
                private:
                 Elemento<TL>* atual;
                 friend class Lista;
                 Iterador(Elemento<TL>* pElem);
                 public:
                 Iterador();
                 ~Iterador();
                 TL* operator*() const ;
                 TL* operator->()const ;
                 Iterador& operator++();
                 bool operator==(Iterador& outro) const;
                 bool operator!=(Iterador& outro)const;

            };
            private:
                Elemento<TL>* pPrimeiro;
                Elemento<TL>* pUltimo;
            public:
                Lista();
                ~Lista();
                void aterrarList();
                void incluir(TL* p);
                void limpar();
                void percorrer();
                Iterador inicio();
                Iterador fim();
                Iterador inicio()const;
                Iterador fim() const;
        };
    }
}
template <class TL>
template <class TE>
trabalhoJogo::Listas::Lista<TL>::Elemento<TE>::Elemento(){
    aterraElem();
}
template <class TL>
template <class TE>
trabalhoJogo::Listas::Lista<TL>:: Elemento<TE>::~Elemento(){
    aterraElem();
}
template <class TL>
template <class TE>
void trabalhoJogo::Listas::Lista<TL>:: Elemento<TE>::aterraElem(){
    pProx = NULL;
    pInfo = NULL;
}
template <class TL>
template <class TE>
void trabalhoJogo::Listas::Lista<TL>::Elemento<TE>::incluir(TE* p){
    pInfo = p;
}
template <class TL>
template <class TE>
const TE* trabalhoJogo::Listas::Lista<TL>::Elemento<TE>::getInfo() const{
    return pInfo;
}
template <class TL>
template <class TE>
TE* trabalhoJogo::Listas::Lista<TL>::Elemento<TE>::getInfo(){
    return pInfo;
}
template <class TL>
template <class TE>
void trabalhoJogo::Listas::Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pP){
    pProx = pP;
}
template <class TL>
template <class TE> 
typename trabalhoJogo::Listas::Lista<TL>::template Elemento<TE>*
 trabalhoJogo::Listas::Lista<TL>::Elemento<TE>::getProximo() const {
    return pProx;
}
template <class TL>
trabalhoJogo::Listas::Lista<TL>::Iterador::Iterador(Elemento<TL>* pElem):atual(pElem){
}
template <class TL>
trabalhoJogo::Listas::Lista<TL>::Iterador::Iterador():atual(NULL){
}
template <class TL>
trabalhoJogo::Listas::Lista<TL>::Iterador::~Iterador(){

}
template <class TL>
typename trabalhoJogo::Listas::Lista<TL>::Iterador& 
trabalhoJogo::Listas::Lista<TL>::Iterador::operator++(){
    if(atual)
        atual = atual->getProximo();
    return *this;
}

template <class TL>
bool trabalhoJogo::Listas::Lista<TL>::Iterador::operator==(Iterador& outro) const{
    return atual == outro.atual;
}
template <class TL>
bool trabalhoJogo::Listas::Lista<TL>::Iterador::operator!=(Iterador& outro) const{
    return atual != outro.atual;
}
template <class TL>
TL* trabalhoJogo::Listas::Lista<TL>::Iterador::operator*() const{
    return atual->getInfo();
}
template <class TL>
TL* trabalhoJogo::Listas::Lista<TL>::Iterador::operator->() const {
    return atual->getInfo();
}
template <class TL>
trabalhoJogo::Listas::Lista<TL>::Lista()
{
    aterrarList();
}
template <class TL>
trabalhoJogo::Listas::Lista<TL>::~Lista()
{
    limpar();
}
template <class TL>
void trabalhoJogo::Listas::Lista<TL>::aterrarList(){
    pPrimeiro = NULL;
    pUltimo = NULL;
}
template <class TL>
void trabalhoJogo::Listas::Lista<TL>::incluir(TL* p){
    if(p == NULL){
        cout << "Tentativa de incluir nulidade"<<endl;
        return;
    }
     Elemento<TL>* temp = NULL;
    if(pPrimeiro == NULL){
        temp = new Elemento<TL>;
        temp->incluir(p);
        pPrimeiro = temp;
        pUltimo = temp;
    }
    else{
        temp = new Elemento<TL>;
        temp->incluir(p);
        pUltimo->setProx(temp);
        pUltimo = temp;
        pUltimo->setProx(NULL);
    }
        
}
template <class TL>
void trabalhoJogo::Listas::Lista<TL>::limpar(){
    Elemento<TL>* temp=pPrimeiro, *depois=NULL;
    while (temp){
        depois = temp->getProximo();
        delete temp;
        temp = depois;
    }
    aterrarList();
}
template <class TL>
void trabalhoJogo::Listas::Lista<TL>::percorrer(){
    Elemento<TL>*temp = pPrimeiro;
    while(temp != NULL){
        temp = temp->getProximo();
    }
}
template <class TL>
typename trabalhoJogo::Listas::Lista<TL>::Iterador
trabalhoJogo::Listas::Lista<TL>::inicio(){
    return Iterador(pPrimeiro);
}

template <class TL>
typename trabalhoJogo::Listas::Lista<TL>::Iterador
trabalhoJogo::Listas::Lista<TL>::fim(){
    return Iterador(NULL);
}

template <class TL>
typename trabalhoJogo::Listas::Lista<TL>::Iterador
trabalhoJogo::Listas::Lista<TL>::inicio()const {
    return Iterador(pPrimeiro);
}
template <class TL>
typename trabalhoJogo::Listas::Lista<TL>::Iterador 
trabalhoJogo::Listas::Lista<TL>::fim() const{
    return Iterador(NULL);
}
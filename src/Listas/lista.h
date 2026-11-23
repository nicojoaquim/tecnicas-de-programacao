#pragma once

#include "../organiza.h"

namespace CMD
{
    namespace Listas
    {
        template <class TL>
        class Lista
        {
        private:
            template <class TE>
            class Elemento
            {
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
            class Iterador
            {
            private:
                Elemento<TL>* atual;
                friend class Lista;
                Iterador(Elemento<TL>* pElem);
                public:
                Iterador();
                ~Iterador();
                TL* operator*() const;
                TL* operator->() const;
                Iterador& operator++();
                const bool operator==(const Iterador& outro) const;
                const bool operator!=(const Iterador& outro) const;
            };
        private:
            Elemento<TL>* pPrimeiro;
            Elemento<TL>* pUltimo;
        public:
            Lista();
            ~Lista();
            void aterrarList();
            void incluir(TL* p);
            bool remover(TL* p);
            void limpar();
            void percorrer();
            Iterador inicio();
            Iterador fim();
            Iterador inicio() const;
            Iterador fim() const;
        };
    }
}

template <class TL>
template <class TE>
CMD::Listas::Lista<TL>::Elemento<TE>::Elemento(){
    aterraElem();
}

template <class TL>
template <class TE>
CMD::Listas::Lista<TL>::Elemento<TE>::~Elemento(){
    aterraElem();
}

template <class TL>
template <class TE>
void CMD::Listas::Lista<TL>::Elemento<TE>::aterraElem(){
    pProx = NULL;
    pInfo = NULL;
}

template <class TL>
template <class TE>
void CMD::Listas::Lista<TL>::Elemento<TE>::incluir(TE* p){
    pInfo = p;
}

template <class TL>
template <class TE>
const TE* CMD::Listas::Lista<TL>::Elemento<TE>::getInfo() const{
    return pInfo;
}

template <class TL>
template <class TE>
TE* CMD::Listas::Lista<TL>::Elemento<TE>::getInfo(){
    return pInfo;
}

template <class TL>
template <class TE>
void CMD::Listas::Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pP){
    pProx = pP;
}

template <class TL>
template <class TE>
typename CMD::Listas::Lista<TL>::template Elemento<TE>*
 CMD::Listas::Lista<TL>::Elemento<TE>::getProximo() const {
    return pProx;
}

template <class TL>
CMD::Listas::Lista<TL>::Iterador::Iterador(Elemento<TL>* pElem):atual(pElem){
}

template <class TL>
CMD::Listas::Lista<TL>::Iterador::Iterador():atual(NULL){
}

template <class TL>
CMD::Listas::Lista<TL>::Iterador::~Iterador(){

}

template <class TL>
typename CMD::Listas::Lista<TL>::Iterador&
CMD::Listas::Lista<TL>::Iterador::operator++(){
    if(atual)
        atual = atual->getProximo();
    return *this;
}

template <class TL>
const bool CMD::Listas::Lista<TL>::Iterador::operator==(const Iterador& outro) const{
    return atual == outro.atual;
}

template <class TL>
const bool CMD::Listas::Lista<TL>::Iterador::operator!=(const Iterador& outro) const{
    return atual != outro.atual;
}

template <class TL>
TL* CMD::Listas::Lista<TL>::Iterador::operator*() const{
    return atual->getInfo();
}

template <class TL>
TL* CMD::Listas::Lista<TL>::Iterador::operator->() const {
    return atual->getInfo();
}

template <class TL>
CMD::Listas::Lista<TL>::Lista()
{
    aterrarList();
}

template <class TL>
CMD::Listas::Lista<TL>::~Lista()
{
    limpar();
}

template <class TL>
void CMD::Listas::Lista<TL>::aterrarList(){
    pPrimeiro = NULL;
    pUltimo = NULL;
}

template <class TL>
void CMD::Listas::Lista<TL>::incluir(TL* p){
    if(p == NULL){
        std::cout << "Tentativa de incluir nulidade" << std::endl;
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
bool CMD::Listas::Lista<TL>::remover(TL* p){
    Elemento<TL>* anterior = NULL;
    Elemento<TL>* atual = pPrimeiro;

    while (atual != NULL) {
        if (atual->getInfo() == p) {
            Elemento<TL>* proximo = atual->getProximo();
            if (anterior != NULL)
                anterior->setProx(proximo);
            else
                pPrimeiro = proximo;

            if (pUltimo == atual)
                pUltimo = anterior;

            delete atual;
            return true;
        }

        anterior = atual;
        atual = atual->getProximo();
    }

    return false;
}

template <class TL>
void CMD::Listas::Lista<TL>::limpar(){
    Elemento<TL>* temp=pPrimeiro, *depois=NULL;
    while (temp){
        depois = temp->getProximo();
        delete temp;
        temp = depois;
    }
    aterrarList();
}

template <class TL>
void CMD::Listas::Lista<TL>::percorrer(){
    Elemento<TL>*temp = pPrimeiro;
    while(temp != NULL){
        temp = temp->getProximo();
    }
}

template <class TL>
typename CMD::Listas::Lista<TL>::Iterador
CMD::Listas::Lista<TL>::inicio(){
    return Iterador(pPrimeiro);
}

template <class TL>
typename CMD::Listas::Lista<TL>::Iterador
CMD::Listas::Lista<TL>::fim(){
    return Iterador(NULL);
}

template <class TL>
typename CMD::Listas::Lista<TL>::Iterador
CMD::Listas::Lista<TL>::inicio()const {
    return Iterador(pPrimeiro);
}

template <class TL>
typename CMD::Listas::Lista<TL>::Iterador
CMD::Listas::Lista<TL>::fim() const{
    return Iterador(NULL);
}

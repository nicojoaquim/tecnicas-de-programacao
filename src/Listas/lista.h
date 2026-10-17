#pragma once
#include "../organiza.h"
template <class TL>
class Lista{
    private:
    template <class TE>
    class Elemento{
        private:
            TE* pInfo;
            Elemento<TE>* pProx;
        public:
            Elemento();
            ~Elemento();
            void aterraElem();
            void incluir(TE* p);
            const TE* getInfo() const;
            void setProx(Elemento<TE>* pP);
            Elemento<TE>* getProximo()const;
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
};
template <class TL>
template <class TE>
Lista<TL>::Elemento<TE>::Elemento(){
    aterraElem();
}
template <class TL>
template <class TE>
Lista<TL>::Elemento<TE>::~Elemento(){
    aterraElem();
}
template <class TL>
template <class TE>
void Lista<TL>::Elemento<TE>::aterraElem(){
    pProx = NULL;
    pInfo = NULL;
}
template <class TL>
template <class TE>
void Lista<TL>::Elemento<TE>::incluir(TE* p){
    pInfo = p;
}
template <class TL>
template <class TE>
const TE* Lista<TL>::Elemento<TE>::getInfo() const{
    return pInfo;
}
template <class TL>
template <class TE>
void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pP){
    pProx = pP;
}
template <class TL>
template <class TE> 
typename Lista<TL>::Elemento<TE>*
 Lista<TL>::Elemento<TE>::getProximo() const {
    return pProx;
}
template <class TL>
Lista<TL>::Lista()
{
    aterrarList();
}
template <class TL>
Lista<TL>::~Lista()
{
    limpar();
}
template <class TL>
void Lista<TL>::aterrarList(){
    pPrimeiro = NULL;
    pUltimo = NULL;
}
template <class TL>
void Lista<TL>::incluir(TL* p){
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
void Lista<TL>::limpar(){
    Elemento<TL>* temp=pPrimeiro, *depois=NULL;
    while (temp){
        depois = temp->getProximo();
        delete temp;
        temp = depois;
    }
    aterrarList();
}
template <class TL>
void Lista<TL>::percorrer(){
    Elemento<TL>*temp = pPrimeiro;
    while(temp != NULL){
        temp = temp->getProximo();
    }
}
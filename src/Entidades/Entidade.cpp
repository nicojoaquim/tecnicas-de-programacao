#include"../organiza.h"
#include"Entidade.h"
Entidade::Entidade(): x(0), y(0), buffer(cout){

}

Entidade::~Entidade()
{
}
void Entidade::salvardataBuffer(){
    buffer <<x << " "<<y;
}
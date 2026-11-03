#include"../organiza.h"
#include"Entidade.h"
using std::cout;
Entidade::Entidade(): x(0), y(0), buffer(cout){

}

Entidade::~Entidade()
{
}
void Entidade::salvarDataBuffer(){
    buffer <<x << " "<<y;
}
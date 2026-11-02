#include"Inimigo.h"
Inimigo::Inimigo():Personagem(),agresividade(1)
{

}
Inimigo::~Inimigo(){

}
void Inimigo::salvarDataBuffer(){
 buffer << x<< y<<num_vida<<agresividade;
}
#include"Inimigo.h"
#include"Jogador.h"
CMD::Entidades::Personagens::Inimigo::Inimigo():
Personagem(),
agresividade(1),
recompenca(1)
{

}
CMD::Entidades::Personagens::Inimigo::~Inimigo(){

}
void CMD::Entidades::Personagens::Inimigo::pontuacaoRecebida(Jogador*pJog){
    if(pJog!=NULL)
        for(int i=0;i<recompenca;i++)
            ++(*pJog);
}
/*
void Inimigo::salvarDataBuffer(){
    buffer << getCoord().x << getCoord().y <<num_vida<<agresividade;
}
*/

#pragma once

#include <vector>
#include <list>
#include <set>

class Inimigo;
class Obstaculo;
class Projetil;
class Jogador;

class Gerenciador_Colisoes
{
private:
    vector<Inimigo*> LIs;
    list<Obstaculo*> LOs;
    set<Projetil*> LPs;
    Jogador* pJog1;
    ;

public:
    Gerenciador_Colisoes();
    ~Gerenciador_Colisoes();
    ;
};

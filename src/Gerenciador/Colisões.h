#pragma once

#include <vector>
#include <list>
#include <set>
using namespace std;
class Entidade;
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
    void incluirInimigo(Inimigo* pi);
    void incluirObstaculo(Obstaculo* po);
    void incluirProjetil(Projetil* pj);
    private:
    const bool verificarColisao(Entidade* p1, Entidade* p2);
    void tratarColisaoJogsInimigo();
    void tratarColisaoJogsObstaculo();
    void tratarColisaoJogsProjetil();
    void executar();
};

#pragma once

#include <vector>
#include <list>
#include <set>

class Entidade;
class Inimigo;
class Obstaculo;
class Projetil;
class Jogador;

using std::vector;
using std::set;
using std::list;

class GerenciadorColisoes
{
private:
    vector<Inimigo*> LIs;
    list<Obstaculo*> LOs;
    set<Projetil*> LPs;
    Jogador* pJog1;

public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
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

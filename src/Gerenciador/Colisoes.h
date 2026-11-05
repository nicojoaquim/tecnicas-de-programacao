#pragma once

#include <vector>
#include <list>
#include <set>

class Entidade;
class Inimigo;
class Obstaculo;
class Projetil;
class Jogador;

class GerenciadorColisoes
{
private:
    std::vector<Inimigo*> LIs;
    std::list<Obstaculo*> LOs;
    std::set<Projetil*> LPs;
    Jogador* pJog1;

public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
    void incluirInimigo(Inimigo* pi);
    void incluirObstaculo(Obstaculo* po);
    void incluirProjetil(Projetil* pj);

private:
    const bool verificarColisao(Entidade* p1, Entidade* p2) const;
    void tratarColisaoJogsInimigo();
    void tratarColisaoJogsObstaculo();
    void tratarColisaoJogsProjetil();
    void executar();
};

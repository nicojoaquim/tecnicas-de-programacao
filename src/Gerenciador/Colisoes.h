#pragma once

#include <vector>
#include <list>
#include <set>

class Entidade;
class Inimigo;
class Obstaculo;
class Projetil;
class Jogador;
class Chao;

class GerenciadorColisoes
{
private:
    std::vector<Inimigo*> LIs;
    std::list<Obstaculo*> LOs;
    std::set<Projetil*> LPs;
    std::list<Chao*> LCs;
    Jogador* pJog1;

public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
    void incluirInimigo(Inimigo* pi);
    void incluirObstaculo(Obstaculo* po);
    void incluirProjetil(Projetil* pj);
    void incluirChao(Chao* pc);

private:
    const bool verificarColisao(Entidade* p1, Entidade* p2) const;
    void tratarColisaoJogsInimigo();
    void tratarColisaoJogsObstaculo();
    void tratarColisaoJogsProjetil();
    void tratarColisaoJogsChao();
    void executar();
};

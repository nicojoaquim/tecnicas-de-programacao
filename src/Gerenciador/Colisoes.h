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
    std::vector<Inimigo*>::iterator itIs;
    std::list<Obstaculo*>::iterator itOs;
    std::set<Projetil*>::iterator itPs;
    std::list<Chao*>::iterator itCs;
    float dx;
    float dy;
    float internox;
    float internoy;

public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
    void incluirInimigo(Inimigo* pi);
    void incluirObstaculo(Obstaculo* po);
    void incluirProjetil(Projetil* pj);
    void incluirChao(Chao* pc);
    void incluirJogador1(Jogador* pPrimeiro);
    void executar();

private:
    void colisaoJogsInimigo();
    void colisaoJogsChao();
    void colisaoChaoInimigo();
    void tratarColisaoJogsInimigo();
    void tratarColisaoJogsObstaculo();
    void tratarColisaoJogsProjetil();
    void tratarColisaoJogsChao();
    void tratarColisaoChaoInimigo();
    const bool verificarColisao(Entidade* p1, Entidade* p2);
};

#pragma once

#include <vector>

#include "../Ente.h"
#include "../Listas/ListaEntidade.h"
#include "../Gerenciador/Colisoes.h"

class Fase: public Ente
{
protected:
    GerenciadorColisoes GC;
    ListaEntidade lista_ents;
    std::vector<Entidade*> temp_lista_ents;
    // Jogador* pJog1; Fase(Jogador* jogador1): pJog1(jogador1)

public:
    Fase();
    virtual ~Fase();
    virtual void executar(); // Polimorfismo

    void tempAdicionaEnt(Entidade* entidade) {
        temp_lista_ents.push_back(entidade);
    }

protected:
    // talvez remover depois alguns metodos
    void criarAranhaGigante();
    void criarOlhoVoador();
    void criarBruxa();
    void criarPlataforma();
    void criarCogumelo();
    void criarObstDificil();//mudar nome depois
    virtual void criarInimigos() = 0;
    virtual void criarObst() = 0;
    void criarCenarios();
    // virtual void desenhar() = 0;
    // virtual void gravitar() = 0;
    // virtual void mover() = 0;
    void gravitar();
    void mover();
    void desenhar();
};

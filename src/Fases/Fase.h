#pragma once

#include <list>

#include "../Ente.h"
#include "../Entidades/Entidade.h"
#include "../Listas/ListaEntidade.h"
#include "../Gerenciador/Colisoes.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Chao.h"
class Fase: public Ente
{
protected:
    GerenciadorColisoes GC;
    ListaEntidade lista_ents;
    std::list<Entidade*> temp_lista_ents;
    // Jogador* pJog1; Fase(Jogador* jogador1): pJog1(jogador1)

public:
    Fase();
    virtual ~Fase();
    virtual void executar(); // Polimorfismo

    void tempAdicionaChao(Chao* chao);
    void tempAdicionaJog1(Jogador* joagdor1);

protected:
    virtual void criarInimigos() = 0;
    virtual void criarObst() = 0;
    void criarCenarios();
    // virtual void desenhar() = 0;
    // virtual void gravitar() = 0;
    // virtual void mover() = 0;
    void gravitar();
    void mover();
    void desenhar();

    // talvez remover depois alguns metodos
    void criarAranhaGigante();
    void criarOlhoVoador();
    void criarBruxa();
    void criarPlataforma();
    void criarCogumelo();
    void criarObstDificil();//mudar nome depois

    void destruirEntidade(Entidade* pE);
};

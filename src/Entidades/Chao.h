#pragma once

#include "Entidade.h"

// Chão será formado por várias
class Chao : public Entidade
{
private:
    float largura;
    float altura;
public:
    Chao();
    ~Chao();
    void inicializaChao(sf::Sprite * chao);
    void tamanhoChao();
    void gravitar();
    void executar();
    void salvar();
};

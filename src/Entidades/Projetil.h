#pragma once

#include "Entidade.h"

class Projetil : public Entidade
{
protected:
    sf::Vector2f v; // velocidade do projétil
    bool ativo;// se foi disparado

public:
    Projetil();
    ~Projetil();
    const sf::Vector2f getV() const;
    void setV(const sf::Vector2f velocidade);
    void gravidar();
    void executar();
    void salvar();
};

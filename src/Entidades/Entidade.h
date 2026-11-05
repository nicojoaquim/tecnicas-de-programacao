#pragma once

#include "../Ente.h"
#include "../Coordenada.h"
#include <SFML/System/Vector2.hpp>

class Entidade:public Ente
{
protected:
    sf::Vector2f coord;
    sf::Vector2f tamanho;
    std::ostream & buffer;

public:
    Entidade();
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;

    void setCoord(sf::Vector2f novas_coord); // Do centro da Fig??
    const sf::Vector2f getCoord() const;
    void setTamanho(sf::Vector2f novo_tam);
    const sf::Vector2f getTamanho() const;

protected:
    virtual void salvarDataBuffer();
};



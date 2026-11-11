#pragma once

#include "../Ente.h"
#include "../Coordenada.h"
#include <SFML/System/Vector2.hpp>

// Usado para testar se é um vetor válido
#define INEXISTENTE (Vector2f(-99999999.f,-99999999.f))

class Entidade: public Ente
{
protected:
    std::ostream & buffer;
    // const bool sofre_gravidade;

public:
    // Entidade(bool gravidade = false);
    Entidade();
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    virtual void gravitar(const float dt) = 0;
    // virtual void mover(const float dt, const sf::Vector2f dr) = 0;
    virtual void mover() = 0;

    void atribuirSprite(sf::Sprite* Fig);

    const sf::Vector2f getPosicao() const;
    void setPosicao(const sf::Vector2f posicao);
    void setPosicaoEsper(const sf::Vector2f posicao);
    const float getX() const;
    const float getY() const;
    const sf::Vector2f getTamanho() const;
    const float getLargura() const;
    const float getAltura() const;
    // const bool sofreGravidade() const;

protected:
    virtual void salvarDataBuffer();
};



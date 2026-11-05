#pragma once

#include "../Ente.h"
#include "../Coordenada.h"
#include <SFML/System/Vector2.hpp>

// Usado para testar se é um vetor válido
#define INEXISTENTE (Vector2f(-999999.f,-999999.f))

class Entidade: public Ente
{
protected:
    std::ostream & buffer;

public:
    Entidade();
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;

    void inicializaPosicao(float x, float y);
    // void centralizar();

    void atribuirSprite(sf::Sprite* Fig);

    const sf::Vector2f getPosicao() const;
    void setPosicao(const sf::Vector2f posicao);
    const float getX() const;
    const float getY() const;

    const sf::Vector2f getTamanho() const;
    const float getLargura() const;
    const float getAltura() const;

protected:
    virtual void salvarDataBuffer();
};



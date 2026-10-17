#pragma once

// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ente;

class Gerenciador_Grafico
{
private:
    ;
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();

    void desenharEnte(Ente* pE);
};

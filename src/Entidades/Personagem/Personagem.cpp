#include"Personagem.h"

Personagem::Personagem():
    Entidade(),
    num_vida(3),
    velocidade({0,0})
{
}

Personagem::~Personagem()
{
}
void Personagem::setVy(float y){
    velocidade.y = y;
}
void Personagem::restartRelogio(){
    relogio.restart();
}
// baseado em https://gafferongames.com/post/integration_basics/
void Personagem::gravitar(const float dt){
    float gravidadeMax = 800.f;
    float aceleracao = 1200.f;
    velocidade.y += aceleracao*dt;
    if(velocidade.y > gravidadeMax)
        velocidade.y = gravidadeMax;
    getFig()->move({0,velocidade.y*dt});
}
 const float Personagem::getSegundos(){
    return relogio.restart().asSeconds();
}

// Relógio é static
sf::Clock Personagem::relogio;

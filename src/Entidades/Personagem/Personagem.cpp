#include"Personagem.h"

Personagem::Personagem():
Entidade(),
num_vida(3),
v({0,0})
{
}

Personagem::~Personagem()
{
}
void Personagem::setVy(float y){
    v.y = y;
}
void Personagem::restartRelogio(){
    relogio.restart();
}
// baseado em https://gafferongames.com/post/integration_basics/
void Personagem::gravitar(const float dt){
    float gravidadeMax = 800.f;
    float aceleracao = 1200.f;
    v.y += aceleracao*dt;
    if(v.y > gravidadeMax)
        v.y = gravidadeMax;
    getFig()->move({0,v.y*dt});
}
 const float Personagem::getSegundos(){
    return relogio.restart().asSeconds();
}
sf::Clock Personagem::relogio;

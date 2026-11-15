#include"Personagem.h"

trabalhoJogo::Entidades::Personagens::Personagem::Personagem():
    // Entidade(true), // sofre_gravidade = true
    Entidade(),
    num_vida(3),
    velocidade({0,0})
{
}

trabalhoJogo::Entidades::Personagens::Personagem::~Personagem()
{
}
void trabalhoJogo::Entidades::Personagens::Personagem::setVy(float y){
    velocidade.y = y;
}

// baseado em https://gafferongames.com/post/integration_basics/
void trabalhoJogo::Entidades::Personagens::Personagem::gravitar(const float dt){
    float gravidadeMax = 800.f;
    float aceleracao = 1200.f;
    velocidade.y += aceleracao*dt;
    if(velocidade.y > gravidadeMax)
        velocidade.y = gravidadeMax;
    getFig()->move({0,velocidade.y*dt});
}

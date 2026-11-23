#include "Personagem.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Gerenciador/Tempo.h"


CMD::Entidades::Personagens::Personagem::Personagem():
    // Entidade(true), // sofre_gravidade = true
    Entidade(),
    num_vida(3),
    esta_no_chao(false)
{
}

CMD::Entidades::Personagens::Personagem::~Personagem()
{
}

void CMD::Entidades::Personagens::Personagem::setEstaNoChao(bool no_chao) {
    esta_no_chao = no_chao;
}


const int CMD::Entidades::Personagens::Personagem::getNumVida() const
 {
     return num_vida; }


void CMD::Entidades::Personagens::Personagem::operator--(){
    num_vida--;
}
// void CMD::Entidades::Personagens::Personagem::gravitar() {
//     /*if (esta_no_chao)
//       return;*/

//     float dt = Gerenciador::Tempo::getSegundos(); // s
//     float velocidade_max = 1200.f; // pixel/s
//     float aceleracao = 1200.f; // pixel/s²

//     velocidade.y += aceleracao*dt;

//     if(velocidade.y > velocidade_max)
//         velocidade.y = velocidade_max;

//     getFig()->move({0,velocidade.y*dt});
// }
// void CMD::Entidades::Personagens::Personagem::setVy(float y) {
//     velocidade.y = y;
// }

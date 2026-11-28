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

void CMD::Entidades::Personagens::Personagem::salvarDataBuffer() {
    Entidade::salvarDataBuffer();
    buffer << "Personagem\n"
           << getNumVida() << "\n"
           << esta_no_chao << "\n";
}

void CMD::Entidades::Personagens::Personagem::carregarDataBuffer() {
    Entidade::carregarDataBuffer();

    std::string str;
    buffer >> str;
    if (str != std::string("Personagem")) {
        std::cerr << "erro: dados inválidos em Personagem::carregarDataBuffer()" << std::endl;
        return;
    }

    int vida;
    buffer >> vida;
    setNumVida(vida);

    bool chao;
    buffer >> chao;
    setEstaNoChao(chao);
}

void CMD::Entidades::Personagens::Personagem::setEstaNoChao(bool no_chao) {
    esta_no_chao = no_chao;
}


const int CMD::Entidades::Personagens::Personagem::getNumVida() const {
    return num_vida;
}

void CMD::Entidades::Personagens::Personagem::setNumVida(int vida) {
    num_vida = vida;
}

void CMD::Entidades::Personagens::Personagem::operator--() {
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

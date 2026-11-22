#include "Projetil.h"
#include "Personagem/Jogador.h"
#include "../Gerenciador/Tempo.h"
#include "../Gerenciador/Grafico.h"
#include "../organiza.h"

CMD::Entidades::Projetil::Projetil():Entidade(),ativo(false){

}
CMD::Entidades::Projetil::~Projetil(){

}

void CMD::Entidades::Projetil::executar(){
    if (!ativo)
        return;

    gravitar();
    mover();
}
void CMD::Entidades::Projetil::salvar(){

}

void CMD::Entidades::Projetil::mover() {
    if (!ativo)
        return;

    const float dt = Gerenciador::Tempo::getSegundos();
    Entidade::mover({ velocidade.x * dt, 0.f });

    if (pGG != NULL && pFig != NULL) {
        const sf::FloatRect limites = pFig->getGlobalBounds();
        const sf::Vector2u tamanhoJanela = pGG->getTamanhoJanela();
        if (limites.left > tamanhoJanela.x
            || limites.left + limites.width < 0.f
            || limites.top > tamanhoJanela.y
            || limites.top + limites.height < 0.f) {
            desativar();
        }
    }
}
//meio alto explicativo, mas ele vai até o alvo
void CMD::Entidades::Projetil::disparar(const sf::Vector2f origem,
    const sf::Vector2f alvo) {
    if (pFig == NULL) {
        std::cerr << "Sprite inexistente ao disparar projetil" << std::endl;
        return;
    }

    sf::Vector2f direcao = alvo - origem;
    const float distancia = std::sqrt(
        direcao.x * direcao.x + direcao.y * direcao.y
    );
    if (distancia > 0.f)
        direcao /= distancia;
    else
        direcao = sf::Vector2f(1.f, 0.f);

    const float velocidadeProjetil = 450.f;
    setPosicao(origem);
    setV(direcao * velocidadeProjetil);
    pFig->setRotation(std::atan2(direcao.y, direcao.x) * 180.f / 3.14159265f + 90.f);
    ativo = true;
}

void CMD::Entidades::Projetil::desativar() {
    ativo = false;
    setV(sf::Vector2f(0.f, 0.f));
}

bool CMD::Entidades::Projetil::estaAtivo() const {
    return ativo;
}

void CMD::Entidades::Projetil::perfurar(Personagens::Jogador* pJ){
    if (!ativo || pJ == NULL || pJ->getNumVida() <= 0)
        return;

    pJ->operator--();
    desativar();
}
// const sf::Vector2f CMD::Entidades::Projetil::getV() const{
//     return velocidade;
// }
// void CMD::Entidades::Projetil::setV(const sf::Vector2f v){
//     velocidade = v;
// }
// void CMD::Entidades::Projetil::gravitar() {
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

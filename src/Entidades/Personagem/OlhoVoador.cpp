#include "OlhoVoador.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Gerenciador/tempo.h"
#include"organiza.h"

using sf::Vector2f;
using sf::Vector2u;
using sf::Keyboard;
CMD::Entidades::Personagens::OlhoVoador::OlhoVoador():Inimigo(),
tamanho(1),
indoParaFrente(true),
mudou_direcao(false),
tempoSen(0),
yBase(0),
yBaseInicializada(false){
    velocidade.x = 160.f;

}

CMD::Entidades::Personagens::OlhoVoador::~OlhoVoador(){

}
void CMD::Entidades::Personagens::OlhoVoador::executar(){
    mover();
    if (mudou_direcao) {
        mudou_direcao = false;
        getFig()->scale(-1.f, 1.f);
    }
}
void CMD::Entidades::Personagens::OlhoVoador::salvar(){
    salvarDataBuffer();
}
void CMD::Entidades::Personagens::OlhoVoador::mover(){
    const Vector2u janela = pGG->getTamanhoJanela();
    const sf::FloatRect limites = getFig()->getGlobalBounds();
    const float dt = Gerenciador::Tempo::getSegundos();
    const float amplitude = 40.f;
    const float frequencia = 2.f;

    if (!yBaseInicializada) {
        yBase = getY();
        yBaseInicializada = true;
    }

    Vector2f movimento(0.f, 0.f);
    const float limiteDireito = std::max(
        0.f,
        static_cast<float>(janela.x) - limites.width
    );
    const float xAtual = limites.left;
    float direcao = 0;
    if (indoParaFrente) 
        direcao = 1.f;
     else 
        direcao = -1.f;
    
    float xDesejado = xAtual + direcao * velocidade.x * dt;
    if (xDesejado >= limiteDireito) {
        movimento.x = limiteDireito - xAtual;
        if (indoParaFrente) {
            indoParaFrente = false;
            mudou_direcao = true;
        }
    }
    else if (xDesejado <= 0.f) {
        movimento.x = -xAtual;
        if (!indoParaFrente) {
            indoParaFrente = true;
            mudou_direcao = true;
        }
    }
    else {
        movimento.x = xDesejado - xAtual;
    }

    tempoSen += dt;
    const float yAlvo = yBase + amplitude * std::sin(tempoSen * frequencia);
    const float limiteSuperior = limites.height / 2.f;
    const float limiteInferior = std::max(
        limiteSuperior,
        static_cast<float>(janela.y) - limites.height / 2.f
    );
    const float yDestino = std::max(
        limiteSuperior,
        std::min(limiteInferior, yAlvo)
    );
    movimento.y = yDestino - getY();

    Entidade::mover(movimento);
}
void CMD::Entidades::Personagens::OlhoVoador::danificar(Jogador* pJog){

}

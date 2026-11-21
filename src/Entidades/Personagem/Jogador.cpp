#include "Jogador.h"

#include "Inimigo.h"
#include "../../Gerenciador/Tempo.h"
#include "../../Gerenciador/Grafico.h"

#include <SFML/Window/Keyboard.hpp>
#include <cmath> // std::abs e trigonométricas

using sf::Keyboard;
using sf::Vector2f;
using std::cerr;
using std::endl;

CMD::Entidades::Personagens::Jogador::Jogador():
    Jogador(1, sf::String(""))
{
}

CMD::Entidades::Personagens::Jogador::Jogador(int jogadorX, sf::String str):
    Personagem(),
    pontos(0),
    jogador(jogadorX),
    nome()
{
    // Não dá para inicializar o sprite aqui, pois esta construtora
    // é chamada antes de inicializar o ponteiro pGG para os Entes
}

CMD::Entidades::Personagens::Jogador::~Jogador()
{
    delete getFig();
}

//baseado na colisão de Hilze Vonck
bool CMD::Entidades::Personagens::Jogador::colidir(Personagens::Inimigo* pIn) {
    if (pIn == NULL) {
        cerr << "Inimigo nulo" << endl;
        return false;
    }
    /*
    float dx = std::abs(pIn->getX() - this->getX());
    float dy = std::abs(pIn->getY() - this->getY());
    float interx = dx - (this->getLargura()/2 + pIn->getLargura()/2) ;
    float intery = dy - (this->getAltura()/2 + pIn->getAltura()/2);

    if(interx < 0.0f && intery < 0.0f)
    {
        if(interx > intery){
            if(dx > 0)
                this->getFig()->move({-1.0f,0.0f});
            else
                this->getFig()->move({1.0f,0.0f});
            }
        else {
            if(dy>0)
                this->getFig()->move({0.0f,-1.0f});
            else
                this->getFig()->move({0.0f,1.0f});
        }
        return true;
    }*/
    return false;
}

void CMD::Entidades::Personagens::Jogador::executar() {
    gravitar();
    mover();
}

void CMD::Entidades::Personagens::Jogador::salvar() {

}

void CMD::Entidades::Personagens::Jogador::mover() {
    sf::Vector2f dv(0, 0);
    float dt = Gerenciador::Tempo::getSegundos();
    //float direcao_ante_vx = velocidade.x;

    if (esta_no_chao && Keyboard::isKeyPressed(Keyboard::Up)) {
            velocidade.y -= 600.;
            esta_no_chao = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
        dv.x -= 800.;
    if (Keyboard::isKeyPressed(Keyboard::Right))
        dv.x += 800.;
    velocidade += dv;
    if(esta_no_chao){
        velocidade.x *= 0.85f;

        if (std::abs(velocidade.x) > 400.f) {

            if(velocidade.x > 0)
                velocidade.x = 400.f;
            else
                velocidade.x = -400.f;
            }

            if (std::abs(velocidade.x) < 1.f)
                    velocidade.x = 0.f;
    }
    else {
        velocidade.x *= 0.98f;

        if (std::abs(velocidade.x) > 500.f) {
            if(velocidade.x > 0)
                    velocidade.x = 500.f;
            else
                velocidade.x = -500.f;

        }
    }
    //     velocidade.x *= 0.3f;
    //     if (velocidade.x < 1.f)
    //         velocidade.x = 0;
    // else {
    //     velocidade.x *= 0.9993f;
    // }

    Entidade::mover(velocidade*dt);
    //std::cout << velocidade.x << "\t" << velocidade.y << "\t"<< std::endl;
}

void CMD::Entidades::Personagens::Jogador::carregarSprite() {
    sf::Sprite* pSprite = new sf::Sprite;

    if (jogador == 1)
        pSprite->setTexture(pGG->getTexJogador1());
    else
        pSprite->setTexture(pGG->getTexJogador2());

    atribuirSprite(pSprite);
    getFig()->setScale(2, 2);
}

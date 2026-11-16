#include "Fase.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Chao.h"

#include "../Entidades/Personagem/AranhaGigante.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>
using sf::Event;
using sf::Keyboard;

#include "../organiza.h"

CMD::Fases::Fase::Fase():
    Ente(),
    GC(),
    lista_ents()
{
}

CMD::Fases::Fase::~Fase(){
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim(); ++it)
        if((*it)->getDinamico())
            destruirEntidade(*it);
}
void CMD::Fases::Fase::adicionaJog1(Entidades::Personagens::Jogador* jogador1){
        lista_ents.incluir(static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(jogador1)));
        GC.incluirJogador1(jogador1);
    }
void CMD::Fases::Fase::adicionaChao(Entidades::Chao* chao){
    lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
    GC.incluirChao(chao);
}
void CMD::Fases::Fase::gravitar() {
    float dt = Tempo::getSegundos();
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->gravitar(dt);
}

void CMD::Fases::Fase::mover() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->mover();

}

void CMD::Fases::Fase::desenhar() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->desenhar();
}

void CMD::Fases::Fase::executar() {
    Event evento;
    bool jogando = true;
    while (jogando) {
        // Verificar eventos ocorridos desde o último frame
        while (pGG->getEvento(evento)) {
            if (evento.type == Event::Closed) {
                pGG->fechar();
                jogando = false;
                return;
            }
            else if (evento.type == Event::KeyPressed
                     && evento.key.code == Keyboard::Escape) {
                // num_vida = 0;
                jogando = false;
                return;
            }
        }
        pGG->limpar();
        gravitar();
        mover();
        GC.executar();
        desenhar();
        pGG->renderizar();
    }
}

void CMD::Fases::Fase::destruirEntidade(Entidades::Entidade *pE) {
    if (pE == NULL) {
        std::cerr << "Nulidade em Fase::destruirEntidade" << std::endl;
        return;
    }
    // std::cout << "delete: " << pE << std::endl;
    delete (pE->getFig()); // Sprite
    delete pE; // Entidade
}

void CMD::Fases::Fase::criarAranhaGigante() {
    Entidades::Personagens::AranhaGigante* pAranha;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexAranhaGigante());

    pAranha = new Entidades::Personagens::AranhaGigante;
    pAranha->atribuirSprite(pSprite);
    pAranha->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pAranha));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(pAranha));
}

void CMD::Fases::Fase::criarOlhoVoador() {

}

void CMD::Fases::Fase::criarBruxa() {

}

void CMD::Fases::Fase::criarPlataforma() {

}

void CMD::Fases::Fase::criarCogumelo() {

}

void CMD::Fases::Fase::criarObstDificil() {

}

void CMD::Fases::Fase::criarCenarios() {

}

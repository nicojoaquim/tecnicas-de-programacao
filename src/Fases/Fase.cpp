#include "Fase.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Entidades/Entidade.h"

#include "../Entidades/Personagem/AranhaGigante.h"

#include <SFML/Window.hpp>
using sf::Event;
using sf::Keyboard;

#include <list>
using std::list;

#include "../organiza.h"

Fase::Fase():
    Ente(),
    GC(),
    lista_ents()
{
    std::cerr << "\nEntrando na fase" << std::endl;
}

Fase::~Fase() {
    std::cerr << "\nSaindo da fase" << std::endl;
    // TEMPORÁRIO
    list<Entidade*>::iterator it;
    it = temp_lista_ents.begin();

    std::cerr << "jogador (Jogo): " << (*it) << std::endl;
    it++; // jogador

    std::cerr << "chao (Jogo): " << (*it) << std::endl;
    it++; // chao

    while (it != temp_lista_ents.end()) {
        std::cerr << "*it: " << (*it) << std::endl;
        destruirEntidade(*it);
        it++;
    }
}

void Fase::gravitar() {
    list<Entidade*>::iterator it;
    float dt = Tempo::getSegundos();
    for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++)
    {
        /*
        if ((*it)->sofreGravidade()) {
            float gravidadeMax = 1800.f;
            float aceleracao = 1200.f;
            velocidade.y += aceleracao*dt;
            if(velocidade.y > gravidadeMax)
                velocidade.y = gravidadeMax;
            getFig()->move({0,velocidade.y*dt});
        }
        */
        (*it)->gravitar(dt);
    }
}

void Fase::mover() {
    list<Entidade*>::iterator it;
    for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++) {
        (*it)->mover();
    }
}

void Fase::desenhar() {
    list<Entidade*>::iterator it;
    for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++) {
        (*it)->desenhar();
    }
}

void Fase::executar() {
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

void Fase::destruirEntidade(Entidade* pE) {
    if (pE == NULL) {
        std::cerr << "Nulidade em Fase::destruirEntidade" << std::endl;
        return;
    }
    std::cerr << "delete: " << pE << std::endl;
    delete (pE->getFig()); // Sprite
    delete pE; // Entidade
}

void Fase::criarAranhaGigante() {
    AranhaGigante* pAranha;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexAranhaGigante());

    pAranha = new AranhaGigante;
    pAranha->atribuirSprite(pSprite);

    std::cerr << "aranha: " << pAranha << "\t"
              << "sprite: " << pSprite << "\t"
              << "getFig: " << pAranha->getFig() << std::endl;
    //incluir na lista de entidades
    temp_lista_ents.push_back(static_cast<Entidade*>(pAranha)); // FAZER DELETE DEPOIS
}

void Fase::criarOlhoVoador() {

}

void Fase::criarBruxa() {

}

void Fase::criarPlataforma() {

}

void Fase::criarCogumelo() {

}

void Fase::criarObstDificil() {

}

void Fase::criarCenarios() {

}

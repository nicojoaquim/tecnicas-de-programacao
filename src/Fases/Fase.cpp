#include "Fase.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Chao.h"

#include "../Entidades/Personagem/AranhaGigante.h"
#include <SFML/Window.hpp>
using sf::Event;
using sf::Keyboard;

#include <vector>
using std::vector;

#include "../organiza.h"

trabalhoJogo::Fases::Fase::Fase():
    Ente(),
    GC(),
    lista_ents()
{
}

trabalhoJogo::Fases::Fase::~Fase(){
    for(auto it = lista_ents.inicio(); it != lista_ents.fim();++it)
        if((*it)->getDinamico())
            delete (*it);
}
void trabalhoJogo::Fases::Fase::adicionaJog1(Entidades::Personagens::Jogador* jogador1){
        //temp_lista_ents.push_back(static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(jogador1)));
        lista_ents.incluir(static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(jogador1)));
        GC.incluirJogador1(jogador1);
    }
void trabalhoJogo::Fases::Fase::adicionaChao(Entidades::Chao* chao){
    //temp_lista_ents.push_back(static_cast<Entidades::Entidade*>(chao));
    lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
    GC.incluirChao(chao);
}
void trabalhoJogo::Fases::Fase::gravitar() {
    //vector<Entidades::Entidade*>::iterator it;
    float dt = Tempo::getSegundos();
    /*for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++)
    {
        (*it)->gravitar(dt);
    }*/
   for(auto it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->gravitar(dt);
}

void trabalhoJogo::Fases::Fase::mover() {
    /*vector<Entidades::Entidade*>::iterator it;
    for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++) {
        (*it)->mover();
    }*/
   for(auto it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->mover();

}

void trabalhoJogo::Fases::Fase::desenhar() {
    /*vector<Entidades::Entidade*>::iterator it;
    for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++) {
        (*it)->desenhar();
    }*/
   for(auto it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->desenhar();
}

void trabalhoJogo::Fases::Fase::executar() {
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
        GC.executar();
        gravitar();
        mover();
        desenhar();
        pGG->renderizar();
    }
}

void trabalhoJogo::Fases::Fase::criarAranhaGigante() {
    const sf::Image image = pGG->getImgInimigos();
    if (!texture.loadFromImage(image, sf::IntRect(3, 184, 12, 8))) {
        std::cerr << "Erro ao carregar imagem em Fase::criarAranha" << std::endl;
    }
    texture.setSmooth(false); // continuar pixelada
    sprite.setTexture(texture);

    Entidades::Personagens::AranhaGigante* aranha = new Entidades::Personagens::AranhaGigante;
    aranha->setDinamico(true);
    aranha->atribuirSprite(&sprite);
    //incluir na lista de entidades
    //temp_lista_ents.push_back(static_cast<Entidades::Entidade*>(aranha)); // FAZER DELETE DEPOIS
    lista_ents.incluir(static_cast<Entidades::Entidade*>(aranha));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(aranha));
}

void trabalhoJogo::Fases::Fase::criarOlhoVoador() {

}

void trabalhoJogo::Fases::Fase::criarBruxa() {

}

void trabalhoJogo::Fases::Fase::criarPlataforma() {

}

void trabalhoJogo::Fases::Fase::criarCogumelo() {

}

void trabalhoJogo::Fases::Fase::criarObstDificil() {

}

void trabalhoJogo::Fases::Fase::criarCenarios() {

}

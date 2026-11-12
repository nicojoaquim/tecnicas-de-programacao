#include "Fase.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Entidades/Entidade.h"

#include "../Entidades/Personagem/AranhaGigante.h"

#include <SFML/Window.hpp>
using sf::Event;
using sf::Keyboard;

#include <vector>
using std::vector;

#include "../organiza.h"

Fase::Fase():
    Ente(),
    GC(),
    lista_ents()
{
}

Fase::~Fase(){
}

void Fase::gravitar() {
    vector<Entidade*>::iterator it;
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
    vector<Entidade*>::iterator it;
    for (it = temp_lista_ents.begin(); it != temp_lista_ents.end(); it++) {
        (*it)->mover();
    }
}

void Fase::desenhar() {
    vector<Entidade*>::iterator it;
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

void Fase::criarAranhaGigante() {
    const sf::Image image = pGG->getImgInimigos();
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromImage(image, sf::IntRect(3, 184, 12, 8))) {
        std::cerr << "Erro ao carregar imagem em Fase::criarAranha" << std::endl;
    }
    texture.setSmooth(false); // continuar pixelada
    sprite.setTexture(texture);

    AranhaGigante* aranha = new AranhaGigante;
    aranha->atribuirSprite(&sprite);
    //incluir na lista de entidades
    temp_lista_ents.push_back(static_cast<Entidade*>(aranha)); // FAZER DELETE DEPOIS
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

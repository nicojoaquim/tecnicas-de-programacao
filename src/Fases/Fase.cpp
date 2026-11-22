#include "Fase.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Chao.h"
#include "../Tilemap.h"

#include "../Entidades/Personagem/AranhaGigante.h"
#include "../Entidades/Personagem/OlhoVoador.h"
#include "../Entidades/Personagem/Bruxa.h"

#include "../Entidades/Obstaculo/Plataforma.h"
#include "../Entidades/Obstaculo/Cogumelo.h"
#include "../Entidades/Obstaculo/Abobora.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>
using sf::Event;
using sf::Keyboard;

#include "../organiza.h"

CMD::Fases::Fase::Fase():
    Ente(),
    GC(),
    lista_ents(),
    tilemap(),
    maxAranhasGicantes(4),
    maxPlataformas(4)
{
    tilemap.calcularTileSize(pGG->getTamanhoJanela());

    // Necessário limpar relógio, pois
    // usaria o tempo decorrido no Menu
    pGT->reiniciarRelogio();
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
void CMD::Fases::Fase::adicionaJog2(Entidades::Personagens::Jogador* jogador2){
        lista_ents.incluir(static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(jogador2)));
        GC.incluirJogador2(jogador2);
    }
void CMD::Fases::Fase::adicionaChao(Entidades::Chao* chao){
    lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
    GC.incluirChao(chao);
}

//void CMD::Fases::Fase::gravitar() {
//    float dt = Tempo::getSegundos();
//    Listas::Lista<Entidades::Entidade>::Iterador it;
//    for(it = lista_ents.inicio(); it != lista_ents.fim();++it)
//        (*it)->gravitar(dt);
//}
//
//void CMD::Fases::Fase::mover() {
//    Listas::Lista<Entidades::Entidade>::Iterador it;
//    for(it = lista_ents.inicio(); it != lista_ents.fim();++it) {
//        (*it)->mover();
//    }
//
//}

void CMD::Fases::Fase::executarEntidades() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim();++it) {
        (*it)->executar();
    }
}

void CMD::Fases::Fase::desenhar() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim();++it)
        (*it)->desenhar();
}

// Mudar para virtual
void CMD::Fases::Fase::executar() {
    Event evento;
    bool jogando = true;
    while (jogando) {
        // Marca o relógio para 0 e armazena
        // tempo decorrido desde o último frame
        pGT->reiniciarRelogio();

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
        executarEntidades();
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

    // tile_size/escala = tamanho_atual/1
    float escala = tilemap.getTileSize() / pAranha->getLargura();
    pAranha->getFig()->setScale(escala, escala);
    pAranha->getFig()->scale(5,5);
}

void CMD::Fases::Fase::criarOlhoVoador() {
    Entidades::Personagens::OlhoVoador* pOlho;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexOlhoVoador());

    pOlho = new Entidades::Personagens::OlhoVoador;
    pOlho->atribuirSprite(pSprite);
    pOlho->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pOlho));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(pOlho));

    // tile_size/escala = tamanho_atual/1
    float escala = tilemap.getTileSize() / pOlho->getLargura();
    pOlho->getFig()->setScale(escala, escala);
    const sf::Vector2u tamanhoJanela = pGG->getTamanhoJanela();
    pOlho->getFig()->setPosition(
        tamanhoJanela.x / 2.f,
        tamanhoJanela.y / 3.f
    );
    pOlho->getFig()->scale(5,5);
}

void CMD::Fases::Fase::criarBruxa() {
    Entidades::Personagens::Bruxa* pBruxa;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexBruxa());

    pBruxa = new Entidades::Personagens::Bruxa;
    pBruxa->atribuirSprite(pSprite);
    pBruxa->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pBruxa));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(pBruxa));

    // tile_size/escala = tamanho_atual/1
    float escala = tilemap.getTileSize() / pBruxa->getLargura();
    pBruxa->getFig()->setScale(escala, escala);
    pBruxa->getFig()->scale(5,5);
}

void CMD::Fases::Fase::criarPlataforma() {
    Entidades::Obstaculos::Plataforma* pPlataforma;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexPlataforma());

    pPlataforma = new Entidades::Obstaculos::Plataforma;
    pPlataforma->atribuirSprite(pSprite);
    pPlataforma->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlataforma));
    GC.incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pPlataforma));

    // tile_size/escala = tamanho_atual/1
    float escala = tilemap.getTileSize() / pPlataforma->getLargura();
    pPlataforma->getFig()->setScale(escala, escala);
    pPlataforma->getFig()->scale(5,5);
}

void CMD::Fases::Fase::criarCogumelo() {
   Entidades::Obstaculos::Cogumelo* pCogumelo;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexCogumelo());

    pCogumelo = new Entidades::Obstaculos::Cogumelo;
    pCogumelo->atribuirSprite(pSprite);
    pCogumelo->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pCogumelo));
    GC.incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pCogumelo));

    // tile_size/escala = tamanho_atual/1
    float escala = tilemap.getTileSize() / pCogumelo->getLargura();
    pCogumelo->getFig()->setScale(escala, escala);
    pCogumelo->getFig()->scale(5,5);
}

void CMD::Fases::Fase::criarAbobora() {
    Entidades::Obstaculos::Abobora* pAbobora;
    sf::Sprite* pSprite;

    pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexAbobora());

    pAbobora = new Entidades::Obstaculos::Abobora;
    pAbobora->atribuirSprite(pSprite);
    pAbobora->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pAbobora));
    GC.incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pAbobora));

    // tile_size/escala = tamanho_atual/1
    float escala = tilemap.getTileSize() / pAbobora->getLargura();
    pAbobora->getFig()->setScale(escala, escala);
    pAbobora->getFig()->scale(5,5);
}

void CMD::Fases::Fase::criarCenarios() {

}

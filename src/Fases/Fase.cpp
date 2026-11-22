#include "Fase.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Chao.h"
#include "../Tilemap.h"

#include "../Entidades/Personagem/AranhaGigante.h"

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

void CMD::Fases::Fase::incluirJogador(Entidades::Personagens::Jogador* jogador) {
    if (jogador == NULL)
        return;

    if (pJog1 == NULL)
        pJog1 = jogador;
    else
        pJog2 = jogador;

    lista_ents.incluir(static_cast<Entidades::Entidade*>(static_cast<Entidades::Personagens::Personagem*>(jogador)));
    GC.incluirJogador(jogador);

    const float escala = 2 * tilemap.getTileSize() / (float) jogador->getAltura();
    jogador->getFig()->setScale(escala, escala);

    jogador->setPosicao(tilemap.getCentroTile({tilemap.getLargura()/2, tilemap.getAltura()/2}));
}

void CMD::Fases::Fase::adicionaChao(Entidades::Chao* chao){
    lista_ents.incluir(static_cast<Entidades::Entidade*>(chao));
    GC.incluirChao(chao);
}

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
    delete pE; // Entidade
}

void CMD::Fases::Fase::criarAranhaGigante(sf::Vector2u pos) {
    Entidades::Personagens::AranhaGigante* pAranha;
    pAranha = new Entidades::Personagens::AranhaGigante;
    pAranha->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pAranha));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(pAranha));

    // tile_size/escala = tamanho_atual/1
    // n.º de tile que ocupa no comprimento máximo está implementada na própria classe, 4*escala
    float escala = tilemap.getTileSize() / pAranha->getLargura();
    pAranha->getFig()->scale(escala, escala);

    //pAranha->setPosicao(pos); TILEMAP VAI FAZER ISSO
    tilemap.incluir(ARANHA, pos);
}

void CMD::Fases::Fase::criarOlhoVoador(sf::Vector2u pos) {

}

void CMD::Fases::Fase::criarBruxa(sf::Vector2u pos) {

}

void CMD::Fases::Fase::criarPlataforma(sf::Vector2u pos) {

}

void CMD::Fases::Fase::criarAbobora(sf::Vector2u pos) {

}

void CMD::Fases::Fase::criarCogumelo(sf::Vector2u pos) {

}

void CMD::Fases::Fase::criarCenario() {
    const float tam_tile = tilemap.getTileSize();
    const float escala = 1 * tam_tile / 16;
    sf::Vector2u pos;
    Tile tipo;
    Entidades::Chao* pChao;

    for (pos.x = 0; pos.x < tilemap.getLargura(); pos.x++) {
        for (pos.y = 0; pos.y < tilemap.getAltura(); pos.y++) {
            tipo = tilemap.getTile(pos);
            if (tipo == VAZIO)
                continue;
            else if (tipo >= RAM0 && tipo <= CPU11) {
                // Criar chão a partir da posição no tilemap
                pChao = new Entidades::Chao(tipo);
                pChao->getFig()->setScale(escala, escala);
                pChao->setPosicao(tilemap.getCentroTile(pos));
                // Incluir chão na lista de entidades
                lista_ents.incluir(static_cast<Entidades::Entidade*>(pChao));
                GC.incluirChao(pChao);
            }
            else {
                std::cerr << "Nenhum tipo além de chão implementado em Fase::criarCenario"
                          << ", " << tipo
                          << std::endl;
            }
        }
    }
}

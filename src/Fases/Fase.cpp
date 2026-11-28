#include "Fase.h"

#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../Tilemap.h"

#include "../Entidades/Entidade.h"
#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Personagem/Inimigo.h"
#include "../Entidades/Personagem/AranhaGigante.h"
#include "../Entidades/Personagem/OlhoVoador.h"
#include "../Entidades/Personagem/Bruxa.h"
#include "../Entidades/Obstaculo/Plataforma.h"
#include "../Entidades/Obstaculo/Abobora.h"
#include "../Entidades/Obstaculo/Cogumelo.h"
#include "../Entidades/Projetil.h"
#include "../Entidades/Chao.h"

#include "../organiza.h"

CMD::Fases::Fase::Fase():
    Ente(),
    GC(),
    lista_ents(),
    tilemap(),
    pJog1(NULL),
    pJog2(NULL),
    maxAranhasGigantes(6),
    maxPlataformas(5)
{
    tilemap.calcularTileSize(pGG->getTamanhoJanela());
    ///*
    std::cout << "Fase criada, tamanho_janela: "
              << pGG->getTamanhoJanela().x << " x " << pGG->getTamanhoJanela().y
              << "\ntile_size: " << tilemap.getTileSize()
              << std::endl;
    //*/

    // Necessário limpar relógio, pois
    // usaria o tempo decorrido no Menu
    pGT->reiniciarRelogio();

    // https://en.cppreference.com/cpp/numeric/random/srand
    std::srand(std::time(NULL));
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

    atualizarAlvosBruxas();

    const float escala = 2 * tilemap.getTileSize() / (float) jogador->getAltura();
    jogador->getFig()->setScale(escala, escala);
    std::cout << "Fase::incluirJogador() setScale " << escala << std::endl;

    const sf::Vector2u posicao =
        (pJog1 == jogador)
        ? sf::Vector2u{tilemap.getLargura()/3, tilemap.getAltura()/2}
        : sf::Vector2u{tilemap.getLargura()*2/3, tilemap.getAltura()/2};
    jogador->setPosicao(tilemap.getCentroTile(posicao));
}

void CMD::Fases::Fase::executarEntidades() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    // Entidades::Personagens::Personagem* personagem;
    // for(it = lista_ents.inicio(); it != lista_ents.fim();++it) {
    //     personagem = dynamic_cast<Entidades::Personagens::Personagem*>(*it);
    //     if (personagem != NULL && personagem->getNumVida() <= 0)
    //         continue;
    //     (*it)->executar();
    // }

    for (it = lista_ents.inicio(); it != lista_ents.fim(); ++it) {
        if (*it != NULL)
            (*it)->executar();
    }
}

// void CMD::Fases::Fase::atualizarAlvosBruxas() {
//     Listas::Lista<Entidades::Entidade>::Iterador it;
//     // Entidades::Personagens::Personagem* personagem;
//     // for(it = lista_ents.inicio(); it != lista_ents.fim();++it) {
//     //     personagem = dynamic_cast<Entidades::Personagens::Personagem*>(*it);
//     //     if (personagem != NULL && personagem->getNumVida() <= 0)
//     //         continue;
//     //     (*it)->executar();
//     // }

//     for (it = lista_ents.inicio(); it != lista_ents.fim(); ++it) {
//         if (*it != NULL)
//             (*it)->executar();
//     }
// }

void CMD::Fases::Fase::atualizarAlvosBruxas() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for (it = lista_ents.inicio(); it != lista_ents.fim(); ++it) {
        Entidades::Personagens::Bruxa* bruxa =
            dynamic_cast<Entidades::Personagens::Bruxa*>(*it);
        if (bruxa != NULL)
            bruxa->setAlvos(pJog1, pJog2);
    }
}

void CMD::Fases::Fase::desenhar() {
    Listas::Lista<Entidades::Entidade>::Iterador it;
    for(it = lista_ents.inicio(); it != lista_ents.fim();++it) {
        Entidades::Projetil* projetil =
            dynamic_cast<Entidades::Projetil*>(*it);
        if (projetil != NULL && !projetil->estaAtivo())
            continue;
        Entidades::Personagens::Personagem* personagem =
            dynamic_cast<Entidades::Personagens::Personagem*>(*it);
        if (personagem != NULL && personagem->getNumVida() <= 0)
            continue;
        (*it)->desenhar();
    }
}

void CMD::Fases::Fase::desenharVidas() {
    if (pJog1 == NULL)
        return;

    sf::Text vidas;
    vidas.setFont(pGG->getFonte());
    vidas.setCharacterSize(36);
    vidas.setFillColor(sf::Color::White);
    vidas.setOutlineColor(sf::Color::Black);
    vidas.setOutlineThickness(2.f);
    vidas.setPosition(20.f, 20.f);

    std::string texto =
        "Jogador 1: Vidas: " + std::to_string(pJog1->getNumVida());
    if (pJog2 != NULL)
        texto += "   Jogador 2: Vidas: " + std::to_string(pJog2->getNumVida());

    vidas.setString(texto);
    pGG->desenharTexto(vidas);
}


void CMD::Fases::Fase::removerInimigosMortos() {
    bool removeuInimigo;
    do {
        removeuInimigo = false;
        Listas::Lista<Entidades::Entidade>::Iterador it;
        for (it = lista_ents.inicio(); it != lista_ents.fim(); ++it) {
            Entidades::Personagens::Inimigo* inimigo =
                dynamic_cast<Entidades::Personagens::Inimigo*>(*it);
            if (inimigo != NULL && inimigo->getNumVida() <= 0) {
                GC.removerInimigo(inimigo);
                lista_ents.remover(*it);
                destruirEntidade(inimigo);
                removeuInimigo = true;
                break;
            }
        }
    } while (removeuInimigo);
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
    float escala = 2 * tilemap.getTileSize() / pAranha->getLargura();
    pAranha->getFig()->setScale(escala, escala);

    pAranha->setPosicao(tilemap.getCentroTile(pos));
}

void CMD::Fases::Fase::criarOlhoVoador(sf::Vector2u pos) {
    Entidades::Personagens::OlhoVoador* pOlho;
    pOlho = new Entidades::Personagens::OlhoVoador;
    pOlho->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pOlho));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(pOlho));

    // tile_size/escala = tamanho_atual/1
    float escala = 3 * tilemap.getTileSize() / pOlho->getLargura();
    pOlho->getFig()->setScale(escala, escala);

    /*
    const sf::Vector2u tamanhoJanela = pGG->getTamanhoJanela();
    pOlho->getFig()->setPosition(
        tamanhoJanela.x / 2.f,
        tamanhoJanela.y / 3.f
    );
    */

    pOlho->setPosicao(tilemap.getCentroTile(pos));
}

void CMD::Fases::Fase::criarBruxa(sf::Vector2u pos) {
    Entidades::Personagens::Bruxa* pBruxa;
    pBruxa = new Entidades::Personagens::Bruxa;
    pBruxa->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pBruxa));
    GC.incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(pBruxa));

    // tile_size/escala = tamanho_atual/1
    float escala = 3 * tilemap.getTileSize() / pBruxa->getLargura();
    pBruxa->getFig()->setScale(escala, escala);

    pBruxa->setPosicao(tilemap.getCentroTile(pos));
    criarProjetil(pos, pBruxa);
}

void CMD::Fases::Fase::criarProjetil(sf::Vector2u pos,
                                     Entidades::Personagens::Bruxa* pBruxa)
{
    Entidades::Projetil* pProjetil;
    pProjetil = new Entidades::Projetil;
    pProjetil->setDinamico(true);

    float escala = tilemap.getTileSize() / 16.f;
    pProjetil->getFig()->setScale(escala, escala);
    pProjetil->setPosicao(tilemap.getCentroTile(pos));

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pProjetil));
    GC.incluirProjetil(pProjetil);

    pBruxa->setProjetil(pProjetil);
}

void CMD::Fases::Fase::criarPlataforma(sf::Vector2u pos) {
    Entidades::Obstaculos::Plataforma* pPlataforma;
    pPlataforma = new Entidades::Obstaculos::Plataforma;
    pPlataforma->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlataforma));
    GC.incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pPlataforma));

    // tile_size/escala = tamanho_atual/1
    float escala = 2 * tilemap.getTileSize() / pPlataforma->getLargura();
    pPlataforma->getFig()->setScale(escala, escala);

    pPlataforma->setPosicao(tilemap.getCentroTile(pos));

    Listas::Lista<Entidades::Entidade>::Iterador it;
    bool encontrouAranha = false;
    Entidades::Personagens::AranhaGigante* aranha;
    for (it = lista_ents.inicio(); it != lista_ents.fim() && !encontrouAranha; ++it) {
        aranha = dynamic_cast<Entidades::Personagens::AranhaGigante*>(*it);
        if (aranha != NULL && !aranha->getNaPlataforma()) {
            aranha->setPosicao({
                pPlataforma->getX(),
                pPlataforma->getY()
                    - (pPlataforma->getAltura() + aranha->getAltura()) / 2.f
            });
            encontrouAranha = true;
            aranha->serNaPlataforma(true);
            //aranha->perderPlataforma();
        }
    }
}

void CMD::Fases::Fase::criarAbobora(sf::Vector2u pos) {
    Entidades::Obstaculos::Abobora* pAbobora;
    pAbobora = new Entidades::Obstaculos::Abobora;
    pAbobora->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pAbobora));
    GC.incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pAbobora));

    // tile_size/escala = tamanho_atual/1
    float escala = 3 * tilemap.getTileSize() / pAbobora->getLargura();
    pAbobora->getFig()->setScale(escala, escala);

    pAbobora->setPosicao(tilemap.getCentroTile(pos));
}

void CMD::Fases::Fase::criarCogumelo(sf::Vector2u pos) {
    Entidades::Obstaculos::Cogumelo* pCogumelo;
    pCogumelo = new Entidades::Obstaculos::Cogumelo;
    pCogumelo->setDinamico(true);

    lista_ents.incluir(static_cast<Entidades::Entidade*>(pCogumelo));
    GC.incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pCogumelo));

    // tile_size/escala = tamanho_atual/1
    float escala = 3 * tilemap.getTileSize() / pCogumelo->getLargura();
    pCogumelo->getFig()->setScale(escala, escala);

    pCogumelo->setPosicao(tilemap.getCentroTile(pos));
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
            else if (tipo == JOG1) {
                if (pJog1 != NULL)
                    pJog1->setPosicao(tilemap.getCentroTile(pos));
                else
                    std::cerr << "Jogador 1 nulo em Fase::criarCenario" << std::endl;
            }
            else if (tipo == JOG2) {
                if (pJog2 != NULL)
                    pJog2->setPosicao(tilemap.getCentroTile(pos));
            }
            else if (tipo >= RAM0 && tipo <= CPU11) {
                // Criar chão a partir da posição no tilemap
                pChao = new Entidades::Chao(tipo);
                pChao->getFig()->setScale(escala, escala);
                pChao->setPosicao(tilemap.getCentroTile(pos));
                // Incluir chão na lista de entidades
                lista_ents.incluir(static_cast<Entidades::Entidade*>(pChao));
                GC.incluirChao(pChao);
            }
            else if (tipo == INVALIDO) {
                /// TODO TEMPORÁRIO
                pChao = new Entidades::Chao(CPU2);
                sf::Texture* pT = new sf::Texture;
                pT->loadFromFile("assets/imagens/retro-lines.png", sf::IntRect(96, 64, 16, 16));
                pChao->getFig()->setTexture(*pT, true);
                pChao->getFig()->setScale(escala, escala);
                pChao->setPosicao(tilemap.getCentroTile(pos));
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

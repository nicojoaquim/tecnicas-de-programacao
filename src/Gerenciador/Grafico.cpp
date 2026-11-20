#include "Grafico.h"
#include "../Ente.h"

#include "../organiza.h"

using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::RenderWindow;


CMD::Gerenciador::Grafico::Grafico():
    janela(),
    fonte(),
    img(),
    texJogador1(),
    texJogador2(),
    texAranhaGigante(),
    texOlhoVoador(),
    texBruxa(),
    texProjetil(),
    texPlataforma(),
    texAbobora(),
    texCogumelo(),
    texAmbienteRAM(),
    texAmbienteCPU()
{
    VideoMode video_mode = VideoMode::getDesktopMode();
    //int estilo_janela = sf::Style::Close; // Barra de título e botão de fechar
    int estilo_janela = sf::Style::Default;
    janela.create(video_mode, NOME_JANELA, estilo_janela);
    janela.clear(Color::Black);
    janela.display();

    try {
        inicializarFontes();
        inicializarImagens();
        inicializarTexturas();
    }
    catch (const char * arquivo) {
        std::cout << "Erro: não foi possível carregar: "
                  << arquivo
                  << std::endl;
        fechar();
    }
}

CMD::Gerenciador::Grafico::~Grafico(){

}

void CMD::Gerenciador::Grafico::desenharEnte(Ente *pE)
{
    if (pE == NULL) {
        std::cerr << "Nulidade em GG::desenharEnte" << std::endl;
    }
    else {
        janela.draw(*pE->getFig());
    }
}

void CMD::Gerenciador::Grafico::desenharTexto(const sf::Text& texto){
    janela.draw(texto);
}

const bool CMD::Gerenciador::Grafico::aberto() const {
    if(janela.isOpen())
        return true;
    return false;
}

void CMD::Gerenciador::Grafico::renderizar(){
    janela.display();
}

void CMD::Gerenciador::Grafico::limpar(){
    janela.clear();
}
/*
void Grafico::executar()
{
    Eent evento;
    // adaptado do tutorial do SFML 2.6
    // para cada evento novo desde a última vez que passou pelo loop
    while (janela.pollEvent(evento))
    {
        // evento de fechar a janela
        if (evento.type == Event::Closed)
            janela.close();
    }
}
*/

bool CMD::Gerenciador::Grafico::getEvento(sf::Event& evento) {
    return janela.pollEvent(evento);
}

void CMD::Gerenciador::Grafico::fechar() {
    janela.close();
}

const sf::Vector2u CMD::Gerenciador::Grafico::getTamanhoJanela() const {
    return janela.getSize();
}

sf::RenderWindow& CMD::Gerenciador::Grafico::getJanela() {
    return janela;
}

const sf::Image& CMD::Gerenciador::Grafico::getImg() const {
    return img;
}

// ==========================================
// inicializar imagem, texturas etc, fazem throw para try catch

void CMD::Gerenciador::Grafico::inicializarFontes() {
    bool sucesso = fonte.loadFromFile(FONTE);
    if (!sucesso)
        throw FONTE;
}

void CMD::Gerenciador::Grafico::inicializarImagens() {
    bool sucesso = img.loadFromFile(RETRO_LINES);
    if (!sucesso)
        throw RETRO_LINES;
}

void CMD::Gerenciador::Grafico::inicializarTexturas() {
    // Jogadores
    if (!texJogador1.loadFromImage(getImg(), sf::IntRect(16, 16, 9, 14)))
        throw "Jogador 1";
    if (!texJogador2.loadFromImage(getImg(), sf::IntRect(16, 30, 9, 14)))
        throw "Jogador 2";

    // Inimigos
    if (!texAranhaGigante.loadFromImage(getImg(), sf::IntRect(16, 115, 12, 8)))
        throw "AranhaGigante";
    if (!texOlhoVoador.loadFromImage(getImg(), sf::IntRect(52, 96, 12, 12)))
        throw "OlhoVoador";
    if (!texBruxa.loadFromImage(getImg(), sf::IntRect(16, 176, 37, 39)))
        throw "Bruxa";

    // Projétil
    if (!texProjetil.loadFromImage(getImg(), sf::IntRect(16, 96, 7, 19)))
        throw "Projétil";

    // Obstáculos
    if (!texPlataforma.loadFromImage(getImg(), sf::IntRect(80, 64, 16, 9)))
        throw "Plataforma";
    if (!texAbobora.loadFromImage(getImg(), sf::IntRect(16, 130, 13, 14)))
        throw "Abóbora";
    if (!texCogumelo.loadFromImage(getImg(), sf::IntRect(51, 138, 13, 6)))
        throw "Cogumelo";

    // Chão, parede etc de ambas fases
    if (!texAmbienteRAM[0].loadFromImage(getImg(), sf::IntRect(16, 160, 16, 16))     // base cima
        || !texAmbienteRAM[1].loadFromImage(getImg(), sf::IntRect(80, 224, 16, 16))  // base baixo
        || !texAmbienteRAM[2].loadFromImage(getImg(), sf::IntRect(0, 176, 16, 16))   // base esq
        || !texAmbienteRAM[3].loadFromImage(getImg(), sf::IntRect(96, 224, 16, 16))  // base dir
        || !texAmbienteRAM[4].loadFromImage(getImg(), sf::IntRect(0, 160, 16, 16))   // canto sup esq ext
        || !texAmbienteRAM[5].loadFromImage(getImg(), sf::IntRect(64, 160, 16, 16))  // canto sup dir ext
        || !texAmbienteRAM[6].loadFromImage(getImg(), sf::IntRect(0, 224, 16, 16))   // canto inf esq ext
        || !texAmbienteRAM[7].loadFromImage(getImg(), sf::IntRect(64, 224, 16, 16))  // canto inf dir ext
        || !texAmbienteRAM[8].loadFromImage(getImg(), sf::IntRect(80, 192, 16, 16))  // canto sup esq int
        || !texAmbienteRAM[9].loadFromImage(getImg(), sf::IntRect(96, 192, 16, 16))  // canto sup dir int
        || !texAmbienteRAM[10].loadFromImage(getImg(), sf::IntRect(80, 208, 16, 16)) // canto inf esq int
        || !texAmbienteRAM[11].loadFromImage(getImg(), sf::IntRect(96, 208, 16, 16)))// canto inf dir int
    {
        throw "Ambiente da fase 1";
    }
    if (!texAmbienteCPU[0].loadFromImage(getImg(), sf::IntRect(16, 80, 16, 16))      // base cima
        || !texAmbienteCPU[1].loadFromImage(getImg(), sf::IntRect(80, 144, 16, 16))  // base baixo
        || !texAmbienteCPU[2].loadFromImage(getImg(), sf::IntRect(0, 96, 16, 16))    // base esq
        || !texAmbienteCPU[3].loadFromImage(getImg(), sf::IntRect(96, 144, 16, 16))  // base dir
        || !texAmbienteCPU[4].loadFromImage(getImg(), sf::IntRect(0, 80, 16, 16))    // canto sup esq ext
        || !texAmbienteCPU[5].loadFromImage(getImg(), sf::IntRect(64, 80, 16, 16))   // canto sup dir ext
        || !texAmbienteCPU[6].loadFromImage(getImg(), sf::IntRect(0, 144, 16, 16))   // canto inf esq ext
        || !texAmbienteCPU[7].loadFromImage(getImg(), sf::IntRect(64, 144, 16, 16))  // canto inf dir ext
        || !texAmbienteCPU[8].loadFromImage(getImg(), sf::IntRect(80, 112, 16, 16))  // canto sup esq int
        || !texAmbienteCPU[9].loadFromImage(getImg(), sf::IntRect(96, 112, 16, 16))  // canto sup dir int
        || !texAmbienteCPU[10].loadFromImage(getImg(), sf::IntRect(80, 128, 16, 16)) // canto inf esq int
        || !texAmbienteCPU[11].loadFromImage(getImg(), sf::IntRect(96, 128, 16, 16)))// canto inf dir int
    {
        throw "Ambiente da fase 2";
    }

    // setSmooth(false) serve para deixar a
    // imagem pixelada quando aplicado scale
    texJogador1.setSmooth(false);
    texJogador2.setSmooth(false);
    texAranhaGigante.setSmooth(false);
    texOlhoVoador.setSmooth(false);
    texBruxa.setSmooth(false);
    texProjetil.setSmooth(false);
    texPlataforma.setSmooth(false);
    texAbobora.setSmooth(false);
    texCogumelo.setSmooth(false);
    for (int i = 0; i < TIPOS_TILES_CHAO; i++) {
        texAmbienteRAM[i].setSmooth(false);
        texAmbienteCPU[i].setSmooth(false);
    }
}

// ==========================================
// getTex... e getFonte

const sf::Font& CMD::Gerenciador::Grafico::getFonte() const {
    return fonte;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexJogador1() const {
    return texJogador1;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexJogador2() const {
    return texJogador2;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAranhaGigante() const {
    return texAranhaGigante;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexOlhoVoador() const {
    return texOlhoVoador;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexBruxa() const {
    return texBruxa;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexProjetil() const {
    return texProjetil;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexPlataforma() const {
    return texPlataforma;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAbobora() const {
    return texAbobora;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexCogumelo() const {
    return texCogumelo;
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAmbienteRAM(int canto) const {
    if (canto >= 0 && canto < TIPOS_TILES_CHAO)
        return texAmbienteRAM[canto];
    else
        return texAmbienteRAM[0];
}

const sf::Texture& CMD::Gerenciador::Grafico::getTexAmbienteCPU(int canto) const {
    if (canto >= 0 && canto < TIPOS_TILES_CHAO)
        return texAmbienteCPU[canto];
    else
        return texAmbienteCPU[0];
}


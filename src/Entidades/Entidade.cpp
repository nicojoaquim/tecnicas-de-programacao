#include "Entidade.h"

#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Tempo.h"
#include "../organiza.h"

using sf::Vector2f;
using sf::Sprite;

CMD::Entidades::Entidade::Entidade():
    //buffer(std::cout),
    buffer(),
    velocidade({0,0}),
    dinamico(false)
{
}

CMD::Entidades::Entidade::~Entidade()
{
}

void CMD::Entidades::Entidade::atribuirSprite(Sprite* Fig) {
    if (Fig == NULL) {
        std::cerr << "Nulidade em atribuirSprite" << std::endl;
        return;
    }
    setFig(Fig);

    Vector2f centro(getLargura()/2.0f, getAltura()/2.0f);

    pFig->setOrigin(centro.x, centro.y);
    setPosicao(getPosicao()+centro);
}

void CMD::Entidades::Entidade::salvarDataBuffer() {
    buffer << "#" << getId() << "\nEntidade\n"
           << getDinamico() << "\n"
           << getX() << " " << getY() << "\n"
           << getV().x << " " << getV().y << "\n";
}

void CMD::Entidades::Entidade::carregarDataBuffer() {
    int id_save;
    buffer >> id_save;
    setId(id_save);

    std::string str;
    buffer >> str;
    if (str != std::string("Entidade")) {
        std::cerr << "erro: dados inválidos em Entidade::carregarDataBuffer()" << std::endl;
        return;
    }

    bool din;
    buffer >> din;
    setDinamico(din);

    float x, y;

    buffer >> x >> y;
    setPosicao({x, y});

    buffer >> x >> y;
    setV({x, y});
}

const Vector2f CMD::Entidades::Entidade::getPosicao() const {
    if (pFig != NULL)
        return pFig->getPosition();
    else {
        std::cerr << "Erro: Figura inexistente em getPosicao" << std::endl;
        return INEXISTENTE;
    }
}

const float CMD::Entidades::Entidade::getX() const {
    return Entidade::getPosicao().x;
}

const float CMD::Entidades::Entidade::getY() const {
    return Entidade::getPosicao().y;
}

void CMD::Entidades::Entidade::setVy(float y) {
    velocidade.y = y;
}

void CMD::Entidades::Entidade::setVx(float x) {
    velocidade.x = x;
}

const sf::Vector2f CMD::Entidades::Entidade::getV() const{
    return velocidade;
}

void CMD::Entidades::Entidade::setV(const sf::Vector2f v){
    velocidade = v;
}

void CMD::Entidades::Entidade::setPosicao(const Vector2f posicao) {
    if (pFig != NULL)
        pFig->setPosition(posicao);
    else
        std::cerr << "Erro: Figura inexistente em setPosicao" << std::endl;
}

const Vector2f CMD::Entidades::Entidade::getTamanho() const {
    if (pFig != NULL)
        // TODO ver se getSize() == getGlobalBounds().width e .height
        // Estava em atribuirSprite:
        // sf::FloatRect cent = pFig->getGlobalBounds();
        // pFig->setOrigin(cent.width/2.0f,cent.height/2.0f);
        return pFig->getGlobalBounds().getSize();
    else {
        std::cerr << "Erro: Figura inexistente em getTamanho" << std::endl;
        return INEXISTENTE;
    }
}

const float CMD::Entidades::Entidade::getLargura() const {
    return getTamanho().x;
}

const float CMD::Entidades::Entidade::getAltura() const {
    return getTamanho().y;
}
void CMD::Entidades::Entidade::setDinamico(bool dim) {
    dinamico = dim;
}
const bool CMD::Entidades::Entidade::getDinamico() const {
    return dinamico;
}

void CMD::Entidades::Entidade::mover(sf::Vector2f movimento) {
    pFig->move(movimento.x, movimento.y);
}
// baseado em https://gafferongames.com/post/integration_basics/
void CMD::Entidades::Entidade::gravitar() {
    /*if (esta_no_chao)
      return;*/

    float dt = Gerenciador::Tempo::getSegundos(); // s
    float velocidade_max = 1200.f; // pixel/s
    float aceleracao = 1200.f; // pixel/s²

    velocidade.y += aceleracao*dt;

    if(velocidade.y > velocidade_max)
        velocidade.y = velocidade_max;

    getFig()->move({0,velocidade.y*dt});
}
//sf::Vector2f& CMD::Entidades::Entidade::operator+=(sf::Vector2f& movimento) {
//    setPosicao(getPosicao()+movimento);
//    return this->getPosicao();
//}

#include "Cogumelo.h"
#include "../Personagem/Jogador.h"
#include "../../Gerenciador/Grafico.h"
#include "../../Gerenciador/Tempo.h"
#include "../../organiza.h"

CMD::Entidades::Obstaculos::Cogumelo::Cogumelo():
    Obstaculo(),
    densidade(-1),
    escalaInicial(1.f, 1.f),
    fatorEscala(1.f),
    escalaMaxima(1.8f),
    velocidadeCrescimento(0.4f),
    escalaInicializada(false),
    crescendo(true),
    cooldownDano()
{
    danoso = true;

    sf::Sprite* pSprite = new sf::Sprite;
    pSprite->setTexture(pGG->getTexCogumelo());
    atribuirSprite(pSprite);
}

CMD::Entidades::Obstaculos::Cogumelo::~Cogumelo() {
    if (getFig() != NULL)
        delete getFig();
}

void CMD::Entidades::Obstaculos::Cogumelo::executar()
{
    gravitar();
    const float dt = Gerenciador::Tempo::getSegundos();
    for (std::map<Personagens::Jogador*, float>::iterator it = cooldownDano.begin();
         it != cooldownDano.end(); ++it) {
        it->second = std::max(0.f, it->second - dt);
    }

    acao();
}

void CMD::Entidades::Obstaculos::Cogumelo::obstaculizar(Personagens::Jogador *p)
{
    if (p== NULL) {
        std::cerr << "Jogador  nulo" << std::endl;
        return;
    }

    const float dx = p->getX() - getX();
    const float dy = p->getY() - getY();
    const float interx =
        (p->getLargura() + getLargura()) / 2.f - std::abs(dx);
    const float intery =
        (p->getAltura() + getAltura()) / 2.f - std::abs(dy);

    if (interx > 0.f && intery > 0.f) {
        std::map<Personagens::Jogador*, float>::iterator cooldown =
            cooldownDano.find(p);
        if (danoso
            && (cooldown == cooldownDano.end() || cooldown->second <= 0.f)) {
            p->operator--();
            cooldownDano[p] = 1.f;
        }

        if (interx < intery) {
            if (dx < 0.f) {
                p->setPosicao({ p->getX() - interx, p->getY() });
            } else {
                p->setPosicao({ p->getX() + interx, p->getY() });
            }
            velocidade.x = 0.f;
        }
        else {
            if (dy < 0.f) {
                p->setPosicao({ p->getX(), p->getY() - intery });
            } else {
                p->setPosicao({ p->getX(), p->getY() + intery });
            }
            velocidade.y = 0.f;
        }
    }
}
void CMD::Entidades::Obstaculos::Cogumelo::salvar(){

}

void CMD::Entidades::Obstaculos::Cogumelo::acao(){
    if (getFig() == NULL)
        return;

    if (!escalaInicializada) {
        escalaInicial = getFig()->getScale();
        escalaInicializada = true;
    }

    const float posicaoBaseY = getY() + getAltura() / 2.f;
    const float dt = Gerenciador::Tempo::getSegundos();
    const float variacao = velocidadeCrescimento * dt;
    if (crescendo) {
        fatorEscala += variacao;
        if (fatorEscala >= escalaMaxima) {
            fatorEscala = escalaMaxima;
            crescendo = false;
        }
    } else {
        fatorEscala -= variacao;
        if (fatorEscala <= 1.f) {
            fatorEscala = 1.f;
            crescendo = true;
        }
    }

    getFig()->setScale(
        escalaInicial.x * fatorEscala,
        escalaInicial.y * fatorEscala
    );
    setPosicao({ getX(), posicaoBaseY - getAltura() / 2.f });

}

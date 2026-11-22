#include "Plataforma.h"
#include "../Personagem/Jogador.h"
#include "../../Gerenciador/Tempo.h"
#include "../../Gerenciador/Grafico.h"
#include "../../organiza.h"

CMD::Entidades::Obstaculos::Plataforma::Plataforma():
    Obstaculo(),
    altura(-1),
    posicaoInicial(0.f, 0.f),
    posicaoInicialDefinida(false),
    jogadoresSobre()
{
}

CMD::Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void CMD::Entidades::Obstaculos::Plataforma::executar()
{
    gravitar();
    acao();
}

void CMD::Entidades::Obstaculos::Plataforma::obstaculizar(Personagens::Jogador *p)
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
                p->setEstaNoChao(true);
                p->setVy(0.f);
                if (std::find(jogadoresSobre.begin(), jogadoresSobre.end(), p)
                    == jogadoresSobre.end()) {
                    jogadoresSobre.push_back(p);
                }
            } else {
                p->setPosicao({ p->getX(), p->getY() + intery });
                p->setVy(0.f);
            }
        }
    }
}
void CMD::Entidades::Obstaculos::Plataforma::salvar(){

}
//em resumo a ação da plataforma é ir contra a gravidade, e se um jogador subir ela desce um pouco
void CMD::Entidades::Obstaculos::Plataforma::acao(){
    if (!posicaoInicialDefinida) {
        posicaoInicial = getPosicao();
        posicaoInicialDefinida = true;
    }

    const float dt = Gerenciador::Tempo::getSegundos();
    const float deslocamentoMaximo = 12.f;
    const float velocidadeRetorno = 180.f;
    bool jogadorApoiando = false;
    for (std::vector<Personagens::Jogador*>::iterator it = jogadoresSobre.begin();
         it != jogadoresSobre.end();) {
        Personagens::Jogador* jogador = *it;
        const float diferencaX = std::abs(jogador->getX() - getX());
        const float folgaHorizontal =
            (jogador->getLargura() + getLargura()) / 2.f;
        const float topoPlataforma = getY() - getAltura() / 2.f;
        const float baseJogador = jogador->getY() + jogador->getAltura() / 2.f;
        const float distanciaVertical = topoPlataforma - baseJogador;

        if (diferencaX < folgaHorizontal
            && distanciaVertical >= -2.f
            && distanciaVertical <= 20.f
            && jogador->getV().y >= 0.f) {
            jogadorApoiando = true;
            ++it;
        } else {
            it = jogadoresSobre.erase(it);
        }
    }

    const float alvoY = posicaoInicial.y + (jogadorApoiando ? deslocamentoMaximo : 0.f);
    const float diferencaY = alvoY - getY();
    const float passo = velocidadeRetorno * dt;

    if (std::abs(diferencaY) <= passo) {
        setPosicao({ posicaoInicial.x, alvoY });
    } else {
        setPosicao({
            posicaoInicial.x,
            getY() + (diferencaY > 0.f ? passo : -passo)
        });
    }

    velocidade.y = 0.f;
}

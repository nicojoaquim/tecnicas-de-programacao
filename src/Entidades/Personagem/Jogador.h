#include "Personagem.h"

using std::cerr;
using std:: endl;
using sf::Keyboard;

class Inimigo;

class Jogador:public Personagem
{
protected:
    int pontos;
public:
    Jogador();
    ~Jogador();
    bool colidir(Inimigo* pIn);
    void executar();
    void salvar();
    void mover();//talvez seje virtual no futuro
};

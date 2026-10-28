#include"Personagem.h"
class Inimigo;
using std::cerr;
using std:: endl;
using sf::Keyboard;
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

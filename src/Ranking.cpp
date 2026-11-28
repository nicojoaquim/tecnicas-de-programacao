#include "Ranking.h"

#include <cerrno>
#include <fstream>
#include <sstream>
#include "organiza.h"

namespace
{
    const char* ARQUIVO_RANKING = "save/ranking.txt";
}

std::vector<CMD::RegistroRanking> CMD::carregarRanking()
{
    std::vector<RegistroRanking> registros;
    errno = 0;
    std::ifstream arquivo(ARQUIVO_RANKING);
    if (!arquivo) {
        if (errno != ENOENT)
            std::cerr << "Erro ao abrir " << ARQUIVO_RANKING << std::endl;
        return registros;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty() || linha[0] == '#')
            continue;

        const std::string::size_type separador = linha.find('|');
        if (separador == std::string::npos || separador + 1 >= linha.size()) {
            std::cerr << "Registro inválido no ranking: " << linha << std::endl;
            continue;
        }

        std::istringstream conversor(linha.substr(0, separador));
        RegistroRanking registro;
        conversor >> registro.pontos;
        if (!conversor || conversor.peek() != std::char_traits<char>::eof()) {
            std::cerr << "Pontuação inválida no ranking: " << linha << std::endl;
            continue;
        }

        registro.nome = linha.substr(separador + 1);
        registros.push_back(registro);
    }

    if (arquivo.bad())
        std::cerr << "Erro ao ler " << ARQUIVO_RANKING << std::endl;

    std::stable_sort(
        registros.begin(),
        registros.end(),
        [](const RegistroRanking& primeiro, const RegistroRanking& segundo) {
            return primeiro.pontos > segundo.pontos;
        });
    return registros;
}

bool CMD::salvarResultadoRanking(const std::string& nome, int pontos)
{
    if (nome.empty() || nome.find_first_of("|\r\n") != std::string::npos) {
        std::cerr << "Nome inválido para registrar no ranking" << std::endl;
        return false;
    }

    std::ofstream arquivo(ARQUIVO_RANKING, std::ios::app);
    if (!arquivo) {
        std::cerr << "Erro ao abrir " << ARQUIVO_RANKING
                  << " para escrita" << std::endl;
        return false;
    }

    arquivo << pontos << '|' << nome << '\n';
    if (!arquivo) {
        std::cerr << "Erro ao gravar em " << ARQUIVO_RANKING << std::endl;
        return false;
    }
    return true;
}

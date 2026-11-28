#pragma once

#include <string>
#include <vector>

namespace CMD
{
    struct RegistroRanking
    {
        std::string nome;
        int pontos;
    };

    std::vector<RegistroRanking> carregarRanking();
    bool salvarResultadoRanking(const std::string& nome, int pontos);
}

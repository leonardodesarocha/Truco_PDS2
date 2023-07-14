#include "doctest.hpp"

#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

#include <cstdint>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

TEST_CASE("TESTANDO PEDIR TRUCO")
{

    Jogador j1("daniel", 1, 1);
    CHECK_EQ(true, j1.pedirTruco());

    Jogador j2("leo", 0, 0);
    CHECK_EQ(true, j2.pedirTruco());
}

TEST_CASE("TESTANDO ACEITAR TRUCO")
{
    Jogador j1("daniel", 1, 1);
    CHECK_EQ(true, j1.aceitarTruco());

    Jogador j2("leo", 0, 0);
    CHECK_EQ(true, j2.aceitarTruco());
}

TEST_CASE("TESTANDO PEGAR PONTOS")
{
    Jogador j1("daniel", 1, 1);
    CHECK_EQ(0, j1.getPontos());

    Jogador j2("leo", 0, 0);
    CHECK_EQ(0, j2.getPontos());
    j2.adicionaPontos(3);
    CHECK_EQ(3, j2.getPontos());
}

TEST_CASE("TESTANDO ADICIONA PONTOS")
{
    Jogador j1("daniel", 1, 1);
    j1.adicionaPontos(0);
    CHECK_EQ(0, j1.getPontos());

    Jogador j2("leo", 0, 0);
    j2.adicionaPontos(4);
    CHECK_EQ(4, j2.getPontos());
}

TEST_CASE("TESTANDO PEGAR NOME")
{
    Jogador j1("daniel", 1, 1);
    CHECK_EQ("daniel", j1.getNome());

    Jogador j2("leo", 0, 0);
    CHECK_EQ("leo", j2.getNome());
}

TEST_CASE("TESTANDO JOGAR CARTA")
{
    Jogador j1("daniel", 1, 1);
    std::vector<Carta> mao;
    mao.push_back(Carta("Espadilha", 12, 37));
    mao.push_back(Carta("7 de copas", 13, 38));
    mao.push_back(Carta("Zap", 14, 39));
    j1.setMao(mao);
    CHECK_EQ("Espadilha", j1.jogarCarta(1).getNome());

    Jogador j2("leo", 0, 0);
    std::vector<Carta> mao2;
    mao2.push_back(Carta("Espadilha", 12, 37));
    mao2.push_back(Carta("7 de copas", 13, 38));
    mao2.push_back(Carta("Zap", 14, 39));
    j2.setMao(mao2);
    CHECK_EQ(13, j2.jogarCarta(2).getPeso());

    Jogador j3("thiago", 1, 2);
    std::vector<Carta> mao3;
    mao3.push_back(Carta("Espadilha", 12, 37));
    mao3.push_back(Carta("7 de copas", 13, 38));
    mao3.push_back(Carta("Zap", 14, 39));
    j3.setMao(mao3);
    CHECK_EQ(39, j3.jogarCarta(3).getId());
}

TEST_CASE("TESTANDO TAMANHO DO VETOR DE CARTAS DO JOGADOR")
{
    Jogador j1("daniel", 1, 1);
    CHECK_EQ(0, j1.getMaoSize());

    Jogador j2("leo", 0, 0);
    std::vector<Carta> mao2;
    mao2.push_back(Carta("Espadilha", 12, 37));
    mao2.push_back(Carta("7 de copas", 13, 38));
    mao2.push_back(Carta("Zap", 14, 39));
    j2.setMao(mao2);
    CHECK_EQ(3, j2.getMaoSize());

    Jogador j3("thiago", 1, 2);
    std::vector<Carta> mao3;
    mao3.push_back(Carta("Espadilha", 12, 37));
    mao3.push_back(Carta("Zap", 14, 39));
    j3.setMao(mao3);
    CHECK_EQ(2, j3.getMaoSize());
}
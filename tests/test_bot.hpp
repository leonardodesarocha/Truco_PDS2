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

TEST_CASE("TESTANDO PEDIR TRUCO BOT")
{
    srand(1);
    Bot b1("bot1", 1, 1);
    CHECK_EQ(false, b1.pedirTruco());

    srand(5);
    Bot b2("bot2", 2, 2);
    CHECK_EQ(false, b2.pedirTruco());

    srand(10);
    Bot b3("bot3", 1, 3);
    CHECK_EQ(false, b3.pedirTruco());
}

TEST_CASE("TESTANDO ACEITAR TRUCO BOT")
{
    srand(1);
    Bot b1("bot1", 1, 1);
    CHECK_EQ(false, b1.aceitarTruco());

    srand(5);
    Bot b2("bot2", 2, 2);
    CHECK_EQ(false, b2.aceitarTruco());

    srand(10);
    Bot b3("bot3", 1, 3);
    CHECK_EQ(false, b3.aceitarTruco());
}

TEST_CASE("TESTANDO JOGAR CARTA BOT")
{
    srand(1);
    Bot b1("bot1", 1, 1);
    std::vector<Carta> mao;
    mao.push_back(Carta("Espadilha", 12, 37));
    mao.push_back(Carta("7 de copas", 13, 38));
    mao.push_back(Carta("Zap", 14, 39));
    b1.setMao(mao);
    CHECK_EQ("Espadilha", b1.jogarCarta(0).getNome());

    srand(100);
    Bot b2("bot2", 2, 2);
    std::vector<Carta> mao2;
    mao2.push_back(Carta("Espadilha", 12, 37));
    mao2.push_back(Carta("7 de copas", 13, 38));
    mao2.push_back(Carta("Zap", 14, 39));
    b2.setMao(mao2);
    CHECK_EQ("7 de copas", b2.jogarCarta(0).getNome());
}
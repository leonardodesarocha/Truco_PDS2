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

TEST_CASE("TESTANDO VALIDADE DA CARTA SELECIONADA PELO HUMANO")
{
    SUBCASE("CASO POSITIVO")
    {
        Humano h1("daniel", 1, 1);
        std::vector<Carta> mao;
        mao.push_back(Carta("Espadilha", 12, 37));
        mao.push_back(Carta("7 de copas", 13, 38));
        mao.push_back(Carta("Zap", 14, 39));
        h1.setMao(mao);
        CHECK_NOTHROW(h1.checaIndice(1));
        CHECK_NOTHROW(h1.checaIndice(2));
        CHECK_NOTHROW(h1.checaIndice(3));

        Humano h2("leo", 2, 2);
        std::vector<Carta> mao2;
        mao2.push_back(Carta("7 de copas", 13, 38));
        mao2.push_back(Carta("Zap", 14, 39));
        h2.setMao(mao2);
        CHECK_NOTHROW(h2.checaIndice(1));
        CHECK_NOTHROW(h2.checaIndice(2));

        Humano h3("thiago", 3, 3);
        std::vector<Carta> mao3;
        mao3.push_back(Carta("Zap", 14, 39));
        h3.setMao(mao3);
        CHECK_NOTHROW(h3.checaIndice(1));
    }
    SUBCASE("CASO NEGATIVO")
    {
        Humano h1("daniel", 1, 1);
        std::vector<Carta> mao;
        mao.push_back(Carta("Espadilha", 12, 37));
        mao.push_back(Carta("7 de copas", 13, 38));
        mao.push_back(Carta("Zap", 14, 39));
        h1.setMao(mao);
        CHECK_THROWS(h1.checaIndice(-1));
        CHECK_THROWS(h1.checaIndice(4));
        CHECK_THROWS(h1.checaIndice(100));

        Humano h2("leo", 2, 2);
        std::vector<Carta> mao2;
        mao2.push_back(Carta("7 de copas", 13, 38));
        mao2.push_back(Carta("Zap", 14, 39));
        h2.setMao(mao2);
        CHECK_THROWS(h2.checaIndice(3));
        CHECK_THROWS(h2.checaIndice(-1));
        CHECK_THROWS(h1.checaIndice(100));

        Humano h3("thiago", 3, 3);
        std::vector<Carta> mao3;
        mao3.push_back(Carta("Zap", 14, 39));
        h3.setMao(mao3);
        CHECK_THROWS(h3.checaIndice(2));
        CHECK_THROWS(h3.checaIndice(3));
    }
}

TEST_CASE("TESTANDO JOGAR CARTA HUMANO")
{
    Humano h1("daniel", 1, 1);
    std::vector<Carta> mao;
    mao.push_back(Carta("Espadilha", 12, 37));
    mao.push_back(Carta("7 de copas", 13, 38));
    mao.push_back(Carta("Zap", 14, 39));
    h1.setMao(mao);
    CHECK_EQ("Espadilha", h1.jogarCarta(1).getNome());

    Humano h2("leo", 2, 2);
    std::vector<Carta> mao2;
    mao2.push_back(Carta("Espadilha", 12, 37));
    mao2.push_back(Carta("7 de copas", 13, 38));
    mao2.push_back(Carta("Zap", 14, 39));
    h2.setMao(mao2);
    CHECK_EQ(13, h2.jogarCarta(2).getPeso());

    Humano h3("thiago", 3, 3);
    std::vector<Carta> mao3;
    mao3.push_back(Carta("Espadilha", 12, 37));
    mao3.push_back(Carta("7 de copas", 13, 38));
    mao3.push_back(Carta("Zap", 14, 39));
    h3.setMao(mao3);
    CHECK_EQ(39, h3.jogarCarta(3).getId());
}

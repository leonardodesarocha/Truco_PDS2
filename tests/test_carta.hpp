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

TEST_CASE("TESTANDO CARTA GET NOME")
{
    Carta c1("Zap", 14, 39);
    Carta c2("4 de ouros", 1, 0);
    Carta c3("5 de paus", 2, 3);
    Carta c4("6 de paus", 3, 7);
    Carta c5("3 de paus", 10, 32);
    Carta c6("TesteTeste", 777, 888);
    CHECK(c1.getNome() == "Zap");
    CHECK(c2.getNome() == "4 de ouros");
    CHECK(c3.getNome() == "5 de paus");
    CHECK(c4.getNome() == "6 de paus");
    CHECK(c5.getNome() == "3 de paus");
    CHECK(c6.getNome() == "TesteTeste");
}

TEST_CASE("TESTANDO CARTA GET PESO")
{
    Carta c1("Zap", 14, 39);
    Carta c2("4 de ouros", 1, 0);
    Carta c3("5 de paus", 2, 3);
    Carta c4("6 de paus", 3, 7);
    Carta c5("3 de paus", 10, 32);
    Carta c6("TesteTeste", 777, 888);
    CHECK(c1.getPeso() == 14);
    CHECK(c2.getPeso() == 1);
    CHECK(c3.getPeso() == 2);
    CHECK(c4.getPeso() == 3);
    CHECK(c5.getPeso() == 10);
    CHECK(c6.getPeso() == 777);
}

TEST_CASE("TESTANDO CARTA GET ID")
{
    Carta c1("Zap", 14, 39);
    Carta c2("4 de ouros", 1, 0);
    Carta c3("5 de paus", 2, 3);
    Carta c4("6 de paus", 3, 7);
    Carta c5("3 de paus", 10, 32);
    Carta c6("TesteTeste", 777, 888);
    CHECK(c1.getId() == 39);
    CHECK(c2.getId() == 0);
    CHECK(c3.getId() == 3);
    CHECK(c4.getId() == 7);
    CHECK(c5.getId() == 32);
    CHECK(c6.getId() == 888);
}
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

TEST_CASE("TESTANDO ID JOGADOR MAIOR CARTA")
{
    // esse metodo sempre eh testado passando como parametro o pesos das cartas dos jogadores com id 0, 1 , 2 e 3 respectivamente
    Rodada b1 = Rodada();
    CHECK_EQ(0, b1.idJogadorMaiorCarta(14, 2, 1, 0));
    CHECK_EQ(1, b1.idJogadorMaiorCarta(5, 12, 1, 0));
    CHECK_EQ(2, b1.idJogadorMaiorCarta(3, 6, 9, 0));
    CHECK_EQ(3, b1.idJogadorMaiorCarta(4, 3, 7, 11));
    // se tiver dois com mesmo valor ele considera o primeiro que tacou a carta
    CHECK_EQ(2, b1.idJogadorMaiorCarta(4, 3, 11, 11));
    CHECK_EQ(0, b1.idJogadorMaiorCarta(14, 14, 2, 3));
}

// sequencia para testar checagemVitorialParcial()
TEST_CASE("TESTANDO VITORAL PARCIAL DO VENCEDOR DA QUEDA")
{
    // so tem um vencendor se as cartas maiores de cada dupla tiverem pesos diferentes
    Rodada b1 = Rodada();
    b1.inserirCartaDupla1(Carta("Zap", 14, 39));
    b1.inserirCartaDupla1(Carta("7 de copas", 13, 38));
    b1.inserirCartaDupla2(Carta("4 de ouros", 1, 0));
    b1.inserirCartaDupla2(Carta("5 de paus", 2, 3));
    b1.checagemVitoriaParcial();
    CHECK_EQ(1, b1.getVitoriasParciaisDupla1());
    CHECK_EQ(0, b1.getVitoriasParciaisDupla2());

    Rodada b2 = Rodada();
    b2.inserirCartaDupla2(Carta("Zap", 14, 39));
    b2.inserirCartaDupla2(Carta("7 de copas", 13, 38));
    b2.inserirCartaDupla1(Carta("4 de ouros", 1, 0));
    b2.inserirCartaDupla1(Carta("5 de paus", 2, 3));
    b2.checagemVitoriaParcial();
    CHECK_EQ(1, b2.getVitoriasParciaisDupla2());
    CHECK_EQ(0, b2.getVitoriasParciaisDupla1());

    Rodada b3 = Rodada();
    b3.inserirCartaDupla2(Carta("5 de paus", 2, 3));
    b3.inserirCartaDupla2(Carta("5 de espadas", 2, 4));
    b3.inserirCartaDupla1(Carta("5 de copas", 2, 5));
    b3.inserirCartaDupla1(Carta("5 de ouros", 2, 6));
    b3.checagemVitoriaParcial();
    CHECK_EQ(0, b3.getVitoriasParciaisDupla2());
    CHECK_EQ(0, b3.getVitoriasParciaisDupla1());
}

TEST_CASE("TESTANDO DUPLA VENCEDORA DA RODADA")
{
    Rodada b1 = Rodada();
    b1.inserirCartaDupla1(Carta("Zap", 14, 39));
    b1.inserirCartaDupla1(Carta("7 de copas", 13, 38));
    b1.inserirCartaDupla2(Carta("4 de ouros", 1, 0));
    b1.inserirCartaDupla2(Carta("5 de paus", 2, 3));
    b1.checagemVitoriaParcial();
    b1.inserirCartaDupla1(Carta("Zap", 14, 39));
    b1.inserirCartaDupla1(Carta("7 de copas", 13, 38));
    b1.inserirCartaDupla2(Carta("4 de ouros", 1, 0));
    b1.inserirCartaDupla2(Carta("5 de paus", 2, 3));
    b1.checagemVitoriaParcial();
    CHECK_EQ(1, b1.checagemDuplaVencedora());

    Rodada b2 = Rodada();
    b2.inserirCartaDupla2(Carta("Zap", 14, 39));
    b2.inserirCartaDupla2(Carta("7 de copas", 13, 38));
    b2.inserirCartaDupla1(Carta("4 de ouros", 1, 0));
    b2.inserirCartaDupla1(Carta("5 de paus", 2, 3));
    b2.checagemVitoriaParcial();
    b2.inserirCartaDupla2(Carta("Zap", 14, 39));
    b2.inserirCartaDupla2(Carta("7 de copas", 13, 38));
    b2.inserirCartaDupla1(Carta("4 de ouros", 1, 0));
    b2.inserirCartaDupla1(Carta("5 de paus", 2, 3));
    b2.checagemVitoriaParcial();
    CHECK_EQ(2, b2.checagemDuplaVencedora());
}

TEST_CASE("TESTANDO AUMENTO E RESET PONTUACAO RODADA ATUAL")
{
    Rodada b1 = Rodada();
    b1.aumentaPontuacaoRodadaAtual();
    CHECK_EQ(4, b1.getPontuacaoRodadaAtual());
    b1.aumentaPontuacaoRodadaAtual();
    CHECK_EQ(6, b1.getPontuacaoRodadaAtual());
    b1.resetPontuacaoRodadaAtual();
    CHECK_EQ(2, b1.getPontuacaoRodadaAtual());
}

TEST_CASE("TESTANDO RESET VITORIAS PARCIAIS DUPLAS")
{
    Rodada b1 = Rodada();
    b1.inserirCartaDupla1(Carta("Zap", 14, 39));
    b1.inserirCartaDupla1(Carta("7 de copas", 13, 38));
    b1.inserirCartaDupla2(Carta("4 de ouros", 1, 0));
    b1.inserirCartaDupla2(Carta("5 de paus", 2, 3));
    b1.checagemVitoriaParcial();
    b1.inserirCartaDupla2(Carta("Zap", 14, 39));
    b1.inserirCartaDupla2(Carta("7 de copas", 13, 38));
    b1.inserirCartaDupla1(Carta("4 de ouros", 1, 0));
    b1.inserirCartaDupla1(Carta("5 de paus", 2, 3));
    b1.checagemVitoriaParcial();
    CHECK_EQ(1, b1.getVitoriasParciaisDupla2());
    CHECK_EQ(1, b1.getVitoriasParciaisDupla1());
    b1.resetVitoriasParciaisDuplas();
    CHECK_EQ(0, b1.getVitoriasParciaisDupla2());
    CHECK_EQ(0, b1.getVitoriasParciaisDupla1());
}

TEST_CASE("TESTANDO QtdQuedasRodadaAtual()")
{
    Rodada b1 = Rodada();
    CHECK_EQ(0, b1.getQtdQuedasRodadaAtual());
    b1.aumentaQtdQuedasRodadaAtual();
    CHECK_EQ(1, b1.getQtdQuedasRodadaAtual());
    b1.aumentaQtdQuedasRodadaAtual();
    b1.aumentaQtdQuedasRodadaAtual();
    CHECK_EQ(3, b1.getQtdQuedasRodadaAtual());
    b1.resetQtdQuedasRodadaAtual();
    CHECK_EQ(0, b1.getQtdQuedasRodadaAtual());
}
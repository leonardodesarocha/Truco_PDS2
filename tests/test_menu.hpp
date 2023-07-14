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

TEST_CASE("TESTANDO VERIFCACAO TAM MAX STRING")
{
    // retorna 1 caso ultrapasse o tam max
    Menu m1 = Menu();
    CHECK_EQ(1, m1.strMaxTamChecker("teste", 2));
    CHECK_EQ(1, m1.strMaxTamChecker("dan", 1));
    CHECK_EQ(1, m1.strMaxTamChecker("paralelepipedo", 7));
    CHECK_EQ(0, m1.strMaxTamChecker("teste", 21));
    CHECK_EQ(0, m1.strMaxTamChecker("dan", 3));
    CHECK_EQ(0, m1.strMaxTamChecker("paralelepipedo", 14));
}

TEST_CASE("TESTANDO VERIFCACAO TAM MIN STRING")
{
    // retorna 1 caso nao ultrapasse o tamanho minimo
    Menu m1 = Menu();
    CHECK_EQ(0, m1.strMinTamChecker("teste", 2));
    CHECK_EQ(0, m1.strMinTamChecker("dan", 1));
    CHECK_EQ(0, m1.strMinTamChecker("paralelepipedo", 7));
    CHECK_EQ(1, m1.strMinTamChecker("teste", 6));
    CHECK_EQ(1, m1.strMinTamChecker("dan", 4));
    CHECK_EQ(1, m1.strMinTamChecker("paralelepipedo", 16));
}

TEST_CASE("TESTANDO VERIFCACAO CONTEM ESPAÇO STRING")
{
    // retorna 1 caso tenha espaco na string
    Menu m1 = Menu();
    CHECK_EQ(0, m1.strSpaceChecker("teste"));
    CHECK_EQ(0, m1.strSpaceChecker("dan"));
    CHECK_EQ(0, m1.strSpaceChecker("paralelepipedo"));
    CHECK_EQ(1, m1.strSpaceChecker("tes te"));
    CHECK_EQ(1, m1.strSpaceChecker("d an"));
    CHECK_EQ(1, m1.strSpaceChecker("para lelepipedo"));
}

TEST_CASE("TESTANDO SE ACHA O USARNAME NO ARQUIVO TXT")
{
    // vai retornar 1 se tiver o nome procurado no arquivo que salva o historico
    Menu m1 = Menu();
    CHECK_EQ(1, m1.findName("dani"));
    CHECK_EQ(1, m1.findName("leo"));
    // retornar 0 pois nao vai achar o usuario
    CHECK_EQ(0, m1.findName("nomeinvalido"));
}

TEST_CASE("TESTANDO SE SENHA CONDIZ COM A CADASTRADA")
{
    Menu m1 = Menu();
    CHECK_EQ(1, m1.passwordChecker("dani", "dani"));
    CHECK_EQ(1, m1.passwordChecker("leo", "leoo"));
    // retornar 0 pois nao vai achar o usuario
    CHECK_EQ(0, m1.passwordChecker("nomeinvalido", "senhainvalida"));
}

TEST_CASE("TESTANDO CRIACAO DO USUARIO")
{
    // cadastra e procura pelo cadastro no arquivo que salva informacoes
    Menu m1 = Menu();
    m1.playerCreate("usuarioteste", "senhateste");
    CHECK_EQ(1, m1.findName("usuarioteste"));
    CHECK_EQ(1, m1.passwordChecker("usuarioteste", "senhateste"));
}

TEST_CASE("TESTANDO LOGIN USUARIO")
{
    // funcao que retorna o nome do jogador que esta logado, tem que digitar usuario e senha
    // tem que digitar usuario que existe e dps senha que bate com esse usuario
    Menu m1 = Menu();
    CHECK_EQ("dani", m1.loginUsuario());
}
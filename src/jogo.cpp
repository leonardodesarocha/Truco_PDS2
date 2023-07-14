#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

/**DEBUG
#include "baralho.cpp"
#include "bot.cpp"
#include "carta.cpp"
#include "humano.cpp"
#include "jogador.cpp"
#include "menu.cpp"
#include "rodada.cpp"**/

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>

// ---- METODOS DA CLASSE JOGO ----

Jogo::Jogo()
{
    menuJogo = Menu();
    baralhoDaQueda = Baralho();
    rodadaAtual = Rodada();
    usuario = Humano(menuJogo._nomeUsuario, 1, 0);
    bot1 = Bot("Bot1", 2, 1);
    bot2 = Bot("Bot2", 1, 2);
    bot3 = Bot("Bot3", 2, 3);
}

void Jogo::inicializaBaralho()
{

    baralhoDaQueda.inicializarBaralhoCompleto();
    baralhoDaQueda.inicializarMaoJogadores();
}

Carta Jogo::polimorfismoJogarCarta(Jogador &j, int indiceCartaEscolhida)
{
    return j.jogarCarta(indiceCartaEscolhida);
}

// sequencia de jogadas iniciando com o usuario
void Jogo::sequenciaJogadasIniciandoUsuario()
{
    // mostra as cartas pro jogador pra ele ver se quer pedir truco ou nao
    usuario.imprimeCartasJogador();
    std::cout << std::endl;

    int indiceCartaEscolhida;
    bool exception_caught = true;
    while (true)
    {
        try
        {
            checaPedidoTrucoJogador();
            exception_caught = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (!exception_caught)
        {
            break;
        }
    }

    std::cout << std::endl
              << std::endl;
    std::cout << "Escolha a carta para jogar:" << std::endl;
    usuario.msgSelecionarCartas();
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();

    bool exception_caughtPlayer = true;
    while (true)
    {
        try
        {
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            usuario.checaIndice(indiceCartaEscolhida);
            exception_caughtPlayer = false;
        }
        catch (ErroEscolhaCartaInvalida &e)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
            usuario.msgSelecionarCartas();
            usuario.imprimeCartasJogador();
        }
        if (!exception_caughtPlayer)
        {
            break;
        }
    }
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = polimorfismoJogarCarta(usuario, indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    std::cout << std::endl;

    bool exception_caught1 = true;
    bool jaPediu1 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot1(jaPediu1);
            exception_caught1 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu1 = true;
        }
        if (!exception_caught1)
        {
            break;
        }
    }
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = polimorfismoJogarCarta(bot1, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    std::cout << std::endl;

    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = polimorfismoJogarCarta(bot2, 0);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    std::cout << std::endl;

    bool exception_caught3 = true;
    bool jaPediu3 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot3(jaPediu3);
            exception_caught3 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu3 = true;
        }
        if (!exception_caught3)
        {
            break;
        }
    }
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = polimorfismoJogarCarta(bot3, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasIniciandoBot1()
{

    // mostra as cartas pro jogador pra ele ver se quer pedir truco ou nao
    usuario.imprimeCartasJogador();
    std::cout << std::endl
              << std::endl;

    bool exception_caught1 = true;
    bool jaPediu1 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot1(jaPediu1);
            exception_caught1 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu1 = true;
        }
        if (!exception_caught1)
        {
            break;
        }
    }
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = polimorfismoJogarCarta(bot1, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    std::cout << std::endl;

    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = polimorfismoJogarCarta(bot2, 0);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    std::cout << std::endl;

    bool exception_caught3 = true;
    bool jaPediu3 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot3(jaPediu3);
            exception_caught3 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu3 = true;
        }
        if (!exception_caught3)
        {
            break;
        }
    }
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = polimorfismoJogarCarta(bot3, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    std::cout << std::endl;

    int indiceCartaEscolhida;
    bool exception_caught = true;
    while (true)
    {
        try
        {
            checaPedidoTrucoJogador();
            exception_caught = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (!exception_caught)
        {
            break;
        }
    }

    std::cout << "Escolha a carta para jogar:" << std::endl;
    usuario.msgSelecionarCartas();
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();

    bool exception_caughtPlayer = true;
    while (true)
    {
        try
        {
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            usuario.checaIndice(indiceCartaEscolhida);
            exception_caughtPlayer = false;
        }
        catch (ErroEscolhaCartaInvalida &e)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
            usuario.msgSelecionarCartas();
            usuario.imprimeCartasJogador();
        }
        if (!exception_caughtPlayer)
        {
            break;
        }
    }
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = polimorfismoJogarCarta(usuario, indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasIniciandoBot2()
{
    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = polimorfismoJogarCarta(bot2, 0);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    std::cout << std::endl;

    bool exception_caught3 = true;
    bool jaPediu3 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot3(jaPediu3);
            exception_caught3 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu3 = true;
        }
        if (!exception_caught3)
        {
            break;
        }
    }
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = polimorfismoJogarCarta(bot3, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    std::cout << std::endl;

    int indiceCartaEscolhida;
    bool exception_caught = true;
    while (true)
    {
        try
        {
            checaPedidoTrucoJogador();
            exception_caught = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (!exception_caught)
        {
            break;
        }
    }
    std::cout << "Escolha a carta para jogar:" << std::endl;
    usuario.msgSelecionarCartas();
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();

    bool exception_caughtPlayer = true;
    while (true)
    {
        try
        {
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            usuario.checaIndice(indiceCartaEscolhida);
            exception_caughtPlayer = false;
        }
        catch (ErroEscolhaCartaInvalida &e)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
            usuario.msgSelecionarCartas();
            usuario.imprimeCartasJogador();
        }
        if (!exception_caughtPlayer)
        {
            break;
        }
    }
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = polimorfismoJogarCarta(usuario, indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);

    std::cout << std::endl;

    bool exception_caught1 = true;
    bool jaPediu1 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot1(jaPediu1);
            exception_caught1 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu1 = true;
        }
        if (!exception_caught1)
        {
            break;
        }
    }
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = polimorfismoJogarCarta(bot1, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasIniciandoBot3()
{
    // mostra as cartas pro jogador pra ele ver se quer pedir truco ou nao
    usuario.imprimeCartasJogador();
    std::cout << std::endl
              << std::endl;

    bool exception_caught3 = true;
    bool jaPediu3 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot3(jaPediu3);
            exception_caught3 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu3 = true;
        }
        if (!exception_caught3)
        {
            break;
        }
    }
    std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot3 = polimorfismoJogarCarta(bot3, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot3);

    std::cout << std::endl;

    int indiceCartaEscolhida;
    bool exception_caught = true;
    while (true)
    {
        try
        {
            checaPedidoTrucoJogador();
            exception_caught = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
        }
        if (!exception_caught)
        {
            break;
        }
    }

    std::cout << "Escolha a carta para jogar:" << std::endl;
    usuario.msgSelecionarCartas();
    // imprime as opcoes de carta do jogador
    usuario.imprimeCartasJogador();

    bool exception_caughtPlayer = true;
    while (true)
    {
        try
        {
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            usuario.checaIndice(indiceCartaEscolhida);
            exception_caughtPlayer = false;
        }
        catch (ErroEscolhaCartaInvalida &e)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
            usuario.msgSelecionarCartas();
            usuario.imprimeCartasJogador();
        }
        if (!exception_caughtPlayer)
        {
            break;
        }
    }
    // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
    Carta cartaSelecionadaUsuario = polimorfismoJogarCarta(usuario, indiceCartaEscolhida);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaUsuario);
    std::cout << std::endl;

    bool exception_caught1 = true;
    bool jaPediu1 = false;
    while (true)
    {
        try
        {
            checaPedidoTrucoBot1(jaPediu1);
            exception_caught1 = false;
        }
        catch (ErroNumeroInvalidoPedidoTruco &e)
        {
            std::cout << e.what() << std::endl;
            jaPediu1 = true;
        }
        if (!exception_caught1)
        {
            break;
        }
    }
    std::cout << "Bot1 (dupla adversaria) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot1 = polimorfismoJogarCarta(bot1, 0);
    rodadaAtual.inserirCartaDupla2(cartaSelecionadaBot1);

    std::cout << std::endl;

    checaPedidoTrucoBot2();
    std::cout << "Bot2 (minha dupla) vai jogar..." << std::endl;
    Carta cartaSelecionadaBot2 = polimorfismoJogarCarta(bot2, 0);
    rodadaAtual.inserirCartaDupla1(cartaSelecionadaBot2);

    rodadaAtual.setMaiorIdMd3(rodadaAtual.idJogadorMaiorCarta(cartaSelecionadaUsuario.getPeso(), cartaSelecionadaBot1.getPeso(), cartaSelecionadaBot2.getPeso(), cartaSelecionadaBot3.getPeso()));

    // checagem de qual dupla ganhou a queda
    rodadaAtual.checagemVitoriaParcial();
}

void Jogo::sequenciaJogadasMd3(int idMaior)
{
    int idJogadorMaiorCarta = idMaior;
    // começar jogando agr quem tacou a maior carta
    if (idJogadorMaiorCarta == 0)
    {
        std::cout << "-------- FIM DA QUEDA --------" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
        // menuJogo.limparTela();
        sequenciaJogadasIniciandoUsuario();
        // declarar que finalizou mais uma queda
        rodadaAtual.aumentaQtdQuedasRodadaAtual();
    }
    else if (idJogadorMaiorCarta == 1)
    {
        std::cout << "-------- FIM DA QUEDA --------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
        // menuJogo.limparTela();
        sequenciaJogadasIniciandoBot1();
        // declarar que finalizou mais uma queda
        rodadaAtual.aumentaQtdQuedasRodadaAtual();
    }
    else if (idJogadorMaiorCarta == 2)
    {
        std::cout << "-------- FIM DA QUEDA --------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
        // menuJogo.limparTela();
        sequenciaJogadasIniciandoBot2();
        // declarar que finalizou mais uma queda
        rodadaAtual.aumentaQtdQuedasRodadaAtual();
    }
    else if (idJogadorMaiorCarta == 3)
    {
        std::cout << "-------- FIM DA QUEDA --------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-------- Nova queda esta comecando --------" << std::endl;
        // menuJogo.limparTela();
        sequenciaJogadasIniciandoBot3();
        // declarar que finalizou mais uma queda
        rodadaAtual.aumentaQtdQuedasRodadaAtual();
    }
}

int Jogo::verificachar(int variavel)
{
    if (!isalpha((unsigned char)variavel))
    {
        if (variavel != 1 && variavel != 2)
        {
            variavel = 3;
            std::cin.clear();
        }
    }
    return variavel;
}

void Jogo::checaPedidoTrucoJogador()
{
    int pedindoTruco;
    bool resposta;
    std::cout << "Se deseja pedir truco digite 1, se nao digite 2 ";
    std::cin >> pedindoTruco;
    verificachar(pedindoTruco);

    if ((pedindoTruco != 1 && pedindoTruco != 2))
    {
        fflush(stdin);
        throw ErroNumeroInvalidoPedidoTruco();
    }

    if (pedindoTruco == 1)
    {
        resposta = bot1.aceitarTruco();
        if (resposta == true)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
        else
        {
            std::cout << "Pedido de truco nao foi aceito" << std::endl;
        }
    }
}

void Jogo::checaPedidoTrucoBot1(int jaPediu)
{
    bool pedindoTruco = bot1.pedirTruco();
    int resposta;
    // std::cin.clear();
    if ((pedindoTruco == true) || (jaPediu == true))
    {
        std::cout << "Se deseja aceitar o truco digite 1, se nao digite 2 ";
        std::cin >> resposta;
        verificachar(resposta);

        if (resposta != 1 && resposta != 2)
        {
            fflush(stdin);
            throw ErroNumeroInvalidoPedidoTruco();
        }
        else if (resposta == 1)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
    }
}

void Jogo::checaPedidoTrucoBot2()
{
    bool pedindoTruco = bot2.pedirTruco();
    bool resposta;
    if (pedindoTruco == true)
    {
        resposta = bot1.aceitarTruco();
        if (resposta == true)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito pelos bots" << std::endl;
        }
    }
}

void Jogo::checaPedidoTrucoBot3(int jaPediu)
{
    bool pedindoTruco = bot3.pedirTruco();
    int resposta;
    std::cin.clear();
    if ((pedindoTruco == true) || (jaPediu == true))
    {
        std::cout << "Se deseja aceitar o truco digite 1, se nao digite 2 ";
        std::cin >> resposta;
        verificachar(resposta);

        // abort();
        /**if (!isdigit( (unsigned char)resposta)){
            if (resposta != 1 && resposta != 2){
                std::cin.clear();
                resposta = 3;
                std::cout << "Sim" << std::endl;
            }
        }**/
        if (resposta != 1 && resposta != 2)
        {
            fflush(stdin);
            throw ErroNumeroInvalidoPedidoTruco();
        }
        else if (resposta == 1)
        {
            rodadaAtual.aumentaPontuacaoRodadaAtual();
            std::cout << "Pedido de truco foi aceito" << std::endl;
        }
    }
}

// procedimentos do final de uma rodada
void Jogo::procedimentosFinalRodada()
{
    // dar o ponto da md3 para quem ganhou ela, no caso so preenchi do usuario ou do bot1 (ja que sao pontos da dupla nao precisa preencher todo mundo)
    if (rodadaAtual.checagemDuplaVencedora() == 1)
    {
        usuario.adicionaPontos(rodadaAtual.getPontuacaoRodadaAtual());
    }
    else if (rodadaAtual.checagemDuplaVencedora() == 2)
    {
        bot1.adicionaPontos(rodadaAtual.getPontuacaoRodadaAtual());
    }
    // reseta o valor da md3 para 2
    rodadaAtual.resetPontuacaoRodadaAtual();
    // reseta as vitorias parciais pois vai ter nova md3
    rodadaAtual.resetVitoriasParciaisDuplas();
    // reseta a quantidade de quedas da rodada
    rodadaAtual.resetQtdQuedasRodadaAtual();
    // reseta o baralho adicionando novamente todas as cartas e prepara a mao de cada jogador
    baralhoDaQueda.resetarBaralhoEMaoJogadores();
    baralhoDaQueda.inicializarBaralhoCompleto();
    baralhoDaQueda.inicializarMaoJogadores();
}

// ---- FIM DOS METODOS DA CLASSE JOGO ----

//

//

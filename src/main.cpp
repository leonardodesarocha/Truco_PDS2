#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <stdio.h>

int main()
{
    inicio:
    srand(time(NULL));
    Jogo jogo;
    Menu menuJogo;

    // se quiser visualizar o ranking digita 1, se quiser iniciar a partida digite 2
    std::string proxPasso;
    std::string exit;
    // se o usuario digitar um valor invalido vai repetir a msg
    while (1)
    {
        proxPasso = "4";
        if (proxPasso == "4")
        {
            while (proxPasso != "0" && proxPasso != "1" && proxPasso != "2" && proxPasso != "3")
            {
                std::cout << "Escolha a opcao que desejar:\n0 - Cadastrar novo usuario\n1 - Exibir ranking\n2 - Iniciar partida\n3 - Sair\n";
                std::cin >> proxPasso;
            }
        }

        if (proxPasso == "0")
        {
            menuJogo.cadastroUsuario();
        }

        if (proxPasso == "1")
        {
            menuJogo.ranking();
        }

        if (proxPasso == "2")
        {
            jogo.menuJogo.limparTela();
            std::string name = jogo.menuJogo.loginUsuario();

            std::cout << "O jogo ira iniciar!";

            // inicializa o baralho completo e prepara a mao de cada jogador
            jogo.inicializaBaralho();

            // // inicializa os jogadores
            // inicializaJogadores();

            jogo.menuJogo.limparTela();

            int quemIniciaJogandoRodada = 0;
            int idJogadorMaiorCarta;

            // while que controla a partida em si, ela so termina se uma das duplas fizer 12 pontos
            while (jogo.usuario.getPontos() < 12 && jogo.bot1.getPontos() < 12)
            {
                if (quemIniciaJogandoRodada == 0)
                {
                    jogo.menuJogo.limparTela();
                    std::cout << "Nova rodada esta iniciando...       Pontuacao atual: (minha dupla)" << jogo.usuario.getPontos() << "  vs  " << jogo.bot1.getPontos() << "(dupla adversaria)" << std::endl;
                    // distribui as cartas pros jogadores
                    jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                    jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                    jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                    jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                    jogo.sequenciaJogadasIniciandoUsuario();

                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                    // declarar que finalizou mais uma queda
                    jogo.rodadaAtual.aumentaQtdQuedasRodadaAtual();

                    // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                    while (jogo.rodadaAtual.getQtdQuedasRodadaAtual() != 3 && (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2))
                    {

                        jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);

                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                    }

                    jogo.procedimentosFinalRodada();
                    quemIniciaJogandoRodada = 1;
                }
                else if (quemIniciaJogandoRodada == 1)
                {
                    jogo.menuJogo.limparTela();
                    std::cout << "Nova rodada esta iniciando...       Pontuacao atual: (minha dupla)" << jogo.usuario.getPontos() << "  vs  " << jogo.bot1.getPontos() << "(dupla adversaria)" << std::endl;
                    // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                    jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                    jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                    jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                    jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                    jogo.sequenciaJogadasIniciandoBot1();

                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                    // declarar que finalizou mais uma queda
                    jogo.rodadaAtual.aumentaQtdQuedasRodadaAtual();

                    // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                    while (jogo.rodadaAtual.getQtdQuedasRodadaAtual() != 3 && (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2))
                    {
                        jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                    }

                    jogo.procedimentosFinalRodada();
                    quemIniciaJogandoRodada = 2;
                }
                else if (quemIniciaJogandoRodada == 2)
                {
                    jogo.menuJogo.limparTela();
                    std::cout << "Nova rodada esta iniciando...       Pontuacao atual: (minha dupla)" << jogo.usuario.getPontos() << "  vs  " << jogo.bot1.getPontos() << "(dupla adversaria)" << std::endl;
                    // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                    jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                    jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                    jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                    jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                    jogo.sequenciaJogadasIniciandoBot2();

                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                    // declarar que finalizou mais uma queda
                    jogo.rodadaAtual.aumentaQtdQuedasRodadaAtual();

                    // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                    while (jogo.rodadaAtual.getQtdQuedasRodadaAtual() != 3 && (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2))
                    {
                        jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                    }

                    jogo.procedimentosFinalRodada();
                    quemIniciaJogandoRodada = 3;
                }
                else if (quemIniciaJogandoRodada == 3)
                {
                    jogo.menuJogo.limparTela();
                    std::cout << "Nova rodada esta iniciando...       Pontuacao atual: (minha dupla)" << jogo.usuario.getPontos() << "  vs  " << jogo.bot1.getPontos() << "(dupla adversaria)" << std::endl;
                    // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
                    jogo.usuario.setMao(jogo.baralhoDaQueda.getMaoJogador0());
                    jogo.bot1.setMao(jogo.baralhoDaQueda.getMaoJogador1());
                    jogo.bot2.setMao(jogo.baralhoDaQueda.getMaoJogador2());
                    jogo.bot3.setMao(jogo.baralhoDaQueda.getMaoJogador3());

                    jogo.sequenciaJogadasIniciandoBot3();

                    // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                    idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();

                    // declarar que finalizou mais uma queda
                    jogo.rodadaAtual.aumentaQtdQuedasRodadaAtual();

                    // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
                    while (jogo.rodadaAtual.getQtdQuedasRodadaAtual() != 3 && (jogo.rodadaAtual.getVitoriasParciaisDupla1() != 2 && jogo.rodadaAtual.getVitoriasParciaisDupla2() != 2))
                    {
                        jogo.sequenciaJogadasMd3(idJogadorMaiorCarta);
                        // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
                        idJogadorMaiorCarta = jogo.rodadaAtual.getMaiorIdMd3();
                    }

                    jogo.procedimentosFinalRodada();

                    quemIniciaJogandoRodada = 0;
                }
            }

            std::cout << "\n" << jogo.usuario.getPontos() << " x " << jogo.bot1.getPontos() << std::endl;
            if (jogo.usuario.getPontos() >= 12)
            {
                std::cout << "Usuario ganhou\n";
                menuJogo.uptadeRanking(name, 1);
            }
            else if (jogo.bot1.getPontos() >= 12)
            {
                std::cout << "Usuario perdeu\n";
                menuJogo.uptadeRanking(name, 0);
            }
            system("pause");
            system("cls");
            goto inicio;
        }

        if (proxPasso == "3")
        {
            std::cout << "Tem certeza que deseja sair do jogo? (s/n):\n";
            std::cin >> exit;
            while (exit != "s" && exit != "n")
            {
                std::cout << "Opcao invalida, digite novamente (s/n):\n";
                std::cin >> exit;
            }
            if (exit == "s")
            {
                break;
            }
        }
    }
}
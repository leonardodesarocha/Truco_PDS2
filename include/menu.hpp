/**
 * @file menu.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica do menu
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Menu é responsável por registrar e processar os
 * dados das partidas anteriores e por organizar as informações das
 * das contas dos jogadores dentro do jogo.
 * @copyright GNU General Public License v2.0
 */

#ifndef MENU_HPP
#define MENU_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"
#include "rodada.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include <stdlib.h>

#define MAXTAM_NAME 20
#define MINTAM_NAME 3
#define MAXTAM_PASSWORD 15
#define MINTAM_PASSWORD 4

/**
 * @brief Cria dentro do jogo um sistema de conta dos jogadores.
 * e armazena os dados para elaborar o ranking.
 * @details Implementa a lógica de logar dentro do jogo com uma conta
 * que já existente ou cadastrar um novo usuário. Além disso, também armazena
 * informações das partidas anteriores para elaborar um ranking entre os
 * jogadores.
 */
class Menu
{
public:
    std::string _nomeUsuario;

    /**
     * @brief Constrói o objeto da classe Menu.
     */
    Menu();

    /**
     * @brief Lógica para cadastrar um jogador.
     * @details Cadastra o nome e a senha do jogador, de acordo
     * com as restrições, e armazena esses dados para utlizar no ranking
     * dos jogadores.
     */
    void cadastroUsuario();

    /**
     * @brief Lógica para exibir o ranking.
     * @details Exibe na tela as informações de todos os jogadores que
     * foram armazenadas em um arquivo "base.txt", como o nome, senha,
     * partidas jogadas e vitórias.
     */
    void ranking();

    /**
     * @brief Lógica para identificar usuário logado no jogo.
     * @details Armazena os dados do usuário logado no jogo para que seja
     * possível, ao final da partida, atualizar o ranking com os dados da
     * última partida.
     * @return Retorna a string do nome do usuário logado.
     */
    std::string loginUsuario();

    /**
     * @brief Lógica para atualizar o ranking.
     * @details De acordo com o nome do usuário logado, as informações
     * necessárias para atualizar o ranking são coletadas ao final do
     * jogo e são armazenadas no arquivo "base.txt".
     */
    void uptadeRanking(std::string player, int win);

    /**
     * @brief Lógica para limpar a tela.
     * @details Apaga todos os dados que foram escritos na tela e que não
     * tem mais necessidade de mostrar para o jogador com objetivo de
     * facilitar o entendimento do jogo.
     */
    void limparTela();

    // Strings
    /**
     * @brief Função para verificação do tamanho da string.
     * @details Implementa a lógica para identificar se o tamanho da string
     * recebida ultrapassa o valor do número inteiro.
     * @param Recebe como parâmetro a string que será comparada e o valor inteiro.
     * @return Retorna 1 caso a string seja maior que o valor ou 0 para o caso contrário.
     */
    bool strMaxTamChecker(std::string str, int size);

    /**
     * @brief Função para verificação do tamanho da string.
     * @details Implementa a lógica para identificar se o tamanho da string
     * recebida é inferior ao valor do número inteiro.
     * @param Recebe como parâmetro a string que será comparada e o valor inteiro.
     * @return Retorna 1 caso a string seja menor que o valor ou 0 para o caso contrário.
     */
    bool strMinTamChecker(std::string str, int size);

    /**
     * @brief Função para verificação de espaçamentos.
     * @details Implementa a lógica para identificar se a string
     * recebida possui espaços.
     * @param Recebe como parâmetro a string para identificação.
     * @return Retorna 1 caso a string possua espaços ou 0 para o caso contrário.
     */
    bool strSpaceChecker(std::string str);

    /**
     * @brief Função para identificar o nome no arquivo.
     * @details Implementa a lógica para comparar o nome recebido por parâmetro
     * com os nomes salvos dentro do arquivo.
     * @param Recebe como parâmetro a string com o nome que será procurado dentro
     * do arquivo.
     * @return Retorna 1 caso exista o nome dentro do arquivo ou 0 para o caso contrário.
     */
    bool findName(std::string name);

    /**
     * @brief Função para checar se a senha do usuário está correta.
     * @details Implementa a lógica para comparar o nome e a senha recebido por parâmetro
     * com os dados salvos dentro do arquivo.
     * @param Recebe como parâmetro a string com o nome do jogador e a senha inserida.
     * @return Retorna 1 caso a senha inserida esteja correta para o jogador e se o nome
     * existe dentro do arquivo ou 0 para o caso que alguma dessas condições não for respeitada.
     */
    bool passwordChecker(std::string name, std::string password);

    /**
     * @brief Função para criar novo jogador.
     * @details Implementa a lógica para adicionar um jogador de acordo com os dados
     * inseridos.
     * @param Recebe como parâmetro a string com o nome do novo jogador e a senha para
     * cadastrar no arquivo.
     */
    void playerCreate(std::string name, std::string password);

    /**
     * @brief Função para ordenar a porcentagem de vitória dos jogadores.
     * @details Implementa a lógica para ler o arquivo de texto e colocar em ordem crescente
     * a porcentagem de vitória dos jogadores.
     * @return Retorna variável do tipo set com os dados ordenados.
     */
    std::set<float> pvs();

    /**
     * @brief Função para filtrar os jogadores que possuem determinada porcentagem de vitória.
     * @details Implementa a lógica para ler o arquivo de texto e, a partir disso,
     * salvar em uma variável do tipo set todos os jogadores que possuem o mesmo valor de
     * de porcentagem de vitória recebido por parâmetro.
     * @param Recebe por parâmetro um número do tipo float com a porcentagem de vitória desejada para
     * seleção dos jogadores.
     * @return Retorna variável do tipo set com os dados ordenados.
     */
    std::set<std::string> nicks(float x);
};
#endif
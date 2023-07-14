/**
 * @file jogo.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica do jogo
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Jogo se relaciona com as outras classes e
 * implementa métodos que controlam a sequência lógica do truco.
 * Além disso, a classe ErroNumeroInvalidoPedidoTruco define a mensagem que
 * será retornada quando houver um erro com a entrada do valor
 * @copyright GNU General Public License v2.0
 */

#ifndef JOGO_HPP
#define JOGO_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"
#include "rodada.hpp"
#include "menu.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

/**
* @brief Classe para detectar erros.
* @details Define um método para exibir uma mensegem quando ocorrer um erro,
* nesse caso, se o jogador pedir truco usando um valor que não seja 1 ou 2.
*/
class ErroNumeroInvalidoPedidoTruco : public std::exception
{
public:
	/**
    * @brief Método para mensagem de erro.
    * @details Implementa a lógica para retornar uma mensagem quando for
	* detectado um erro.
    */
    virtual const char *what() const noexcept
    {
        return "Entrada invalida, os numeros permitidos sao 1 ou 2";
    }
};

/**
 * @brief Armazena e processa o jogo em si.
 * @details Define a sequência lógica, por meio de métodos específicos, para
 * que o truco seja desenvolvido.
 */
class Jogo
{
public:
    
	/**
	* @brief Objeto da classe menu contendo as informações das partidas
	* e do login do usuário.
	*/
	Menu menuJogo;
    
	/**
	* @brief Objeto da classe Baralho contendo as cartas utilizadas durante a rodada.
	*/
	Baralho baralhoDaQueda;
    
	/**
	* @brief Objeto da classe Rodada contendo as informações da rodada atual.
	*/
	Rodada rodadaAtual;
    
	/**
	* @brief Objeto da classe Humano para salvar os dados referentes ao usuário.
	*/
	Humano usuario;
    
	/**
	* @brief Um dos três objetos da classe Bot.
	*/
	Bot bot1;
    
	/**
	* @brief Um dos três objetos da classe Bot.
	*/
	Bot bot2;
    
	/**
	* @brief Um dos três objetos da classe Bot.
	*/
	Bot bot3;

	/**
	* @brief Constrói o objeto da classe Jogo.
	* @details Incializa os atributos que pertencem a classe Jogo.
	*/
    Jogo();
    
	/**
	* @brief Inicializa o baralho da rodada e define as cartas dos
	* jogadores.
	* @details Implementa a lógica para gerar o baralho da rodada e
	* distribuir três cartas para cada jogador.
	*/
	void inicializaBaralho();
    
	/**
	* @brief Etapas de uma queda iniciando pelo usuário.
	* @details Define a sequência lógica da queda iniciada a partir do usuário
    * incluindo o lançamento das cartas de cada jogador, as comparações
	* das cartas jogadas, os pedidos de truco e o resultado final da queda.
	*/
	void sequenciaJogadasIniciandoUsuario();
    
	/**
	* @brief Etapas de uma queda iniciando pelo bot 1.
	* @details Define a sequência lógica da queda iniciada a partir do bot 1
    * incluindo o lançamento das cartas de cada jogador, as comparações
	* das cartas jogadas, os pedidos de truco e o resultado final da queda.
	*/
	void sequenciaJogadasIniciandoBot1();
    
	/**
	* @brief Etapas de uma queda iniciando pelo bot 2.
	* @details Define a sequência lógica da queda iniciada a partir do bot 2
    * incluindo o lançamento das cartas de cada jogador, as comparações
	* das cartas jogadas, os pedidos de truco e o resultado final da queda.
	*/
	void sequenciaJogadasIniciandoBot2();
    
	/**
	* @brief Etapas de uma queda iniciando pelo bot 3.
	* @details Define a sequência lógica da queda iniciada a partir do bot 3
    * incluindo o lançamento das cartas de cada jogador, as comparações
	* das cartas jogadas, os pedidos de truco e o resultado final da queda.
	*/
	void sequenciaJogadasIniciandoBot3();
    
	/**
	* @brief Etapas de uma queda iniciando pelo jogador que jogou a maior
	* carta na queda anterior.
	* @details Define a sequência lógica da queda iniciada a partir do
	* jogador que jogou a maior carta na queda anterior
    * incluindo o lançamento das cartas de cada jogador, as comparações
	* das cartas jogadas, os pedidos de truco e o resultado final da queda.
	*/
	void sequenciaJogadasMd3(int idMaior);
    
	/**
	* @brief Método para avaliar pedido de truco do usuário.
	* @details Implementa a lógica para o jogador pedir truco e,
	* além disso, checar se foi aceito pelos outros jogadores.
	*/
	void checaPedidoTrucoJogador();
    
	/**
	* @brief Método para avaliar pedido de truco do bot 1.
	* @details Implementa a lógica para armazenar a resposta dos outros
	* jogadores em relação ao pedido de truco do bot1. Além disso, caso
	* a checagem de truco seja realizada, mas a resposta foi dada por algum valor
	* diferente de 1 ou 2, ele indica um erro e repete a checagem novamente.
	* @param Recebe um número inteiro como parâmetro para identificar se a checagem
	* já foi realizada, mas estava com erro nas respostas dos outros jogadores.
	*/
	void checaPedidoTrucoBot1(int jaPediu);
    
	/**
	* @brief Método para avaliar pedido de truco do bot 2.
	* @details Implementa a lógica para o jogador pedir truco e,
	* além disso, checar se foi aceito pelos outros jogadores.
	*/
	void checaPedidoTrucoBot2();
    
	/**
	* @brief Método para avaliar pedido de truco do bot 3
	* @details Implementa a lógica para armazenar a resposta dos outros
	* jogadores em relação ao pedido de truco do bot1. Além disso, caso
	* a checagem de truco seja realizada, mas a resposta foi dada por algum valor
	* diferente de 1 ou 2, ele indica um erro e repete a checagem novamente.
	* @param Recebe um número inteiro como parâmetro para identificar se a checagem
	* já foi realizada, mas estava com erro nas respostas dos outros jogadores.
	*/
	void checaPedidoTrucoBot3(int jaPediu);
    
	/**
	* @brief Estabelece os procedimento finais da rodada.
	* @details Implementa a lógica para dar os pontos para a dupla que venceu
    * a rodada, resetar a pontuação da rodada e as vitórias parciais, além disso,
    * reseta o baralho da rodada e as cartas dos jogadores.
	*/
	void procedimentosFinalRodada();
    
	/**
	* @brief Método que verifica a resposta.
	* @details Implementa a lógica para identificar se a resposta do jogador possui letras ou
	* é apenas números.
	* @param Recebe por parâmetro o valor no formato inteiro que será verificado.
	* @return Retorna o valor 3 caso o parâmetro seja diferente de 1 e 2.
	*/
	int verificachar(int variavel);

    /**
	* @brief Função com polimorfismo para jogar a carta.
	* @details Implementa a lógica para que, a partir dos parâmetros recebidos, 
	* seja possível identificar qual tipo de jogador vai lançar a carta.
	* Sendo assim, caso seja um bot será utilizado o método jogarCarta do bot com
	* o respectivo índice da carta, caso seja um humano o método utilizado será do
    * usuário.
	* @param Recebe como parâmetro o endereço de um jogador e a carta que será jogada.
	* @return Retorna a carta que o usuário selecionou.
	*/
	Carta polimorfismoJogarCarta(Jogador &j, int indiceCartaEscolhida = 0);
};
#endif
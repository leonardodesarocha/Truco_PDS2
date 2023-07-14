/**
 * @file rodada.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica da rodada
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Rodada é responsável para armazenar todas as
 * informações da rodada que permitem desenvolvimento do jogo
 * @copyright GNU General Public License v2.0
 */

#ifndef RODADA_HPP
#define RODADA_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "humano.hpp"
#include "bot.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

/**
* @brief Armazena e processa os dados de uma partida.
* @details Implementa a lógica para definir a carta jogada pelas duplas,
* atribue a quantidade de pontos que a partida vale e checa se existe o
* vencedor da rodada.
*/
class Rodada
{
    /**
    * @brief Vector de Cartas para salvar as cartas jogadas pela dupla 1.
    */
	std::vector<Carta> _cartasDupla1Mesa;
    
	/**
    * @brief Número inteiro entre 0 e 2 que representa a quantidade de
	* vitória da dupla 1 na rodada.
    */
	int _vitoriasParciaisDupla1;
    
	/**
    * @brief Vector de Cartas para salvar as cartas jogadas pela dupla 2.
    */
	std::vector<Carta> _cartasDupla2Mesa;
    
	/**
    * @brief Número inteiro entre 0 e 2 que representa a quantidade de
	* vitória da dupla 2 na rodada.
    */
	int _vitoriasParciaisDupla2;
    
	/**
    * @brief Número inteiro que representa o valor da rodada.
    */
	int _pontuacaoRodadaAtual = 2;
    
	/**
    * @brief Número inteiro que identifica quem jogou a maior
	* carta.
    */
	int _maiorIdMd3;

	/**
    * @brief Número inteiro que identifica a quantidade de quedas da rodada.
    */
    int _qtdQuedasRodadaAtual = 0;

public:
    /**
	* @brief Constrói o objeto da classe Rodada.
	* @details Incializa como zero os atributos referente a quantidade 
	* de vitoria das duplas.
	*/
	Rodada();
	
    /**
	* @brief Lógica para identificar as cartas jogadas pela dupla 1.
	* @details Inclue a carta que um dos jogadores deseja jogar no
	* conjunto de cartas da dupla.
	* @param carta do tipo Carta para adição ao conjunto de cartas
	* da dupla 1.
	*/ 
	void inserirCartaDupla1(Carta carta);
    
	/**
	* @brief Lógica para identificar as cartas jogadas pela dupla 2.
	* @details Inclue a carta que um dos jogadores deseja jogar no
	* conjunto de cartas da dupla.
	* @param carta do tipo Carta para adição ao conjunto de cartas
	* da dupla 2.
	*/
	void inserirCartaDupla2(Carta carta);
    
	/**
	* @brief Identificação do jogador que jogou a maior carta.
	* @details Cria um vector como os pesos de todas as cartas jogadas.
	* Posteriormente, implementa a lógica para comparar os maiores
	* pesos e identificar o jogador que jogou a maior carta.
	* @param Quatro números inteiros referente ao peso de cada carta lançada.
	* @return Retorna um número inteiro entre 0 e 3 para identificar o jogador.
	*/
	int idJogadorMaiorCarta(int peso0, int peso1, int peso2, int peso3);
    
	/**
	* @brief Método que retorna o número de identificação do jogador que jogou
	* a maior carta.
	* @details Implementa a lógica para retornar o número de identificação do
	* jogador que jogou a maior carta na melhor de três.
	* @return Retorna um número inteiro entre 0 e 3 para identificar o jogador.
	*/
	int getMaiorIdMd3();
    
	/**
	* @brief Armazanamento da informação do jogador que lançou a maior carta.
	* @details Armazena o número de identificação do jogador com base no parâmetro
	* recebido.
	* @param Um número inteiro de identificação do jogador.
	*/ 
	void setMaiorIdMd3(int num);
    
	/**
	* @brief Checa a quantidade vitórias parciais das duplas.
	* @details Implenta a comparação para identificar se alguma dupla conseguiu
    * duas vitórias parciais.
	* @return Retorna um ou dois para identificação da dupla vencedora da
	* rodada.
	*/ 
	int checagemDuplaVencedora();
    
	/**
	* @brief Método que retorna o número de vitórias parciais da dupla.
	* @details Implementa a lógica para retornar a quantidade de vitórias 
	* parciais que a dupla 1 conseguiu.
	* @return Retorna um número inteiro entre 0 e 2.
	*/
	int getVitoriasParciaisDupla1();
    
	/**
	* @brief Método que retorna o número de vitórias parciais da dupla.
	* @details Implementa a lógica para retornar a quantidade de vitórias 
	* parciais que a dupla 2 conseguiu.
	* @return Retorna um número inteiro entre 0 e 2.
	*/
	int getVitoriasParciaisDupla2();
    
	/**
	* @brief Lógica para retornar o valor da aposta.
	* @details Implementa a lógica para retornar a quantidade de pontos
	* que foi apostado durante aquela rodada.	
	* @return Retorna um número inteiro correspondente a pontuação da rodada.
	*/
	int getPontuacaoRodadaAtual();
    
	/**
	* @brief Lógica para aumentar o valor da aposta.
	* @details Implementa a lógica para aumentar o valor da aposta caso
	* a outra dupla aceite o pedido de truco.
	*/
	void aumentaPontuacaoRodadaAtual();
    
	/**
	* @brief Lógica para resetar o valor da aposta.
	* @details Implementa a lógica para resetar a quantidade de pontos sendo
	* apostado no momento para dois.
	*/
	void resetPontuacaoRodadaAtual();
    
	/**
	* @brief Lógica para resetar a quantidade de vitórias parciais.
	* @details Implementa a lógica para resetar as vitórias parciais 
	* das duas duplas para zero.
	*/
	void resetVitoriasParciaisDuplas();
    
	/**
	* @brief Checagem da dupla que ganhou a partida.
	* @details Implementa a lógica para definir o ganhador da partida
	* de acordo com as cartas de maior peso e, caso forem iguais,
	* compara com as segundas cartas com maior peso. Além disso, zera
	* os conjuntos de cartas das duplas.
	*/
	void checagemVitoriaParcial();

    /**
	* @brief Método que retorna a quantidade de quedas da rodada.
	* @details Implementa a lógica para retornar o número que indica
	* quantas quedas da rodada passaram até o momento.
	* @return Retorna um número inteiro entre 1 e 3 referente a quantidade de quedas.
	*/
	int getQtdQuedasRodadaAtual();
    
	/**
	* @brief Aumenta a quantidade de quedas da rodada.
	* @details Implementa a lógica para aumentar a quantidade de quedas.
	* assim que for definido um ganhador.
	*/
	void aumentaQtdQuedasRodadaAtual();
    
	/**
	* @brief Reseta a quantidade de quedas da rodada.
	* @details Implementa a lógica para resetar a quantidade de quedas.
	* assim que iniciar uma nova rodada.
	*/
	void resetQtdQuedasRodadaAtual();
};
#endif
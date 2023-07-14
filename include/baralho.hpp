/**
 * @file baralho.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica do baralho
 * @version 1.0
 * @date 2022-12-06
 * @details A classe baralho é responsável por modificar e armazenar as
 * informações das cartas de cada jogador que serão utilizadas durante
 * a partida
 * @copyright GNU General Public License v2.0
 */

#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "carta.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

/**
* @brief Modifica e armazena as cartas dos jogadores.
* @details Implementa a lógica para inserir, sortear e deletar determinada
* carta dentro do conjunto de cartas selecionado.
*/
class Baralho
{
private:

	/**
	* @brief Vector de Cartas contendo todas as 40 cartas para o baralho.
	*/
    std::vector<Carta> _baralho;
    
	/**
	* @brief  Vector de Cartas contendo as cartas disponíveis para o jogador 0.
	*/
	std::vector<Carta> _maoJogador0;
    
	/**
	* @brief  Vector de Cartas contendo as cartas disponíveis para o jogador 1.
	*/
	std::vector<Carta> _maoJogador1;
    
	/**
	* @brief  Vector de Cartas contendo as cartas disponíveis para o jogador 2.
	*/
	std::vector<Carta> _maoJogador2;
    
	/**
	* @brief  Vector de Cartas contendo as cartas disponíveis para o jogador 3.
	*/
	std::vector<Carta> _maoJogador3;

public:
	/**
	* @brief Constrói o objeto da classe Baralho.
	* @details Incializa os atributos do objeto e define os seus tamanhos.
	*/
    Baralho();
    
	/**
	* @brief Lógica para gerar cartas aleatórias.
	* @details Sorteia um número inteiro entre 0 e 39 que é utilizado como
	* índice da carta.
	* @return Retorna um valor inteiro entre 0 e 39.
	*/
	int sortearCarta();
    
	/**
	* @brief Lógica para inicializar o baralho.
	* @details Atribuição manual do nome, índice numérico e id de todas as 40 cartas que fazem parte do baralho.
	*/
	void inicializarBaralhoCompleto();
    
	/**
	* @brief Lógica para remover carta.
	* @details Exclue a carta, com base no índice passado como parâmetro, em determinado
  	* conjunto.
	* @param Índice do tipo inteiro contendo o id da carta que será deletada.
	*/ 
	void deletarCartaBaralho(int indice);
    
	/**
	* @brief Lógica para inicializar as cartas iniciais.
	* @details Geração e inclusão de três cartas aleatórias no conjunto de cartas de
	* cada um dos quatro jogadores utilizando o método sortearCarta e exclusão das cartas
	* selecionadas do baralhos.	
	*/ 
	void inicializarMaoJogadores();
    
	/**
	* @brief Lógica para resetar todos os conjuntos de carta.
	* @details Deleta as cartas armazenadas dos quatro jogadores e do baralho.
	*/
	void resetarBaralhoEMaoJogadores();
    
	/**
	* @brief Lógica para retornar as cartas do jogador 0.
	* @details Retorna o conjunto de cartas atualizado com a ultima modificação
	* feita.
	* @return Retorna o membro privado _maoJogador0.
	*/
	std::vector<Carta> getMaoJogador0();
    
	/**
	* @brief Lógica para retornar as cartas do jogador 1.
	* @details Retorna o conjunto de cartas atualizado com a ultima modificação
	* feita.
	* @return Retorna o membro privado _maoJogado1.
	*/
	std::vector<Carta> getMaoJogador1();
    
	/**
	* @brief Lógica para retornar as cartas do jogador 2.
	* @details Retorna o conjunto de cartas atualizado com a ultima modificação
	* feita.
	* @return Retorna o membro privado _maoJogador2 do tipo Carta.
	*/
	std::vector<Carta> getMaoJogador2();
    
	/**
	* @brief Lógica para retornar as cartas do jogador 3.
	* @details Retorna o conjunto de cartas atualizado com a ultima modificação
	* feita.
	* @return Retorna o membro privado _maoJogador3 do tipo Carta.
	*/
	std::vector<Carta> getMaoJogador3();
	
	/**
	* @brief Lógica para retornar o tamanho do conjunto cartas.
	* @details Retorna a quantidade de cartas que tem no baralho.
	* @return Retorna número inteiro entre 1 e 40.
	*/
    int getBaralhoSize();
};

#endif
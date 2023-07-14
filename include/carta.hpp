/**
 * @file carta.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica da carta
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Carta é responsável por armazenar os dados referente
 * as cartas do jogo.
 * @copyright GNU General Public License v2.0
 */

#ifndef CARTA_HPP
#define CARTA_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

/**
* @brief Armazena informações básicas de uma carta para o jogo.
* @details Implementa a lógica para salvar informações como o nome, o peso e o id
* de cada carta.
*/
class Carta
{
private:
	/**
    * @brief Nome da carta.
    */
    std::string _nome;
	
	/**
    * @brief Peso da carta.
    */
    int _peso;
	
	/**
    * @brief Número de 0 a 39 que identifica a carta.
    */
    int _id;

public:
	/** 
	* @brief Constrói o objeto da classe Carta.
	* @details Inicializa os atributos do objeto de acordo com os parâmetros.	
	* @param Nome da carta do tipo string, peso informando o valor da carta do tipo
	* inteiro e número entre 0 e 39 do tipo inteiro para identificar a carta.
	*/
    Carta(std::string nome, int peso, int id);
	
	/**
	@brief Método que retorna o nome da carta.
	@details Implementa a lógica para retornar o nome da carta.
	@return Retorna o membro privado _nome do tipo string.
	*/
	std::string getNome();
    
	/**
	@brief Método que retorna o peso da carta.
	@details Implementa a lógica para retornar o peso da carta.
	@return Retorna o membro privado _peso do tipo inteiro.
	*/
	int getPeso();
    
	/**
	@brief Método que retorna o número de identificação da carta.
	@details Implementa a lógica para retornar o número de identificação da carta.
	@return Retorna o membro privado _id do tipo inteiro.
	*/
	int getId();
    
	/**
	@brief Lógica para "setar" o número de identificação da carta.
	@details Definição do número de identificação da carta com base no paramêtro
	recebido.
	@param Número do tipo inteiro utlizado para identificar a carta.
	*/
	void setId(int num);
    
	/**
	@brief Lógica para imprimir a carta.
	@details Exibe na tela o nome da carta selecionada.
    */
	void imprimeCarta();
};

#endif
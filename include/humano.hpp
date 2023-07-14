/**
 * @file humano.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica do humano
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Humano é responsável para armazenar e processar
 * todas as informações do usuário que serão utilizadas no decorrer do jogo.
 * Além disso, a classe ErroEscolhaCartaInvalida define a mensagem que
 * será retornada quando houver um erro com a entrada do valor
 * @copyright GNU General Public License v2.0
 */

#ifndef HUMANO_HPP
#define HUMANO_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

/**
* @brief Classe para detectar erros.
* @details Define um método para exibir uma mensegem quando ocorrer um erro,
* nesse caso, se o usuário selecionar uma carta usando um valor que não pertence a ela.
*/
class ErroEscolhaCartaInvalida : public std::exception
{
public:
	
	/**
    * @brief Método para mensagem de erro.
    * @details Implementa a lógica para retornar uma mensagem quando for
	* detectado um erro.
    */
    virtual const char *what() const noexcept
    {
        return "Numero para selecionar cartas invalido";
    }
};

/**
 * @brief Classe que armazena e processa as informações do usuário.
 * @details Implementa a lógica para definir as informações básicas.
 * do usuário, como por exemplo, o nome, quais cartas ele tem acesso,
 * se ele deseja pedir truco e qual carta ele deseja jogar.
 */
class Humano : public Jogador
{
public:
    Humano();
    
	/**
	* @brief Contrução do objeto da classe Humano.
	* @details Constrói o objeto por meio do construtor da classe jogador.
	* Isso é possóvel devido a relação de herança entre as classes.
	* @param Recebe o parâmetro do tipo string para identificar o nome do usuário, 
	* o inteiro referente ao id da dupla que faz parte e o outro número inteiro para
	* identificar seu próprio id.
	*/	
	Humano(std::string nome, int idDupla, int idJogador);
    
	/**
	* @brief Exibe as cartas do usuário.
	* @details Implementa a lógica para exibir na tela as cartas disponíveis.
	* para serem jogadas do usuário.
	*/
	void imprimeCartasJogador();
    
	/**
	* @brief Mensagem para seleção das cartas.
	* @details De acordo com a quantidade de cartas do usuário é exibido na
	* tela uma mensegem pedindo um número ao usuário referente a qual carta ele 
	* deseja jogar.
	*/
	void msgSelecionarCartas();
    
	/**
	* @brief Método para detectar erros.
	* @details Se o usuário digitar um valor de entrada diferente de 1, 2 ou 3
 	* durante a selação das cartas será considerado erro.
	*/
	void checaIndice(int indice);
    
	/**
	* @brief Seleciona uma das três cartas.
	* @details Implementa a lógica para lançar uma carta a partir do valor
	* inserido pelo usuário e, em seguida, retira a mesma carta do baralho 
	* do usuário.
	* @return Retorna a carta que o usuário selecionou.
	*/
	Carta jogarCarta(int indice) override;
};

#endif

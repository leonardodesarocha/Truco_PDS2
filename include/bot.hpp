/**
 * @file bot.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica do bot
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Bot é responsável para armazenar e processar
 * todas as informações do usuário que serão utilizadas no decorrer do jogo 
 * @copyright GNU General Public License v2.0
 */

#ifndef BOT_HPP
#define BOT_HPP

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
* @brief Armazena e processa as informações do bot.
* @details Implementa a lógica para definir as informações básicas
* do bot, como por exemplo, o nome, quais cartas ele tem acesso,
* se ele deseja pedir truco e qual carta ele deseja jogar.
*/
class Bot : public Jogador
{
public:
    Bot();
	
	/**
	* @brief Contrução do objeto da classe Bot.
	* @details Constrói o objeto por meio do construtor da classe jogador.
	* Isso é possóvel devido a relação de herança entre as classes.
	*/
    Bot(std::string nome, int idDupla, int idJogador);
    
	/**
	* @brief Método para o bot pedir truco.
	* @details Implementa a lógica para gerar pedidos de truco pelo bot de forma
	* aleatória.
	*/
	bool pedirTruco() override;
    
	/**
	* @brief Método para o bot aceitar truco.
	* @details Implementa a lógica para o bot aceitar truco de forma
	* aleatória.
	*/
	bool aceitarTruco() override;
    
	/**
	* @brief Seleciona uma das três cartas.
	* @details Implementa a lógica para lançar uma carta a partir do valor
	* aleatório gerado e, em seguida, retira a mesma carta do baralho 
	* do bot.
	* @return Retorna a carta que o usuário selecionou.
	*/
	Carta jogarCarta(int numAleatorio) override;
};

#endif

/**
 * @file jogador.hpp
 * @author Daniel Augusto Castro de Paula, Leonardo D’avila Teixeira Soares,     
 * Leonardo de Sá Rocha Fernandes
 * @brief Classe com a lógica do jogador
 * @version 1.0
 * @date 2022-12-06
 * @details A classe Jogador é responsável para armazenar e processar 
 * todas as informações do jogador que serão utilizadas no decorrer do jogo
 * @copyright GNU General Public License v2.0
 */

#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "carta.hpp"
#include "baralho.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

/**
* @brief Armazena e processa as informações do jogador.
* @details Implementa a lógica para definir as informações básicas
* dos jogadores, como por exemplo, o nome, quais cartas ele tem acesso,
* se ele deseja pedir truco e qual carta ele deseja jogar.
*/
class Jogador
{
protected:
    
	/**
	* @brief String contendo o nome do jogador.
	*/
	std::string _nome;
    
	/**
	* @brief Vetor de Cartas contendo as cartas que o jogador tem acesso.
	*/
	std::vector<Carta> _mao;
    
	/**
	* @brief Número inteiro referente a pontuação do jogador.
	*/
	int _pontos = 0;
    
	/**
	* @brief Número inteiro para identidicar o jogador.
	*/
	int _idJogador;
    
	/**
	* @brief Número inteiro para identidicar a dupla do jogador.
	*/
	int _idDupla;
    
	/**
	* @brief Atriduto booleano para identificar se o jogador deseja
	* pedir o truco.
	*/
	bool _pedindoTruco = false;
    
	/**
	* @brief Atriduto booleano para identificar se o jogador deseja
	* aceitar o truco.
	*/
	bool _aceitandoTruco = false;

public:


    Jogador();
    
	/** 
	* @brief Constrói o objeto da classe Jogador.
	* @details Inicializa os atributos do objeto de acordo com os parâmetros.
	* @param Nome do jogador do tipo string, número de identificação da dupla do tipo
	* inteiro e número de identificação do jogador do tipo inteiro.
	*/
	Jogador(std::string nome, int idDupla, int idJogador);
    
	/** 
	* @brief Lógica para o jogador pedir o truco.
	* @details Implementa a lógica para o jogador pedir truco.
	* @return Retorna uma resposta booleana, se desejar pedir truco retorna "true",
	* caso contrário, "false".
	*/
	virtual bool pedirTruco();
    
	/** 
	* @brief Lógica para o jogador aceitar o truco.
	* @details Implementa a lógica para o jogador aceitar o truco.
	* @return Retorna uma resposta booleana, se desejar aceitar o truco retorna
	* "true", caso contrário, "false".
	*/
	virtual bool aceitarTruco();
    
	/** 
	* @brief Lógica para retornar pontuação do jogador.
	* @details Implementa a lógica para retornar a pontuação do jogador.
	* @return Número inteiro entre 0 e 12 referente a quantidade de pontos
	* do jogador.
	*/
	int getPontos();
    
	/** 
	* @brief Lógica para adicionar os pontos do jogador.
	* @details De acordo com o valor da rodada, esse método soma a pontuação
	* da rodada a pontuação do jogador caso ele seja o vencedor.
	* @param Número inteiro que representa o valor da rodada.
	*/
	void adicionaPontos(int pontos);
    
	/** 
	* @brief Lógica para retornar o nome do jogador.
	* @details Implementa a lógica para retornar o nome do jogador.
	* @return Retorna a string com o nome do jogador.
	*/
	std::string getNome();
    
	/** 
	* @brief Lógica para selecionar uma das três cartas disponíveis para
	* o jogador.
	* @details De acordo com o parâmetro recebido, é selecionada a carta que 
	* o jogador deseja jogar e, consequentemente, a mesma carta é deletada do
	* conjunto de cartas do jogador.
	* @param Número inteiro entre 1 e 3 para identificar a carta selecionada.
	* @return Retorna a carta selecionada do tipo Carta.
	*/
	virtual Carta jogarCarta(int indice);
    
	/** 
	* @brief Lógica salvar as cartas recebidas.
	* @details Implementa a lógica para armazenar as cartas recebidas no
	* início de cada rodada de cada jogador de acordo com o vector de Cartas
	* recebido como parâmetro.
	* @param Vector de Cartas referente ao conjunto de cartas distribuídos para
	* o jogador.
	*/
	void setMao(std::vector<Carta> mao);

    /** 
	* @brief Lógica retornar a quantidade de cartas do jogador.
	* @details Implementa a lógica para retornar um número inteiro
	* referente a quantidade de cartas no conjunto.
	* @return Retorna um número inteiro entre 1 e 3 para a quantidade
	* de cartas que o jogador possui.
	*/
	int getMaoSize();
};
#endif
#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/humano.hpp"
/** DEBUG
#include "jogador.cpp"
#include "baralho.cpp"*/

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Humano::Humano(){};

Humano::Humano(std::string nome, int idDupla, int idJogador) : Jogador(nome, idDupla, idJogador)
{
}

void Humano::imprimeCartasJogador()
{
    std::cout << "Cartas disponiveis para escolha:" << std::endl;
    for (int i = 0; i < int(_mao.size()); i++)
    {
        std::cout << _mao[i].getNome() << " -peso:" << _mao[i].getPeso() << ", ";
    }
}

void Humano::checaIndice(int indice)
{
    if (!isalpha((unsigned char)indice))
    {
        if (indice > int(_mao.size()) || indice < 1)
        {
            indice = 5;
            std::cin.clear();
        }
    }

    if (indice > int(_mao.size()) || indice < 1)
    {
        fflush(stdin);
        throw ErroEscolhaCartaInvalida();
    }
}

Carta Humano::jogarCarta(int indice)
{

    // logica para selecionar uma das 3 cartas, ja que o iterator begin retorna o endereço para primeira posicao
    // se vier um indice invalido vai jogar a carta na posicao 0
    std::vector<Carta>::iterator it = _mao.begin();
    if (indice == 2)
    {
        ++it;
    }
    else if (indice == 3)
    {
        ++it;
        ++it;
    }
    Carta cartaSelecionada = *(it);
    _mao.erase(it);
    return cartaSelecionada;
}

void Humano::msgSelecionarCartas()
{
    if (_mao.size() == 1)
    {
        std::cout << "Digite 1 para escolher a primeira carta" << std::endl;
    }
    else if (_mao.size() == 2)
    {
        std::cout << "Digite 1 para escolher a primeira carta, 2 para escolher a segunda" << std::endl;
    }
    else if (_mao.size() == 3)
    {
        std::cout << "Digite 1 para escolher a primeira carta, 2 para escolher a segunda ou 3 para a terceira" << std::endl;
    }
}

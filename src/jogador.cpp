#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Jogador::Jogador(){};

Jogador::Jogador(std::string nome, int idDupla, int idJogador)
{
    _nome = nome;
    _idDupla = idDupla;
    _idJogador = idJogador;
}

bool Jogador::pedirTruco()
{
    _pedindoTruco = true;
    return true;
}

bool Jogador::aceitarTruco()
{
    _aceitandoTruco = true;
    return true;
}

int Jogador::getPontos()
{
    return _pontos;
}

void Jogador::adicionaPontos(int pontos)
{
    _pontos += pontos;
}

std::string Jogador::getNome()
{
    return _nome;
}

Carta Jogador::jogarCarta(int indice)
{
    // logica para selecionar uma das 3 cartas, ja que o iterator begin retorna o endereço para primeira posicao
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

void Jogador::setMao(std::vector<Carta> mao)
{
    _mao = std::vector<Carta>(mao);
}

// metodos auxiliares testes

int Jogador::getMaoSize()
{
    return _mao.size();
}

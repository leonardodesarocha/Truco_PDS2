#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Rodada::Rodada()
{
    _vitoriasParciaisDupla1 = 0;
    _vitoriasParciaisDupla2 = 0;
};

void Rodada::inserirCartaDupla1(Carta carta)
{
    _cartasDupla1Mesa.push_back(carta);
}

void Rodada::inserirCartaDupla2(Carta carta)
{
    _cartasDupla2Mesa.push_back(carta);
}

void Rodada::setMaiorIdMd3(int num)
{
    _maiorIdMd3 = num;
}

int Rodada::getMaiorIdMd3()
{
    return _maiorIdMd3;
}

int Rodada::idJogadorMaiorCarta(int peso0, int peso1, int peso2, int peso3)
{
    std::vector<int> pesos;
    pesos.push_back(peso0);
    pesos.push_back(peso1);
    pesos.push_back(peso2);
    pesos.push_back(peso3);
    int idMaiorPeso = 0;
    int maiorPeso = peso0;
    for (int i = 0; i < 4; i++)
    {
        if (pesos[i] > maiorPeso)
        {
            maiorPeso = pesos[i];
            idMaiorPeso = i;
        }
    }
    return idMaiorPeso;
}

// checagem de vitoria de cada queda da md3 que compoe a rodada e zera as cartas na mesa
void Rodada::checagemVitoriaParcial()
{
    int pesoMaiorCartaDupla1 = _cartasDupla1Mesa[0].getPeso();
    if (_cartasDupla1Mesa[1].getPeso() > pesoMaiorCartaDupla1)
    {
        pesoMaiorCartaDupla1 = _cartasDupla1Mesa[1].getPeso();
    }

    int pesoMaiorCartaDupla2 = _cartasDupla2Mesa[0].getPeso();
    if (_cartasDupla2Mesa[1].getPeso() > pesoMaiorCartaDupla2)
    {
        pesoMaiorCartaDupla2 = _cartasDupla2Mesa[1].getPeso();
    }

    if (pesoMaiorCartaDupla1 > pesoMaiorCartaDupla2)
    {
        _vitoriasParciaisDupla1 = _vitoriasParciaisDupla1 + 1;
    }
    else if (pesoMaiorCartaDupla2 > pesoMaiorCartaDupla1)
    {
        _vitoriasParciaisDupla2 = _vitoriasParciaisDupla2 + 1;
    }
    _cartasDupla1Mesa.clear();
    _cartasDupla2Mesa.clear();
}

// checagem de vitoria da rodada
int Rodada::checagemDuplaVencedora()
{
    if (_vitoriasParciaisDupla1 == 2)
    {
        return 1;
    }
    else if (_vitoriasParciaisDupla2 == 2)
    {
        return 2;
    }
    return 0;
}

int Rodada::getVitoriasParciaisDupla1()
{
    return _vitoriasParciaisDupla1;
}

int Rodada::getVitoriasParciaisDupla2()
{
    return _vitoriasParciaisDupla2;
}

int Rodada::getPontuacaoRodadaAtual()
{
    return _pontuacaoRodadaAtual;
}

void Rodada::aumentaPontuacaoRodadaAtual()
{
    _pontuacaoRodadaAtual += 2;
}

void Rodada::resetPontuacaoRodadaAtual()
{
    _pontuacaoRodadaAtual = 2;
}

void Rodada::resetVitoriasParciaisDuplas()
{
    _vitoriasParciaisDupla1 = 0;
    _vitoriasParciaisDupla2 = 0;
}

int Rodada::getQtdQuedasRodadaAtual()
{
    return _qtdQuedasRodadaAtual;
}

void Rodada::aumentaQtdQuedasRodadaAtual()
{
    _qtdQuedasRodadaAtual = _qtdQuedasRodadaAtual + 1;
}

void Rodada::resetQtdQuedasRodadaAtual()
{
    _qtdQuedasRodadaAtual = 0;
}
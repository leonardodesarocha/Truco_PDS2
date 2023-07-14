#include "../include/carta.hpp"
#include "../include/baralho.hpp"
// DEBUG #include "carta.cpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

Baralho::Baralho()
{
    _baralho = std::vector<Carta>();
    _maoJogador0 = std::vector<Carta>();
    _maoJogador1 = std::vector<Carta>();
    _maoJogador2 = std::vector<Carta>();
    _maoJogador3 = std::vector<Carta>();

    _baralho.reserve(40);
    _maoJogador0.reserve(3);
    _maoJogador1.reserve(3);
    _maoJogador2.reserve(3);
    _maoJogador3.reserve(3);
};

int Baralho::sortearCarta()
{
    int indiceCarta = rand() % _baralho.size();
    return indiceCarta;
}

void Baralho::inicializarBaralhoCompleto()
{
    _baralho.push_back(Carta("4 de ouros", 1, 0));
    _baralho.push_back(Carta("4 de espadas", 1, 1));
    _baralho.push_back(Carta("4 de copas", 1, 2));

    _baralho.push_back(Carta("5 de paus", 2, 3));
    _baralho.push_back(Carta("5 de espadas", 2, 4));
    _baralho.push_back(Carta("5 de copas", 2, 5));
    _baralho.push_back(Carta("5 de ouros", 2, 6));

    _baralho.push_back(Carta("6 de paus", 3, 7));
    _baralho.push_back(Carta("6 de espadas", 3, 8));
    _baralho.push_back(Carta("6 de copas", 3, 9));
    _baralho.push_back(Carta("6 de ouros", 3, 10));

    _baralho.push_back(Carta("7 de paus", 4, 11));
    _baralho.push_back(Carta("7 de espadas", 4, 12));

    _baralho.push_back(Carta("Dama de ouros", 5, 13));
    _baralho.push_back(Carta("Dama de espadas", 5, 14));
    _baralho.push_back(Carta("Dama de copas", 5, 15));
    _baralho.push_back(Carta("Dama de paus", 5, 16));

    _baralho.push_back(Carta("Valete de ouros", 6, 17));
    _baralho.push_back(Carta("Valete de espadas", 6, 18));
    _baralho.push_back(Carta("Valete de copas", 6, 19));
    _baralho.push_back(Carta("Valete de paus", 6, 20));

    _baralho.push_back(Carta("Rei de ouros", 7, 21));
    _baralho.push_back(Carta("Rei de espadas", 7, 22));
    _baralho.push_back(Carta("Rei de copas", 7, 23));
    _baralho.push_back(Carta("Rei de paus", 7, 24));

    _baralho.push_back(Carta("As de paus", 8, 25));
    _baralho.push_back(Carta("As de ouros", 8, 26));
    _baralho.push_back(Carta("As de copas", 8, 27));

    _baralho.push_back(Carta("2 de paus", 9, 28));
    _baralho.push_back(Carta("2 de espadas", 9, 29));
    _baralho.push_back(Carta("2 de copas", 9, 30));
    _baralho.push_back(Carta("2 de ouros", 9, 31));

    _baralho.push_back(Carta("3 de paus", 10, 32));
    _baralho.push_back(Carta("3 de espadas", 10, 33));
    _baralho.push_back(Carta("3 de copas", 10, 34));
    _baralho.push_back(Carta("3 de ouros", 10, 35));

    _baralho.push_back(Carta("7 de ouros", 11, 36));

    _baralho.push_back(Carta("Espadilha", 12, 37));

    _baralho.push_back(Carta("7 de copas", 13, 38));

    _baralho.push_back(Carta("Zap", 14, 39));

    // Carta &ultimaCarta = _baralho[39];
}

void Baralho::deletarCartaBaralho(int indice)
{
    if (indice < 0 || indice > 39)
    {
        throw std::exception();
    }
    auto it = _baralho.begin();
    for (int i = 0; i < indice; i++)
    {
        ++it;
    }
    for (int j = indice + 1; j < int(_baralho.size()); j++)
    {
        _baralho[j].setId(_baralho[j].getId() - 1);
    }
    _baralho.erase(it);
}

void Baralho::inicializarMaoJogadores()
{
    for (int i = 0; i < 3; i++)
    {
        Carta &_cartaSelecionada1 = _baralho[sortearCarta()];
        _maoJogador0.push_back(_cartaSelecionada1);
        deletarCartaBaralho(_cartaSelecionada1.getId());
    }

    for (int i = 0; i < 3; i++)
    {
        Carta &_cartaSelecionada2 = _baralho[sortearCarta()];
        _maoJogador1.push_back(_cartaSelecionada2);
        deletarCartaBaralho(_cartaSelecionada2.getId());
    }

    for (int i = 0; i < 3; i++)
    {
        Carta &_cartaSelecionada3 = _baralho[sortearCarta()];
        _maoJogador2.push_back(_cartaSelecionada3);
        deletarCartaBaralho(_cartaSelecionada3.getId());
    }

    for (int i = 0; i < 3; i++)
    {
        Carta &_cartaSelecionada4 = _baralho[sortearCarta()];
        _maoJogador3.push_back(_cartaSelecionada4);
        deletarCartaBaralho(_cartaSelecionada4.getId());
    }
}

void Baralho::resetarBaralhoEMaoJogadores()
{
    _baralho.clear();
    _maoJogador0.clear();
    _maoJogador1.clear();
    _maoJogador2.clear();
    _maoJogador3.clear();
}

std::vector<Carta> Baralho::getMaoJogador0()
{
    return _maoJogador0;
}

std::vector<Carta> Baralho::getMaoJogador1()
{
    return _maoJogador1;
}

std::vector<Carta> Baralho::getMaoJogador2()
{
    return _maoJogador2;
}

std::vector<Carta> Baralho::getMaoJogador3()
{
    return _maoJogador3;
}

int Baralho::getBaralhoSize()
{
    return _baralho.size();
}

#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include <stdlib.h>

#define CLEAR "clear"

Menu::Menu()
{
}

//  função para cadastrar um usuário

//  Como o arquivo será escrito:
//  nome senha partidas vitorias "porcentagem de vitorias"
//  ------------------------------------------------------
//  name password games victorys pv
void Menu::cadastroUsuario()
{
    system("cls");

    // cria a variavel name e manda inserir um nome
    std::string name;
    std::cout << "REGISTRO\n\n";
    std::cout << "Crie um nick:\n";
    std::getline(std::cin, name);

    // loop para checar se o nome segue todas as restrições
    while (1)
    {
        if (strMaxTamChecker(name, MAXTAM_NAME))
        {
            std::cout << "\nNick com mais de " << MAXTAM_NAME << " caracteres, tente outro:";
        }

        else if (strMinTamChecker(name, MINTAM_NAME))
        {
            std::cout << "\nNick com menos de " << MINTAM_NAME << " caracteres, tente outro:";
        }

        else if (strSpaceChecker(name))
        {
            std::cout << "\nNick com espaco, tente outro:";
        }

        else if (findName(name))
        {
            std::cout << "\nNick ja utilizado, tente outro:\n";
        }

        else
        {
            break;
        }
        std::cout << "\n";
        std::getline(std::cin, name);
    }

    // cria a variavel password e manda inserir uma senha
    std::string password;
    std::cout << "\n\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Crie uma senha:\n";
    std::cin >> password;
    std::cout << "\n";

    // loop para checar se a senha segue todas as restrições
    while (1)
    {
        if (strMaxTamChecker(password, MAXTAM_PASSWORD))
        {
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com mais de " << MAXTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, password);
        }

        else if (strMinTamChecker(password, MINTAM_PASSWORD))
        {
            std::cout << "Senha com menos de " << MINTAM_PASSWORD << " caracteres, tente outra:\n";
            std::getline(std::cin, password);
        }

        else if (strSpaceChecker(password))
        {
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha com espaco, tente outra:\n";
            std::getline(std::cin, password);
        }

        else
        {
            break;
        }
    }

    // cria um jogador com o nome e a senha escolhida
    playerCreate(name, password);
    std::cout << "\n";
    std::cout << "Jogador registrado\n\n";
    system("pause");
    system("cls");
}

//  função para imprimir ranking
void Menu::ranking()
{
    system("cls");

    // verifica se existe um arquivo com jogadores cadastrados
    std::ifstream base("base.txt");
    if (!base)
    {
        std::cout << "Nao ha jogadores cadastrados, impossivel exibir ranking";
    }

    else
    {
        //  cria um set com todas as porcentagem de vitorias (em ordem crescente)
        std::set<float> p = pvs();
        float x[int(p.size())];

        // preenche um vetor com os valores de set
        int z = 0;
        for (auto i = p.begin(); i != p.end(); ++i)
        {
            x[z] = *i;
            z++;
        }

        std::cout << "Pos.   Nick                  Pv\n";
        std::cout << "------------------------------------\n";
        // imprime o vetor em ordem decrescente
        for (int i = int(p.size()); i >= 0; i--)
        {

            // cria um set com todos os nomes que possuem o mesmo pv
            std::set<std::string> n = nicks(x[i]);

            // imprime os nomes
            for (auto j = n.begin(); j != n.end(); ++j)
            {
                std::cout << " " << p.size() - i << "  -  " << *j;

                // for para deixar os pv's alinhados
                std::string b = *j;
                for (int a = 0; a < 22 - int(b.size()); a++)
                    std::cout << " ";

                std::cout << x[i] << "\n";
            }
        }
    }
    std::cout << "\n";
    system("pause");
    system("cls");
}

//  função retorna o nome do usuario logado para depois do jogo conseguir realizar o ranking uptade
std::string Menu::loginUsuario()
{
    system("cls");

    // cria a variavel name para receber um nome
    std::string name;
    std::cout << "LOGIN\n\n";
    std::cout << "Digite o seu nick:\n";
    std::cin >> name;
    std::cout << "\n";

    // checa se o nome atende as restrições
    while (1)
    {
        if (strMaxTamChecker(name, MAXTAM_NAME))
        {
            std::cout << "Nick com mais de " << MAXTAM_NAME << ", tente outro:\n";
            std::getline(std::cin, name);
        }

        else if (strMinTamChecker(name, MINTAM_NAME))
        {
            std::cout << "Nick com menos de " << MINTAM_NAME << " caracteres, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if (strSpaceChecker(name))
        {
            std::cout << "Nick com espaco, tente outro:\n";
            std::getline(std::cin, name);
        }

        else if (!findName(name))
        {
            std::cout << "Nick nao encontrado, tente outro:\n";
            std::getline(std::cin, name);
        }

        else
        {
            break;
        }
    }

    system("cls");

    // cria a variavel name para receber um nome
    std::string password;
    std::cout << "LOGIN\n";
    std::cout << "Nick: " << name << "\n";
    std::cout << "Digite o sua senha:\n";
    std::cin >> password;
    std::cout << "\n";

    // checa se a senha atende as restrições
    while (1)
    {
        if (passwordChecker(name, password))
            break;
        else
        {
            std::cout << "Nick: " << name << "\n";
            std::cout << "Senha incorreta, tente outra:\n";
            std::getline(std::cin, password);
        }
    }

    std::cout << "Usuario " << name << " logado\n\n";
    system("pause");
    system("cls");

    return name;
}

//  função para atualizar o ranking
void Menu::uptadeRanking(std::string player, int win)
{
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;
    std::vector<std::string> escrita;
    std::string linha;

    // cria um arquivo para escrita e um para leitura
    std::ifstream base("base.txt", std::ios::in);

    // loop para copiar o antigo em um novo, modificando apenas a linha do jogador
    int i = 0;   
    while (base >> name >> password >> games >> victorys >> pv)
    {
        if (player == name)
        {
            games++;
            if (win)
                victorys++;
            pv = victorys / games;
        }
        linha = name + " " + password + " " + std::to_string(games) + " " + std::to_string(victorys) + " " + std::to_string(pv);
        escrita.push_back(linha);
        i++;
    }
    base.close();

    std::ofstream aux("base.txt", std::ios::out);
    for(int n = 0; n < i; n++) {
        aux << escrita[n];
        if(n < i - 1)
            aux << "\n";
    }
    aux.close();
}

/*-------------------------string-------------------------*/

// retorna 1 caso a string ultrapasse um tamanho maximo
bool Menu::strMaxTamChecker(std::string str, int size)
{
    if (int(str.size()) > size)
        return 1;
    return 0;
}

// retorna 1 caso a string não ultrapasse um tamanho minimo
bool Menu::strMinTamChecker(std::string str, int size)
{
    if (int(str.size()) < size)
        return 1;
    return 0;
}

// retorna 1 se a string contem espaços
bool Menu::strSpaceChecker(std::string str)
{
    for (int i = 0; i < int(str.size()); i++)
    {
        if (int(str[i]) == 32)
            return 1;
    }
    return 0;
}
/*--------------------------------------------------------*/

/*------------------------arquivo-------------------------*/

// retorna 1 se a string se encontrar como um nome no arquivo
bool Menu::findName(std::string name)
{
    std::ifstream base("base.txt", std::ios::in);
    std::string auxname;
    while (base >> auxname)
    {
        if (auxname == name)
            return 1;
    }
    base.close();
    return 0;
}

// retorna 1 se a senha do nome for verdadeira
bool Menu::passwordChecker(std::string name, std::string password)
{
    std::string auxpassword;
    std::string auxname;
    float partidas;
    float vitorias;
    float pv;

    std::ifstream base("base.txt", std::ios::in);
    while (base >> auxname >> auxpassword >> partidas >> vitorias >> pv)
    {
        if (password == auxpassword && auxname == name)
        {
            base.close();
            return 1;
        }
    }
    base.close();
    return 0;
}

// cria um novo jogador no final do arquivo
void Menu::playerCreate(std::string name, std::string password)
{

    std::ifstream teste("base.txt");
    int aux = 0;
    if (teste)
    {
        aux = 1;
    }
    teste.close();

    std::ofstream base("base.txt", std::ios::app);
    if (aux == 1)
    {
        base << "\n";
    }
    base << name << " " << password << " 0 0 0";
    base.close();
}

// cria um set com os pv's em ordem crescente
std::set<float> Menu::pvs()
{
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::set<float> s;

    std::ifstream base("base.txt", std::ios::in);

    while (base >> name >> password >> games >> victorys >> pv)
    {
        s.insert(pv);
    }
    base.close();

    return s;
}

// cria um set com todos os nomes que possuem o pv = x
std::set<std::string> Menu::nicks(float x)
{
    std::ifstream base("base.txt", std::ios::in);
    std::string name;
    std::string password;
    float games;
    float victorys;
    float pv;

    std::set<std::string> s;

    while (base >> name >> password >> games >> victorys >> pv)
    {
        if (pv == x)
            s.insert(name);
    }
    base.close();

    return s;
}

//  limpa a tela
void Menu::limparTela()
{
    system("cls");
}

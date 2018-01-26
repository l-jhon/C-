#include <iostream>
#include <fstream>
#include "ArvoreAVL.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	Pessoa *A = new Pessoa;


	ArvoreAVL<long int, Pessoa> obj1;
	ArvoreAVL<string, Pessoa> obj2;
	ArvoreAVL<string, Pessoa> obj3;

	string str;
	string cpf;
	string rg;
	string nome;
	string data;
	string cidade;
	int op;

	ifstream is("testeR.txt");

	do
	{
		system("cls");

		cout << "1 - Inserir Pessoas na Arvore\n2 - Consultar Pessoa pelo CPF\n3 - Consultar Pessoa pelo Nome\n";
		cout << "4 - Consulta por Data de Nascimento - Periodo\n5 - Validar Balanceamento da Arvore\n6 - Sair\n";
		cout << "\nDigite a opcao desejada: ";
		cin >> op;

		if (op == 1)
		{
			while (!is.eof())
			{
				getline(is, str);

				cpf = "";
				int i = 0;
				while (str[i] != ';')
				{
					cpf += str[i++];
				}

				rg = "";
				i++;
				while (str[i] != ';')
				{
					rg += str[i++];
				}

				nome = "";
				i++;
				while (str[i] != ';')
				{
					nome += str[i++];
				}

				data = "";
				i++;
				while (str[i] != ';')
				{
					data += str[i++];
				}

				cidade = "";
				i++;
				while (i < str.size())
				{
					cidade += str[i++];
				}
	
				A->set_dados(stoll(cpf.c_str()), stoll(rg.c_str()), nome, inverter(data), cidade);
				obj1.inserir(A->cpf, *A);
				obj2.inserir(A->nome, *A);
				obj3.inserir(A->data, *A);
			}
			cout << "Insercao efetuada com Sucesso!!!" << endl;
			system("PAUSE");
		}

		if (op == 2)
		{
			system("cls");

			long long  y;
			cout << "Digite o CPF:";
			cin >> y;
			*A = obj1.buscarCPF(y);
			cout << A->cpf << " - " << A->rg << " - " << A->nome << " - " << reverter(A->data) << " - " << A->cidade << endl;
			system("pause");
		}

		if (op == 3)
		{
			system("cls");
			string x;
		
			cin.ignore();
			cout << "Digite o Nome:";
			getline(cin, x);
			x = obj2.buscarNome(x);
			cout << x;
			system("pause");
		}

		if (op == 4)
		{
			system("cls");

			string dataini;
			string datafim;
			string pessoas;
			cout << "Data Inicial:";
			cin >> dataini;
			cout << "Data Final:";
			cin >> datafim;
			dataini = inverter(dataini);
			datafim = inverter(datafim);
			pessoas = obj3.buscarData(dataini, datafim);
			cout << pessoas;
			system("pause");
		}


		if (op == 5)
		{
			system("cls");
			obj1.print();
			system("pause");
		}

	} while (op != 6);

	system("PAUSE");

}




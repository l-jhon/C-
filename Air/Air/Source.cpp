#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "grafo.h"
#include "dijkstra.h"
#include "saida.h"

using namespace std;

int main()
{
	string str;
	string voo;
	string cidadeOri;
	string cidadeDest;
	string horarioSai;
	string horarioChe;
	string cidadeOriEsc;
	string horarioSaiEsc;
	string cidadeDestEsc;
	string horarioCheEsc;

	Grafo grafo;

	ifstream is("grafo-apresentacao.txt");

	while (!is.eof())
	{
		getline(is, str);

		voo = "";
		cidadeOri = "";
		horarioSai = "";
		cidadeDest = "";
		horarioChe = "";
		cidadeOriEsc = "";
		horarioSaiEsc = "";
		cidadeDestEsc = "";
		horarioCheEsc = "";

		int cont = 0;

		for (int i = 0; i < str.size(); i++)
		{
			if (isspace(str[i]))
			{
				cont++;
			}

			if (cont < 5)
			{
				if (cont == 0)
				{
					voo += str[i];
				}

				if (cont == 1)
				{
					cidadeOri += str[i];
				}

				if (cont == 2)
				{
					horarioSai += str[i];
				}

				if (cont == 3)
				{
					cidadeDest += str[i];
				}

				if (cont == 4)
				{
					horarioChe += str[i];
				}
			}

			else // possui escala
			{
				cidadeOriEsc = cidadeDest;

				if (cont == 5)
				{
					horarioSaiEsc += str[i];
				}

				if (cont == 6)
				{
					cidadeDestEsc += str[i];
				}

				if (cont == 7)
				{
					horarioCheEsc += str[i];
				}
			}
		}

		voo.erase(remove(voo.begin(), voo.end(), ' '), voo.end());
		cidadeOri.erase(remove(cidadeOri.begin(), cidadeOri.end(), ' '), cidadeOri.end());
		horarioSai.erase(remove(horarioSai.begin(), horarioSai.end(), ' '), horarioSai.end());
		cidadeDest.erase(remove(cidadeDest.begin(), cidadeDest.end(), ' '), cidadeDest.end());
		horarioChe.erase(remove(horarioChe.begin(), horarioChe.end(), ' '), horarioChe.end());
		cidadeOriEsc.erase(remove(cidadeOriEsc.begin(), cidadeOriEsc.end(), ' '), cidadeOriEsc.end());
		horarioSaiEsc.erase(remove(horarioSaiEsc.begin(), horarioSaiEsc.end(), ' '), horarioSaiEsc.end());
		cidadeDestEsc.erase(remove(cidadeDestEsc.begin(), cidadeDestEsc.end(), ' '), cidadeDestEsc.end());
		horarioCheEsc.erase(remove(horarioCheEsc.begin(), horarioCheEsc.end(), ' '), horarioCheEsc.end());

		if (!grafo.buscarVertice(cidadeOri, cidadeOri))
		{
			grafo.MontarVertice(cidadeOri, cidadeOri, "00:00", "pCity");
			grafo.MontarVertice(cidadeOri, cidadeOri, "00:00", "cCity");
		}
		grafo.MontarVertice(voo, cidadeOri, horarioSai, "pVoo");
		grafo.MontarAresta(cidadeOri, "pCity", cidadeOri, cidadeOri, "pVoo", voo); //cria uma aresta entre os vertices CidadePartida e vooPartida

		if (!grafo.buscarVertice(cidadeDest, cidadeDest))
		{
			grafo.MontarVertice(cidadeDest, cidadeDest, "00:00", "pCity");
			grafo.MontarVertice(cidadeDest, cidadeDest, "00:00", "cCity");
		}
		grafo.MontarVertice(voo, cidadeDest, horarioChe, "cVoo");
		grafo.MontarAresta(cidadeOri, "pVoo", voo, cidadeDest, "cVoo", voo);// cria uma aresta entre os vertices vooPartida e vooChegada
		grafo.MontarAresta(cidadeDest, "cVoo", voo, cidadeDest, "cCity", cidadeDest);//cria uma aresta entre os vertices CidadeChegada e vooChegada

		if (cont > 5)
		{
			grafo.MontarVertice(voo, cidadeOriEsc, horarioSaiEsc, "pVoo");
			grafo.MontarAresta(cidadeDest, "pCity", cidadeDest, cidadeOriEsc, "pVoo", voo); //cria uma aresta entre os vertices CidadeChegada e vooPartidaEscala
			grafo.MontarAresta(cidadeDest, "cVoo", voo, cidadeOriEsc, "pVoo", voo); // cria uma aresta entre os vertices vooChegada e vooPartidaEscala

			if (!grafo.buscarVertice(cidadeDestEsc, cidadeDestEsc))
			{
				grafo.MontarVertice(cidadeDestEsc, cidadeDestEsc, "00:00", "pCity");
				grafo.MontarVertice(cidadeDestEsc, cidadeDestEsc, "00:00", "cCity");
			}
			grafo.MontarVertice(voo, cidadeDestEsc, horarioCheEsc, "cVoo");
			grafo.MontarAresta(cidadeOriEsc, "pVoo", voo, cidadeDestEsc, "cVoo", voo); // cria uma aresta entre os vertices vooParticaEscala e vooChegadaEscala
			grafo.MontarAresta(cidadeDestEsc, "cVoo", voo, cidadeDestEsc, "cCity", cidadeDestEsc);//cria uma aresta entre os vertices CidadeChegadaEscala e vooChegadaEscala
		}
	}

	Dijkstra djk;
	Saida *saida; //= new Saida(grafo.QtdVertices());
	string origem;
	string destino;
	int orig;
	int dest;
	string result;
	int op;

	grafo.ligarVertices();

	do
	{
		system("cls");

		cout << "###### Opcoes ######";
		cout << endl;
		cout << "1 - Buscar menor caminho\n2 - Sair";
		cout << endl;
		cout << "Opcao escolhida:";
		cin >> op;
		cout << endl;

		if (op == 1)
		{
			cout << "Digite o nome da cidade de Partida:";
			cin >> origem;

			cout << "Digite o nome da cidade de Destino:";
			cin >> destino;

			orig = grafo.buscarIndiceVertice(origem, "pCity", origem);
			dest = grafo.buscarIndiceVertice(destino, "cCity", destino);

			saida = djk.Dijkstra_cod(grafo, orig);

			result = saida->saida(grafo, orig, dest);
			cout << endl;
			cout << result << endl;

			
		}
		system("pause");

	} while (op != 2);

	return 0;
}

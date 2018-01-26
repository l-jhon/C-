#pragma once
#include <iostream>
#include <string>
#include "grafo.h"

using namespace std;

class Saida
{
public:
	int* pai;
	int* dist;

	Saida(int tam)
	{
		pai = new int[tam];
		dist = new int[tam];
	}

	Saida(){}

	string saida(Grafo &graf, int origem, int destino)
	{
		string linha = "";
		retorno_rec(graf, origem, pai[destino], linha);

		return linha;
	}

	void retorno_rec(Grafo &graf, int origem, int destino, string &linha)
	{
		if (pai[pai[destino]] != -1)
		{
			retorno_rec(graf, origem, pai[destino], linha);

			if (graf.listVertice[destino].tipoVertice == "cVoo" || graf.listVertice[destino].tipoVertice == "cCity") // Vertice destino
			{
				std::string linha_1 = "";
				linha_1 += graf.listVertice[destino].cidade;
				linha_1 += " ";
				linha_1 += graf.listVertice[destino].formatoHora;
				linha_1 += " ";

				linha += linha_1;

			}
			else
			{
				if (graf.listVertice[destino].voo != graf.listVertice[pai[destino]].voo)
				{
					std::string linha_1 = "\n";
					linha_1 += graf.listVertice[destino].voo; 
					linha_1 += " ";
					linha_1 += graf.listVertice[destino].cidade;
					linha_1 += " ";
					linha_1 += graf.listVertice[destino].formatoHora;
					linha_1 += " ";

					linha += linha_1;
				}
				else
				{
					string linha_1 = " ";
					linha_1 += graf.listVertice[destino].formatoHora;
					linha_1 += " ";

					linha += linha_1;
				}
			}
		}

		else if (graf.listVertice[pai[destino]].cidade == graf.listVertice[origem].cidade) // Cidade de origem
		{
			string linha_1 = "";
			linha_1 += graf.listVertice[destino].voo;
			linha_1 += " ";
			linha_1 += graf.listVertice[destino].cidade;
			linha_1 += " ";
			linha_1 += graf.listVertice[destino].formatoHora;
			linha_1 += " ";

			linha += linha_1;
		}
	}
};

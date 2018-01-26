#pragma once
#include <iostream>
#include <vector>
#include "vertice.h"
#include <string>

using namespace std;

class Grafo
{
public:
	Grafo(){}

	vector<Vertice> listVertice;

	void MontarVertice(string, string, string, string);
	void MontarAresta(string, string, string, string, string, string);
	void ligarVertices();
	void printVertice();
	void printAresta();

	bool buscarVertice(string, string);
	int buscarIndiceVertice(string, string, string);
	int QtdVertices();
};


int Grafo::QtdVertices()
{
	int cont = 0;

	for (int i = 0; i < listVertice.size(); i++)
	{
		cont += 1;
	}

	return cont;
}

bool Grafo::buscarVertice(string voo, string cidade)
{
	for (int i = 0; i < listVertice.size() || listVertice.empty(); i++)
	{
		if (i == listVertice.capacity())
		{
			return false;
		}
		else if (listVertice[i].voo == voo && listVertice[i].cidade == cidade)
		{
			return true;
		}
	}
	return false;
}

void Grafo::MontarVertice(string voo, string cidade, string hora, string tipo)
{
	Vertice v;
	int id = QtdVertices();
	v.setVoo(voo);
	v.setCidade(cidade);
	v.setHorario(hora);
	v.setFormatHora(hora);
	v.setTipo(tipo);
	v.setId(id);

	listVertice.push_back(v);
}

void Grafo::MontarAresta(string cidadeOri, string vooP, string codVooP, string cidadeDest, string vooC, string codVooC)
{
	Aresta a;

	int peso = 0;
	int posDestino = 0;
	int posVertice = 0;

	posVertice = buscarIndiceVertice(cidadeOri, vooP, codVooP);
	posDestino = buscarIndiceVertice(cidadeDest, vooC, codVooC);

	peso = listVertice[posDestino].horario - listVertice[posVertice].horario;

	if ((listVertice[posVertice].cidade == listVertice[posDestino].cidade) && ((vooP == "pCity" && vooC == "pVoo") || (vooP == "cVoo" && vooC == "cCity")))
	{
		peso = 0;
	}
	else
	{
		if (peso < 0)
		{
			peso += 1440;
		}
		else
		{
			if (peso < 30 && ((listVertice[posVertice].cidade == listVertice[posDestino].cidade) && (listVertice[posVertice].voo != listVertice[posDestino].voo)))
			{
				peso = (listVertice[posVertice].horario + 1440) - listVertice[posDestino].horario;
			}
			else
			{
				peso = listVertice[posDestino].horario - listVertice[posVertice].horario;
			}
		}
	}
	a.setDest(posDestino);
	a.setPeso(peso);

	listVertice.at(posVertice).AdicionarAresta(a);
}

int Grafo::buscarIndiceVertice(string cidade, string tipoV, string codVoo)
{
	for (int i = 0; i < listVertice.size(); i++)
	{
		 if (listVertice[i].cidade == cidade && listVertice[i].tipoVertice == tipoV && listVertice[i].voo == codVoo)
		{
	        return i;
		}
	}
	return -1;
}

void Grafo::ligarVertices()
{
	int j;

	for (int i = 0; i < listVertice.size(); i++)
	{
		if (listVertice[i].tipoVertice == "cVoo" && listVertice[i].voo != listVertice[i].cidade)
		{
			j = buscarIndiceVertice(listVertice[i].cidade, "pCity", listVertice[i].cidade);

			for (int k = 0; k < listVertice[j].listAresta.size(); k++)
			{
				int aux = listVertice[j].listAresta[k].getDestino();

				if (listVertice[i].cidade == listVertice[aux].cidade)
				{
					MontarAresta(listVertice[i].cidade, listVertice[i].tipoVertice, listVertice[i].voo, listVertice[aux].cidade, listVertice[aux].tipoVertice, listVertice[aux].voo);
				}
			}
		}
	}
}

void Grafo::printVertice()
{
	for (int i = 0; i < listVertice[i].listAresta.size(); i++)
	{
		cout << "Codigo do voo: " << listVertice[i].voo << endl;
		cout << "Cidade: " << listVertice[i].cidade << endl;
		cout << "Tipo: " << listVertice[i].tipoVertice << endl;
		cout << "Hora: " << listVertice[i].formatoHora << endl;
	}
}

void Grafo::printAresta()
{
	int aux;
	for (int i = 0; i < listVertice.size(); i++)
	{
		cout << listVertice[i].voo << " ";
		for (int j = 0; j < listVertice[i].listAresta.size(); j++)
		{
			if (listVertice[i].listAresta[j].getPeso() != -1)
			{
				aux = (listVertice[i].listAresta[j].getDestino());

				cout << listVertice[aux].cidade << " ";
				cout << listVertice[aux].voo << " ";
				cout << listVertice[aux].tipoVertice << " ";
				cout << listVertice[aux].formatoHora << " " << " ==> ";
			}
		}
	}
}

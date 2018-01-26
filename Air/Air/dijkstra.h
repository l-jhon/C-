#pragma once
#include "saida.h"
#include "grafo.h"
#include <list>
#include <iostream>
#include<iomanip>

using namespace std;

class Dijkstra
{
public:
    Dijkstra() {}
    int extract_min(list<int> &Vertice, int *Distancia);
    void Relax(Saida &R, int menor, int i, int peso);
    Saida* Dijkstra_cod(Grafo &g, int origem);

};

Saida* Dijkstra::Dijkstra_cod(Grafo &g, int origem)
{
    int tam = g.listVertice.size();
    int menor; //posição que o menor ocupa
    list<int> lista;

    Saida *R = new Saida(tam);

    for (int i = 0; i < tam; i++)
    {
        lista.push_back(i);
        R->dist[i] = 50000; // Distancia infinita
        R->pai[i] = -1;
    }

    R->dist[origem] = 0;

    while (!lista.empty())
    {
        menor = extract_min(lista, R->dist); // Extrai o menor vertice com o menor peso

        for (unsigned int i = 0; i < g.listVertice[menor].listAresta.size(); i++)
        {
            Relax(*R, menor, g.listVertice[menor].listAresta[i].getDestino(), g.listVertice[menor].listAresta[i].getPeso());
        }
    }
    return R;
}

int Dijkstra::extract_min(list<int> &Vertices, int *Distancia)
{
	int i = 0, menor = 50001;
	list<int>::iterator iter;

	for (iter = Vertices.begin(); iter != Vertices.end(); iter++)
	{
		if (Distancia[*iter] < menor)
		{
			menor = Distancia[*iter];
			i = *iter;
		}
	}
	Vertices.remove(i);
	return i;// indice do menor
}

void Dijkstra::Relax(Saida &R, int menor, int i, int peso) // Controla se o novo peso de um caminho e menor do já existente  se for ele troca
{
	if (R.dist[menor] + peso < R.dist[i])
	{
		R.dist[i] = R.dist[menor] + peso;
		R.pai[i] = menor;
	}
}

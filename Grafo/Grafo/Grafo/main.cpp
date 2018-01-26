// Grafo.cpp : Define o ponto de entrada para a aplicação de console. 
//
#include <iostream>
#include <fstream>
#include "Grafo.h"
using namespace std;


int main()
{	
	Grafo* G = new Grafo("arquivo.txt");

	int x, y;
	do{
		cout << "Digite o vertice de origem, entre 0 e "<<G->getQtdVertices()-1<<": ";
		cin >> x;
	} while (x > G->getQtdVertices()-1 || x < 0);
	do{
		cout << "Digite o vertice de destino, entre 0 e " << G->getQtdVertices()-1 << ": ";
		cin >> y;
	} while (y>G->getQtdVertices()-1 || y < 0);
	
	Pilha<int>* P = new Pilha<int>();

	if (G->menorCaminho(x, y, P)){
		cout << "Tamanho do caminho: " << P->size()-1 << endl;
		cout << "Melhor caminho: ";
		P->print();
		cout << endl;
	}
	else{
		cout << "Nao existe caminho possivel!" << endl;
	}

	system("PAUSE");
	return 0;
}
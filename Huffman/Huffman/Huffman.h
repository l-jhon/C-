#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Smbolo.h"
#include <vector>
#include <algorithm>

using namespace std;
class Huffman
{
public:
	vector<Simbolo> *lista;

	void adicionarLista(Simbolo*);
	vector<Simbolo> ordenarLista(vector<Simbolo>*);
	void AlgoHuffman(vector<Simbolo>*);
	vector<Simbolo> getLista();
	Simbolo getElemento(int);
	void printArvore(string s, Simbolo* aux);
	void printBin(char, Simbolo*, string, vector <Simbolo>*);
	void gerarSaida(string, string, string, vector<Simbolo>*);

	Huffman();
};

Huffman::Huffman()
{
	lista = new vector<Simbolo>;
}

void Huffman::AlgoHuffman(vector<Simbolo> *lista)
{
	while (lista->size() > 1)
	{
		int i = 0;

		Simbolo *simbolo = new Simbolo();
		Simbolo *aux1 = new Simbolo();
		Simbolo *aux2 = new Simbolo(); 

		aux1->setPeso((lista->at(i).getPeso()));
        aux1->setChar(lista->at(i).getChar());
        aux1->dir = lista->at(i).dir;
        aux1->esq = lista->at(i).esq;
        aux2->setPeso(lista->at(i+1).getPeso()) ;
        aux2->setChar(lista->at(i+1).getChar());
        aux2->dir = lista->at(i+1).dir;
        aux2->esq = lista->at(i+1).esq;
		
		simbolo->esq = aux1;
		simbolo->dir = aux2;
		simbolo->setPeso((lista->at(0).getPeso() + (lista->at(1).getPeso())));
		lista->erase(lista->begin());
		lista->erase(lista->begin());
		lista->push_back(*simbolo);
		ordenarLista(lista);
	}

	cout << endl;
	cout << "=============================================" << endl;
	cout << "       ***** Arvore *****            " << endl;
	cout << "=============================================" << endl;
	printArvore(" ", &lista->at(0));
	cout << endl;
	cout << "=============================================" << endl;
	cout << "       ***** Dicionario *****        " << endl;
	cout << "=============================================" << endl;
	printBin(' ', &lista->at(0), "", lista);
}

Simbolo Huffman::getElemento(int pos )
{
	return lista->at(pos);
}

void Huffman::adicionarLista(Simbolo *simbolo)
{
	lista->push_back(*simbolo);
	ordenarLista(lista);
}

vector<Simbolo> Huffman::getLista()
{
	return *lista;
}

vector<Simbolo> Huffman::ordenarLista(vector<Simbolo> *lista)
{
	for (int i = 0; i < lista->size(); i++)
	{
		for (int k = i; k < lista->size(); k++)
		{
			if (lista->at(k).getPeso() < lista->at(i).getPeso())
			{
				int aux = lista->at(k).getPeso();
				char aux2 = lista->at(k).getChar();
				lista->at(k).setPeso(lista->at(i).getPeso());
				lista->at(k).setChar(lista->at(i).getChar());
				lista->at(i).setPeso(aux);
				lista->at(i).setChar(aux2);
			}
		}
	}
	return *lista;
}

void Huffman::printArvore(string s, Simbolo* aux)
{
	if (aux)
	{
		printArvore(s + "        ", aux->dir);
		cout << s << aux->getPeso() << " < " << aux->getChar() << endl;
		printArvore(s + "        ", aux->esq);

	}
}

void Huffman::printBin(char cod, Simbolo* aux, string s, vector <Simbolo>* lista)
{
	if (aux)
	{
		s += cod;
		printBin('1', aux->dir, s, lista);
		printBin('0', aux->esq, s, lista);
	}

	if (aux && aux->dir == NULL && aux->esq == NULL)
	{
		Simbolo *simbolo = new Simbolo();
		cout << "Caracter: " << aux->getChar() << " " << s << endl << endl;
		simbolo->setChar(aux->getChar());
		simbolo->setIdent(s);
		lista->push_back(*simbolo);
		s = "";
	}
}

void Huffman::gerarSaida(string arqEntrada, string arqSaida, string palavra, vector<Simbolo> *lista)
{
	ifstream entrada(arqEntrada);
	ofstream saida(arqSaida);

	if (entrada.is_open() && saida.is_open())
	{
		while (!entrada.eof())
		{
			getline(entrada, palavra);

			for (int i = 0; i<palavra.size(); i++)
			{
				for (int k = 0; k < lista->size(); k++)
				{
					if (palavra[i] == lista->at(k).getChar())
					{
						saida << lista->at(k).getIdent();
					}
				}
			}
		}
		entrada.close();
		saida.close();
	}
}

#pragma once

#include<iostream>

using namespace std;

template <typename T>

class Node
{
public:
	T x;
	T balance = 0;
	Node<T> *dir;
	Node<T> *esq;
	Node(T x) :x(x), esq(NULL), dir(NULL){}
};

template <typename T>

class ArvoreAVL
{

private:
	Node<T> * raiz;
	bool verificar;

	Node<T>* inserir_rec(Node<T>*, T);
	Node<T>* remover_rec(Node<T>*, T);
	Node<T>* rotRR(Node<T>*);
	Node<T>* rotLL(Node<T>*);
	Node<T>* rotRL(Node<T>*);
	Node<T>* rotLR(Node<T>*);
	Node<T>* buscar_rec(Node<T>*, T);
	void print_rec(Node<T>*, int);

public:
	ArvoreAVL();

	void inserir(T);
	void remover(T);
	void print();
	T buscar();
};

template <typename T>

ArvoreAVL<T>::ArvoreAVL()
{
	raiz = NULL;
}

template <typename T>
void ArvoreAVL<T>::inserir(T x)
{
	raiz = inserir_rec(raiz, x);
}

template <typename T>
Node<T>* ArvoreAVL<T>::inserir_rec(Node<T> *pto, T x)
{
	if (pto)
	{
		if (x < pto->x)
		{
			pto->esq = inserir_rec(pto->esq, x);

			if (verificar)
			{
				switch (pto->balance)
				{
				case 1:
					pto->balance = 0;
					verificar = false;
					break;
				case 0:
					pto->balance = -1;
					break;
				case -1:
					if (pto->esq->balance)
					{
						pto = rotLL(pto);
						pto->balance = 0;
						pto->dir->balance = 0;
					}
					else
					{
						pto = rotLR(pto);

						switch (pto->balance)
						{
						case 1:
							pto->esq->balance = -1;
							pto->dir->balance = 0;
							break;
						case -1:
							pto->esq->balance = 0;
							pto->dir->balance = 1;
							break;
						case 0:
							pto->esq->balance = 0;
							pto->dir->balance = 0;
							break;
						}
						pto->balance = 0;
					}
					verificar = false;
				}
			}
		}
		else
		{
			pto->dir = inserir_rec(pto->dir, x);
			
			if (verificar)
			{
				switch (pto->balance)
				{
				case -1:
					pto->balance = 0;

					verificar = false;
					break;
				case 0:
					pto->balance = 1;
					break;
				case 1:
					switch (pto->dir->balance)
					{
					case 1:
						pto = rotRR(pto);
						pto->balance = 0;
						pto->esq->balance = 0;
						break;
					case -1:
						pto = rotRL(pto);
						switch (pto->balance)
						{
						case -1:
							pto->esq->balance = 0;
							pto->dir->balance = 1;
							break;
						case 1:
							pto->esq->balance = -1;
							pto->dir->balance = 0;
							break;
						case 0:
							pto->esq->balance = 0;
							pto->dir->balance = 0;
							break;
						}
						pto->balance = 0;
						break;
					}
					verificar = false;
					break;
				}
			}

		}
	}
	else
	{
		pto = new Node<T>(x);
		verificar = true;
	}
	return pto;
}

template <typename T>
Node<T>* ArvoreAVL<T>::rotRR(Node<T> *pto)
{
	/*Node<T> aux = pto->esq;
	pto->esq = aux->dir;
	aux->dir = pto;
	return aux;*/


	Node<T> *aux1 = pto;
	pto = pto->esq;
	aux1->esq = pto->dir;
	pto->dir = aux1;
	return pto;
}

template <typename T>
Node<T>* ArvoreAVL<T>::rotLL(Node<T> *pto)
{
	/*Node<T> aux = pto->dir;
	pto->dir = aux->esq;
	aux->esq = pto;
	return aux;*/

	Node<T>*aux1 = pto;
	pto = pto->dir;
	aux1->dir = pto->esq;
	pto->esq = aux1;
	return pto;
}

template <typename T>
Node<T>* ArvoreAVL<T>::rotRL(Node<T> * pto)
{
	pto->dir = rotLL(pto->dir);
	return rotRR(pto);
}

template <typename T>
Node<T>* ArvoreAVL<T>::rotLR(Node<T> * pto)
{
	pto->esq = rotRR(pto->esq);
	return rotLL(pto);
}

template <typename T>
void ArvoreAVL<T>::print()
{
	return print_rec(raiz,0);
}

template <typename T>
void ArvoreAVL<T>::print_rec(Node<T> *pto, int i)
{
	if (pto)
	{
		i++;
		print_rec(pto->dir, i);
		for (int j = 0; j < i; j++)
			cout << "                ";
		cout << pto->x << "<" << pto->balance << ">" << endl;
		print_rec(pto->esq, i);
		i--;
	}
}

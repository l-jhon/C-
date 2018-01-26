#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	int x;
	Node* esq;
	Node* dir;
	Node(int x) :x(x), esq(NULL), dir(NULL){}
};

class Arvore
{
private:
	Node* raiz;
	int qtd;

	Node* add_rec(Node *, int);
	Node* remove_rec(Node*, int);
	Node* MVD(Node*);
	Node* buscar_rec(Node *, int);
	void print_rec(Node *);

public:
	Arvore();
	~Arvore();
	void add1(int);
	void add(int);
	Node* remove(int);
	int buscar(int);
	void print();

};


Arvore::Arvore()
{
	raiz = NULL;
	qtd = 0;
}

Arvore::~Arvore()
{
}

void Arvore::add1(int x)
{
	if (raiz == NULL)
	{
		raiz = new Node(x);
	}
	else
	{
		Node* pto = raiz;

		while (pto)
		{
			if (x < pto->x)
			{
				if (pto->esq != NULL)
				{
					pto = pto->esq;
				}
				else
				{
					pto->esq = new Node(x);
					pto = NULL;
				}
			}
			else
			{
				if (pto->esq != NULL)
				{
					pto = pto->esq;
				}
				else
				{
					pto->esq = new Node(x);
					pto = NULL;
				}
			}
		}
	}
}

void Arvore::add(int x)
{
	raiz = add_rec(raiz, x);
}

Node* Arvore::add_rec(Node * raiz, int x)
{
	if (raiz)
	{
		if (raiz->x > x)
		{
			raiz->esq = add_rec(raiz->esq, x);
		} 
		else
		{
			raiz->dir = add_rec(raiz->dir, x);
		}
	}
	else
	{
		raiz = new Node(x);
	}

	return raiz;
}


Node* Arvore::remove(int x)
{   
	return remove_rec(raiz, x);

}

Node* Arvore::remove_rec(Node *pto, int x)
{
	if (pto == NULL)
	{
		return NULL;
	}
	if (x == pto->x)
	{
		Node *aux = NULL;

		if (pto->esq == NULL)
		{
			pto = pto->dir;
		}
		else if (pto->dir == NULL)
		{
			pto = pto->esq;
		}
		else
		{
			aux = MVD(pto->esq);
			pto->x = aux->x;
		}
		delete aux;
	}
	else if (x < pto->x)
	{
		return remove_rec(pto->esq, x);
	}
	else
		return remove_rec(pto->dir, x);
}

Node* Arvore::MVD(Node *pto)
{
	Node *aux = NULL;

	aux = pto;

	if (aux->dir == NULL)
	{
		pto = pto->esq;
		return aux;
	}
	else
		return MVD(pto->dir);
}

int Arvore::buscar(int x)
{
	return buscar_rec(raiz, x)->x;
}

Node* Arvore::buscar_rec(Node *pto, int x)
{
	if (pto)
	{
		if (pto->x == x)
		{
			return pto;
		}
		else
		{
			if (pto->x > x)
			{
				return buscar_rec(pto->esq, x);
			}
			else
				return buscar_rec(pto->dir, x);
		}
	}
	else
	{
		return NULL;
	}
}

void Arvore::print()
{
   return print_rec(raiz);
}

void Arvore::print_rec(Node*pto)
{
	if (pto)
	{	
		print_rec(pto->esq);
		cout << pto->x << endl;
		print_rec(pto->dir);
	}

}


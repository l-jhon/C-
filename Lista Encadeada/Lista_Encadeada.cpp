#include "Lista_Encadeada.h"

#include <iostream>

using namespace std;

Lista_Encadeada::Lista_Encadeada()
{
	inicio = NULL;
	fim = NULL;
	s = 0;
}

void Lista_Encadeada::add(int x) // inicio 01
{
	if (!inicio)
	{
		inicio = new Node(x);
		fim = inicio;
	}
	else
	{
		fim->prox = new Node(x);
		fim = fim->prox;
		fim->prox = nullptr;
	}
	s++;

}

void Lista_Encadeada::add_pto(int x) // inicio 02
{
	if (inicio)
	{
		Node* pto = inicio;

		while (pto->prox)
		{
			pto = pto->prox;
		}
		pto->prox = new Node(x);
		pto = pto->prox;
		pto->prox = nullptr;
	}
	else
	{
		inicio = new Node(x);
	}
	s++;
}

void Lista_Encadeada::add_begin(int a)
{
	if (inicio)
	{
		Node *n = new Node(a);
		n->prox = inicio;
		inicio = n;
	}
	else
	{
		Node *n = new Node(a);
		n->prox = inicio;
		inicio = n;
	}
	s++;
}

void Lista_Encadeada::add_at(int i, int x)
{
	if (i < 0)
	{
		Node* n = new Node(x);
		n->prox = inicio;
		inicio = n;
	}
	else if (i > s)
	{
		if (inicio)
		{
			Node* pto = inicio;

			while (pto->prox)
			{
				pto = pto->prox;
			}
			pto->prox = new Node(x);
			pto = pto->prox;
			pto->prox = NULL;
		}

	if (i > 0 && i < s)
	{
		Node* n = inicio;
		
		for (int j = 0; j < i - 2; j++)
		{
			n = n->prox;
		}
			Node *pto2 = new Node(x);
			pto2->prox = n->prox;
			n->prox = pto2;
		}
		s++;
	}
}

bool Lista_Encadeada::set(int i, int x)
{
	if (i > 0 && i < s)
	{
		Node* n = inicio;

		for (int j = 0; j < i - 1; j++)
		{
			n = inicio->prox;
		}
		n -> prox -> x = x;
		return true;
	}
	else 
		return false;
}

int Lista_Encadeada::get(int i )
{
	Node * pto = inicio;

	if ( i > 0 && i <= s)
	{
		for (int j = 0; j < i - 1; j++)
		{
			pto = pto->prox;
		}
		return pto->x;
	}
	else return -1;
}


int Lista_Encadeada::find(int x)
{
	Node* pto = inicio;
	
	if (pto)
	{
		int c = 1;

		while (pto && pto->x != x)
		{
			pto = pto->prox;
			c++;
		}
		return c;
	}
	else
		return -1;
}

bool Lista_Encadeada::remove(int i)
{
	if (!inicio)
	{
		return false;
	}

	Node* pto = inicio;

	if (i == 1)
	{
		inicio = pto->prox;
		delete pto;
		return true;
	}
	else if (i > 1 && i <= s + 1)
	{
		for (int j = 1; j < i - 1 ; j++)
		{
			pto = pto->prox;
		}

		if (pto->prox)
		{
			Node* pto2 = pto->prox;
			pto->prox = pto2->prox;
			delete pto2;

			return true;
		}
		else
			return false;
	}
	s--;
}

int Lista_Encadeada::size()
{
	if (inicio)
	{
		int cont = 1;
		Node* pto = inicio;

		while(pto)
		{
			cont++;
		}
		return cont;
	}
}

void Lista_Encadeada::clear()
{
	Node* pto = inicio;

	if (pto)
	{
		while (pto)
		{
			delete pto;
		}
	}

}


bool Lista_Encadeada::is_empty()
{
	if (!inicio)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Lista_Encadeada::print()
{
	print_desc(inicio);
}

void Lista_Encadeada::print_desc(Node *pto)
{
	if (pto)
	{
		cout << pto->x << endl;	
		print_desc(pto->prox);
		
	}

}
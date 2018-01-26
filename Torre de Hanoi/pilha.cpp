#include "pilha.h"

Pilha::Pilha(int z)
{
	topo = NULL;
	inicial(z);
}

void Pilha::push(int x) 
{
	Node *no = new Node();
	no->x = x;
	no->prox = topo;
	topo = no;

}

void Pilha::inicial(int x)
{
	while (x>0)
	{
		push(x);
		x--;
	}
}

int Pilha::pop() 
{

	if (topo == NULL)
	{
		return 0;
	}
	else
	{
		Node *aux = topo;
		int	x = aux->x;
		topo = topo->prox;
		delete (aux);
		return x;
	}

}

int Pilha::get_top() 
{
	if (topo)
	{
		return topo->x;
	}
	else
		return 0;
}

bool Pilha::is_emptyi() 
{

	if (topo)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Pilha::cleari() 
{
	while (topo)
	{
		Node *tmp = topo;
		topo = topo->prox;
		delete tmp;

	}

}

int Pilha::sizei() 
{
	Node *temp = topo;
	int aux = 0;
	while (temp)
	{
		temp = temp->prox;
		aux++;
	}
	if (aux == 0)
	{
		return 0;
	}
	else
	{
		return aux;
	}
}

void Pilha::auxiliar() 
{
	print(topo);
}

void Pilha::print(Node *pto)
{
	if (pto)
	{
		print(pto->prox);
		cout << "|" << pto->x << "|-";
	}
}

void Pilha::desfazer()
{

}

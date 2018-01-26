#include "Pilha.h"


Pilha::Pilha()
{
	topo = NULL;
}	

void Pilha::push(int x)
{
	Node *no = new Node(x);
	no->prox = topo;
	topo = no;

}
int Pilha::pop()
{
	if (topo == NULL)
	{
		//cout << "Pilha vazia" << endl;
	}
	else
	{
		Node *aux = topo;
		int x = aux->x;
		topo = topo->prox;
		delete (aux);
		return x;
	}

}

int Pilha::get_top() 
{
	if (topo)
	{
		return topo -> x;

	}
		return 0;
}

bool Pilha::is_empty() 
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

void Pilha::clear() 
{
	while (topo)
	{
		Node *tmp = topo;
		topo = topo->prox;
		delete tmp;

	}

}

int Pilha::size() 
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

void Pilha::inverter() 
{
	Pilha aux1;
	Pilha aux2;

	while (topo)
	{
		aux1.push(pop());
	}

	while (aux1.topo)
	{
		aux2.push(aux1.pop());
	}

	while (aux2.topo)
	{
		push(aux2.pop());
	}
}

void Pilha::print()
{
	Node *tmp = topo;
	if (!tmp)
	{
		cout << "Pilha Vazia!" << endl;
	}
	else{
		cout << "Pilha -> ";
		while (tmp)
		{
			cout << tmp->x << " ";
			tmp = tmp->prox;
		}
	}
	cout << endl;
}

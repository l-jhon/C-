#include "pilhaDR.h"

pilhaDR::pilhaDR()
{
	topo = NULL;
}

void pilhaDR::push(int x, int y)
{
	Node *no = new Node();
	no->x = x;
	no->prox = topo;
	topo = no;

}

int pilhaDR::pop()
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

int pilhaDR::get_top()
{
	if (topo)
	{
		return topo->x;
	}
	else
		return 0;
}

bool pilhaDR::is_emptyi()
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

void pilhaDR::cleari()
{
	while (topo)
	{
		Node *tmp = topo;
		topo = topo->prox;
		delete tmp;

	}

}

int pilhaDR::sizei()
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

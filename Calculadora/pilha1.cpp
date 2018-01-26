#include "pilha1.h"

#include <math.h>

Pilha1::Pilha1(string eq)
{
	topo = NULL;

	calculoEq(eq);
}

float Pilha1::getResultado()
{
	return resultado;
}


void Pilha1::push(float x) 
{
	Node1 *no = new Node1();
	no->x = x;
	no->prox = topo;
	topo = no;

}

float Pilha1::pop() 
{
	if (topo)
	{
		float x;
		Node1 *aux = topo;
		x = aux->x;
		topo = topo->prox;
		delete (aux);
		return x;

	}

	return 0;
}


float Pilha1::get_top() 
{
	if (topo)
	{
		return topo->x;
	}

	return 0;
}

void Pilha1::calculoEq(string equacao)
{
	for (int i = 0; i < equacao.size(); i++)
	{
		if (equacao[i] >= '0' && equacao[i] <= '9')
		{
			push((float)equacao[i] - '0');
		}
		else
		{
			float x, y;
			if (equacao[i] == '+')
			{
				y = pop();
				x = pop();
				push(x + y);
			}
			else
			{
				if (equacao[i] == '-')
				{
					y = pop();
					x = pop();
					push(x - y);
				}
				else
				{
					if (equacao[i] == '*')
					{
						y = pop();
						x = pop();
						push(x*y);
					}
					else
					{
						if (equacao[i] == '/')
						{
							y = pop();
							x = pop();
							push(x / y);
						}
						else
						{
							if (equacao[i] == '^')
							{
								y = pop();
								x = pop();
								
								push(pow(x, y));
							}
						}

					}
				}
			}
		}
	}
	resultado = pop();
}

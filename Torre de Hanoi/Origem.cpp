#include <iostream>
#include "pilha.h"
#include<cstdlib>
#include<string.h>

void erro()
{
	cout << "Movimento Invalido, tente novamente!" << endl;
	system("PAUSE");
}

void desfazer()
{


}

int main()
{

	int a;
	int qtd = 0;

	cout << "Digite a quantidade de discos:";
	cin >> a;

	while (a<3 || a>7)
	{
		cout << "Digite a quantidade de discos válida(de 3 a 7):";
		cin >> a;
		system("cls");
	}

	Pilha *pino1 = new Pilha(a);
	Pilha *pino2 = new Pilha(0);
	Pilha *pino3 = new Pilha(0);

	cout << endl << "Pino A *"; pino1->auxiliar();
	cout << endl << "Pino B *"; pino2->auxiliar();
	cout << endl << "Pino C *"; pino3->auxiliar();

	int tam = pino3->sizei();

	while (tam < a)
	{
		int origem, destino;

		cout << endl;

		cout << endl << "Origem ->";
		cin >> origem;

		cout << endl << "Destino ->";
		cin >> destino;

		if (origem == 1 && destino == 2)
		{

			if (pino1->get_top() != 0)
			{
				if ((pino1->get_top() < pino2->get_top()) || pino2->get_top() == 0)
				{
					pino2->push(pino1->pop());
				}
				else
				{
					erro();
				}
			}
		}
		if (origem == 1 && destino == 3)
		{
			if (pino1->get_top() != 0)
			{
				if ((pino1->get_top() < pino3->get_top()) || pino3->get_top() == 0)
				{
					pino3->push(pino1->pop());
				}
				else
				{
					erro();
				}
			}
		}
		if (origem == 2 && destino == 1)
		{
			if (pino2->get_top() != 0)
			{
				if ((pino2->get_top() < pino1->get_top()) || pino1->get_top() == 0)
				{
					pino1->push(pino2->pop());
				}
				else
				{
					erro();
				}
			}
		}
		if (origem == 2 && destino == 3)
		{
			if (pino2->get_top() != 0)
			{
				if ((pino2->get_top() < pino3->get_top()) || pino3->get_top() == 0)
				{
					pino3->push(pino2->pop());
				}
				else
				{
					erro();
				}
			}
		}
		if (origem == 3 && destino == 1)
		{
			if (pino3->get_top() != 0)
			{
				if ((pino3->get_top() < pino1->get_top()) || pino1->get_top() == 0)
				{
					pino1->push(pino3->pop());
				}
				else
				{
					erro();
				}
			}
		}
		if (origem == 3 && destino == 1)
		{
			if (pino3->get_top() != 0)
			{
				if ((pino3->get_top() < pino1->get_top()) || pino1->get_top() == 0)
				{
					pino1->push(pino3->pop());
				}
				else
				{
					erro();
				}
			}
		}
		if (origem == 3 && destino == 2)
		{
			if (pino3->get_top() != 0)
			{
				if ((pino3->get_top() < pino2->get_top()) || pino2->get_top() == 0)
				{
					pino2->push(pino3->pop());
				}
				else
				{
					erro();
				}
			}
		}

		qtd++;

		system("cls");

		cout << endl << "Pino A *"; pino1->auxiliar();
		cout << endl << "Pino B *"; pino2->auxiliar();
		cout << endl << "Pino C *"; pino3->auxiliar();

		tam = pino3->sizei();


	}
	if (tam = a)
	{
		cout << endl;
		cout << "Voce venceu com: " << qtd << " jogadas" << endl;
	}

	system("PAUSE");
}



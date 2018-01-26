#include <iostream>
#include "Sort.h"
#include <time.h>

using namespace std;

void InicializarVetor(int *vet,int *vet1, int n)
{
	for (int j = 0; j < n; j++)
	{
		vet1[j] = vet[j];
	}
}

int main()
{
	Sort *ordenar = new Sort();

	int op;
	int op2;
	int op3;
	int n;
	float ini;
	float fin;

	do
	{
		cout << "Escolha:\n";
		cout << "1 - Ordenar Vetor\n2 - Sair do programa\n=>";
		cin >> op2;
		cout << "\nDigite o tamanho do vetor:";
		cin >> n;
		cout << "\nGerando Vetor...";

		int *vet = new int[n]; // vetor aleatório;
		int *vetaux = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++) // inserindo numeros aleatórios e sem repetição no vetor
		{
			vet[i] = (rand() % n) + 1;

			for (int j = 0; j < i; j++)
			{
				if (vet[j] == vet[i])
				{
					vet[i] = (rand() % n) + 1;
					j = -1;
				}
			}
		}
		
		system("cls");

		do
		{
			cout << "Qual o tipo de vetor a ser ordenado?\n";
			cout << "1 - Aleatorio\n2 - Crescente\n";
			cout << "3 - Decrescente\n4 - Imprimir Vetor para validar ordenacao\n";
			cout << "5 - Alterar o tamanho do vetor ou Sair\n=>";
			cin >> op;
			system("cls");

			if (op == 1)
			{

				cout << "Ordenando vetor..." << endl << endl;

				cout << "    ###### Ordenacao Crescente ######      " << endl << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->SelectionSortCresc(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Selection Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->BubbleSortCresc(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Bubble Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->InserctionSortCresc(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Inserction Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->MergeSortCresc(vetaux, 0, n - 1);
				fin = (clock() - ini)/ 1000;
				cout << "Merge Sort - Tempo de execucao: " << fin << " ms " << endl; 

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->QuickSortCresc(vetaux ,0 , n - 1);
				fin = (clock() - ini) / 1000;
				cout << "Quick Sort - Tempo de execucao: " << fin << " ms " << endl << endl;

				cout << "    ###### Ordenacao Decrescente ######      " << endl << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->SelectionSortDecres(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Selection Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->BubbleSortDecres(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Bubble Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->InserctionSortDecres(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Inserction Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->MergeSortDecres(vetaux, 0, n - 1);
				fin = (clock() - ini) * 1000;
				cout << "Merge Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->QuickSortDecres(vetaux, 0, n - 1);
				fin = (clock() - ini) / 1000;
				cout << "Quick Sort - Tempo de execucao: " << fin << " ms " << endl;

				system("pause");
				system("cls");
			}

			if (op == 2)
			{
				for (int i = 1; i < n + 1; i++)
				{
					vet[i] = i;
					vetaux[i] = i;
				}

				cout << "Ordenando vetor..." << endl << endl;

				cout << "    ###### Ordenacao Crescente ######      " << endl << endl;

				ini = clock();
				ordenar->SelectionSortCresc(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Selection Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->BubbleSortCresc(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Bubble Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->InserctionSortCresc(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Inserction Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->MergeSortCresc(vetaux, 0, n - 1);
				fin = (clock() - ini) / 1000;
				cout << "Merge Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->QuickSortCresc(vetaux, 0, n - 1);
				fin = (clock() - ini) / 1000;
				cout << "Quick Sort - Tempo de execucao: " << fin << " ms " << endl << endl;
			
				system("pause");
				system("cls");
			}

			if (op == 3)
			{
				for (int i = n; i > 0; i--)
				{
					vet[i] = i;
					vetaux[i] = i;
				}

				cout << "Ordenando vetor..." << endl << endl;

				cout << "    ###### Ordenacao Decrescente ######      " << endl << endl;;

				ini = clock();
				ordenar->SelectionSortDecres(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Selection Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->BubbleSortDecres(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Bubble Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->InserctionSortDecres(vetaux, n);
				fin = (clock() - ini) / 1000;
				cout << "Inserction Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->MergeSortDecres(vetaux, 0, n - 1);
				fin = (clock() - ini) / 1000;
				cout << "Merge Sort - Tempo de execucao: " << fin << " ms " << endl;

				InicializarVetor(vet, vetaux, n);
				ini = clock();
				ordenar->QuickSortDecres(vetaux, 0, n - 1);
				fin = (clock() - ini) / 1000;
				cout << "Quick Sort - Tempo de execucao: " << fin << " ms " << endl;

				system("pause");
				system("cls");
			}

			if (op == 4)
			{
				do
				{
					cout << "Escolha o algoritmo a ser validado\n";
					cout << "1 - Selection Sort - Crescente\n2 - Selection Sort - Decrescente\n";
					cout << "3 - Bubble Sort - Crescente\n4 - Bubble Sort - Decrescente\n";
					cout << "5 - Inserction Sort - Crescente\n6 - Inserction Sort - Decrescente\n";
					cout << "7 - Merge Sort - Crescente\n8 - Merge Sort - Decrescente\n";
					cout << "9 - Quick Sort - Crescente\n10 - Quick Sort - Decrescente\n11 - Sair do Menu de Validacao\n=>";
					cin >> op3;

					system("cls");

					if (op3 == 1)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->SelectionSortCresc(vetaux, n);
						ordenar->print(vetaux,n);	
						cout << endl;
						system("pause");
						system("cls");
						
					}

					if (op3 == 2)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->SelectionSortDecres(vetaux, n);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 3)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->BubbleSortCresc(vetaux, n);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}
					if (op3 == 4)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->BubbleSortDecres(vetaux, n);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 5)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->InserctionSortCresc(vetaux, n);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 6)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->InserctionSortDecres(vetaux, n);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 7)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->MergeSortCresc(vetaux, 0, n - 1);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 8)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->MergeSortDecres(vetaux, 0, n-1);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 9)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->QuickSortCresc(vetaux, 0, n - 1);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

					if (op3 == 10)
					{
						InicializarVetor(vet, vetaux, n);
						ordenar->QuickSortDecres(vetaux, 0, n -1);
						ordenar->print(vetaux, n);
						cout << endl;
						system("pause");
						system("cls");
					}

				} while (op3 != 11);
			}

		} while (op != 5);

	} while (op2 != 2);
	
	system("pause");

	return 0;
}

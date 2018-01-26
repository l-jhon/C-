#pragma once
#include<iostream>
#include <vector>

using namespace std;


class Sort
{
public:

	void SelectionSortCresc(int *, int);
	void SelectionSortDecres(int *, int);
	void BubbleSortCresc(int *, int);
	void BubbleSortDecres(int *, int);
	void InserctionSortCresc(int *, int);
	void InserctionSortDecres(int *, int);
	void MergeSortCresc(int *, int ,int);
	void MergeSortDecres(int *, int, int);
	void QuickSortCresc(int *, int, int);
	void QuickSortDecres(int *, int, int);
	void HeapSortCresc(int *, int);
	void HeapSortDecres(int *, int);
	void print(int *, int);

private:
	void MergeCresc(int *, int, int, int);
	void MergeDecres(int *, int, int, int);
	int FindPivoCresc(int*, int, int);
	int FindPivoDecres(int*, int, int);

};

//Complexiade = >
//  Melhor: O(N2)
//  Medio : Omega(N2)
//  Pior : Teta(N2)
// O algoritmo faz com na primeira itera��o o menor elemento do vetor esteja na primeira posi��o, e ap�s isso procura outro elemento que seja
// menor que os demais, por�m maior que o anterior

void Sort::SelectionSortCresc(int *vet, int n)
{
	int m; // menor posi��o que deve receber o menor elemento
	int aux;

	for (int i = 0; i < n - 1; i++) // percorrer o vetor
	{
		m = i; // menor posi��o = 0

		for (int j = i + 1; j < n; j++) // percorre o vetor p/ efetuar a compara��o dos elementos
		{
			if (vet[j] < vet[m]) // se for menor o "M - menor" recebe a posi��o do menor elemento
				m = j;
		}
		aux = vet[m]; // trocas
		vet[m] = vet[i];
		vet[i] = aux;
	}
}

void Sort::SelectionSortDecres(int *vet, int n)
{
	int m; // menor posi��o que deve receber o menor elemento
	int aux;

	for (int i = 0; i < n - 1; i++) // percorrer o vetor
	{
		m = i; // menor posi��o = 0

		for (int j = i + 1; j < n; j++) // percorre o vetor p/ efetuar a compara��o dos elementos
		{
			if (vet[j] > vet[m]) // se for maior o "M - maior" recebe a posi��o do maior elemento
				m = j;
		}
		aux = vet[m]; // trocas
		vet[m] = vet[i];
		vet[i] = aux;
	}
}

//Complexidade = >
// Melhor : O(N2)
// Medio : Omega(N2)
//  Pior : Teta(N2)
// faz uma troca entre os elementos, o primeiro com o segundo, caso o primeiro seja maior, e assim por diante
// Este algoritmo garante na primeira itera��o que o maior elemento est� no fim do vetor

void Sort::BubbleSortCresc(int *vet, int n)
{
	int aux;

	for (int i = 0; i < n - 1; i++) // percorre todo o vetor
	{
		for (int j = 0; j < n - 1; j++) // percorre o vetor da posi��o i + 1 at� o fim do vetor
		{
			if (vet[j] > vet[j + 1]) // se o vetor na posi��o j, for maior que o vetor na posi��o j+1, ent�o faz a troca
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}

	}
}

void Sort::BubbleSortDecres(int * vet, int n)
{
	int aux;

	for (int i = 0; i < n - 1; i++) // percorre todo o vetor 
	{
		for (int j = 0; j < n - 1; j++) // percorre o vetor da posi��o i + 1 at� o fim do vetor
		{
			if (vet[j] < vet[j + 1]) // se o vetor na posi��o j, for menor que o vetor na posi��o j+1, ent�o faz a troca
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}

	}
}

//Complexidade
//Melhor : O(n)
//Medio : O(n2)
//Pior : O(n2)

//ordena��o por inser��o
// a cada avan�o vai organizando os elementos

void Sort::InserctionSortCresc(int * vet, int n)
{
	int aux;

	for (int i = 1; i < n; i++) // percorre o vetor da esquerda para a direita, assim fazendo com que os elementos da esquerda
	{							// fiquem ordenados
		int j = i;
		
		while ((j != 0) && (vet[j] < vet[j-1])) // enquanto a posi��o atual for menor que a anterior vai fazer as trocas
		{										// at� que a posi��o atual seja maior q a anterior
			aux = vet[j];
			vet[j] = vet[j-1];
			vet[j-1] = aux;
			j--;
		}
	}
}

void Sort::InserctionSortDecres(int * vet, int n)
{
	int aux;

	for (int i = 1; i < n; i++)
	{
		int j = i;

		while ((j != 0) && (vet[j] > vet[j - 1]))
		{
			aux = vet[j];
			vet[j] = vet[j - 1];
			vet[j - 1] = aux;
			j--;
		}

	}
}

//Complexiade = >
//   Melhor: O(n logn)
//   Medio : Omega(n logn)
//  Pior : Teta(n log2n)

void Sort::MergeSortCresc(int *vet, int  inicio, int fim)
{
	int n = fim - inicio + 1;
	int meio = (inicio + fim) / 2;

	if (n > 1)
	{
		MergeSortCresc(vet, inicio, meio); // divis�o do vetor, do inicio at� o meio dele
		MergeSortCresc(vet, meio + 1, fim); // divis�o do vetor, do meio+1 at� fim
		MergeCresc(vet, inicio, meio, fim); // intercala os subvetores gerados e ordena os mesmos
	}
}

void Sort::MergeCresc(int *vet, int inicio, int meio, int fim)
{
	int *temp = new int[fim];
	int i = inicio;
	int k = inicio;
	int j = meio + 1;

	while (i <= meio && j <= fim)
	{
		if (vet[i] < vet[j])
		{
			temp[k++] = vet[i++];
		}
		else
		{
			temp[k++] = vet[j++];
		}
	}

	while (i <= meio)
	{
		temp[k++] = vet[i++];
	}

	while (j <= fim)
	{
		temp[k++] = vet[j++];
	}

	for (i = inicio; i < k; i++)
	{
		vet[i] = temp[i];
	}
}

void Sort::MergeSortDecres(int *vet, int  inicio, int fim)
{
	int n = fim - inicio + 1;
	int meio = (inicio + fim) / 2;

	if (n > 1)
	{
		MergeSortDecres(vet, inicio, meio); // divis�o do vetor, do inicio at� o meio dele
		MergeSortDecres(vet, meio + 1, fim); // divis�o do vetor, do meio+1 at� fim
		MergeDecres(vet, inicio, meio, fim); // intercala os subvetores gerados e ordenas os mesmos
	}
}

void Sort::MergeDecres(int *vet, int inicio, int meio, int fim)
{
	int *temp = new int[fim];
	int i = inicio;
	int k = inicio;
	int j = meio + 1;

	while (i <= meio && j <= fim)
	{
		if (vet[i] > vet[j])
		{
			temp[k++] = vet[i++];
		}
		else
		{
			temp[k++] = vet[j++];
		}
	}

	while (i <= meio)
	{
		temp[k++] = vet[i++];
	}

	while (j <= fim)
	{
		temp[k++] = vet[j++];
	}

	for (i = inicio; i < k; i++)
	{
		vet[i] = temp[i];
	}
}

// Complexiade = >
// Melhor: O(n logn)
// Medio : Omega(n logn)
// Pior : Teta(n2)
// o algoritmo consiste em fazer uma separa��o utilizando um pivo, onde todos os elementos menores que o pivo devem estar � esquerda dele
// e os elementos maiores devem estar � direita


void Sort::QuickSortCresc(int *vet, int inicio, int fim)
{
	// o algoritmo faz com que a cada itera��o seja gerado um subvetor, onde o mesmo j� est� ordenado

	int pivo; 

	if (inicio < fim)
	{
		pivo = FindPivoCresc(vet, inicio, fim); // busca do pivo do vetor
		QuickSortCresc(vet, inicio, pivo-1); // parte do inicio do vetor at� o pivo - 1, pivo -1 porque o pivo j� est� no lugar correto
		QuickSortCresc(vet, pivo + 1, fim); // parte da posi��o do pivo+1, pois do vetor pra tr�s j� est� ordenado, ent�o � necess�rio a posi��o ap�s o pivo para ordenar os demais elementos 
	}
}

int Sort::FindPivoCresc(int *vet, int inicio, int fim)
{
	int k = inicio; //fixo o meu pivo na posi��o inicial do vetor
	int j = inicio;
	int i = inicio + 1;
	int aux;

	for (int i = inicio + 1; i <= fim; i++)
	{
		if (vet[i] < vet[k]) // se o pivo for maior que a proxima posi��o fa�o a troca dos elementos
		{					// se for menor incrementa o j e troca o elemento da posi��o i com j
			j++;
			aux = vet[i];  // quando i for menor que o pivo, o j � incrementado e � feita a troca do elementos de vet[i] e vet[j]
			vet[i] = vet[j];  // quando chegar o no caso onde o vet[i] n�o � menor que vet[k], ent�o incrementa o i at� 
			vet[j] = aux;  // at� que finalize todo o vetor
		}
	}
	aux = vet[k];  // ao percorrer todo o vetor e sair do "for", � feita a troca do pivo vet[k] ( que no caso t� no inicio) por vet[j]
	vet[k] = vet[j];
	vet[j] = aux;

	return j;
	// ao fim da fun��o � retornado o pivo do vetor
}

void Sort::QuickSortDecres(int *vet, int inicio, int fim)
{
	// o algoritmo faz com que a cada itera��o seja gerado um subvetor, onde o mesmo j� est� ordenado
	int pivo;

	if (inicio < fim)
	{
		pivo = FindPivoDecres(vet, inicio, fim); // busca do pivo do vetor
		QuickSortDecres(vet, inicio, pivo-1); // na primeira itera��o recebe o inicio e o pivo, mas como o pivo e o inicio s�o os mesmos, eles j� est�o ordenados
		QuickSortDecres(vet, pivo + 1, fim); // parte da posi��o do pivo+1, pois do vetor pra tr�s j� est� ordenado, ent�o � necess�rio a posi��o ap�s o pivo para ordenar os demais elementos 
	}
}

int Sort::FindPivoDecres(int *vet, int inicio, int fim)
{
	int k = inicio; //fixo o meu pivo na posi��o inicial do vetor
	int j = inicio;
	int i = inicio + 1;
	int aux;

	for (int i = inicio + 1; i <= fim; i++)
	{
		if (vet[i] > vet[k]) // se o pivo for maior que a proxima posi��o fa�o a troca dos elementos
		{					// se for maior incrementa o j e troca o elemento da posi��o i com j
			j++;
			aux = vet[i];  // quando i for maior que o pivo, o j � incrementado e � feita a troca do elementos de vet[i] e vet[j]
			vet[i] = vet[j];  // quando chegar o no caso onde o vet[i] n�o � maior que vet[k], ent�o incrementa o i at� 
			vet[j] = aux;  // at� que finalize todo o vetor
		}
	}
	aux = vet[k];  // ao percorrer todo o vetor e sair do "for", � feita a troca do pivo vet[k] ( que no caso t� no inicio) por vet[j]
	vet[k] = vet[j];
	vet[j] = aux;

	return j;
	// ao fim da fun��o � retornado o pivo do vetor
}

void Sort::print(int * vet, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << vet[i] << "]" << " ";
	}
}

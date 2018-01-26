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
// O algoritmo faz com na primeira iteração o menor elemento do vetor esteja na primeira posição, e após isso procura outro elemento que seja
// menor que os demais, porém maior que o anterior

void Sort::SelectionSortCresc(int *vet, int n)
{
	int m; // menor posição que deve receber o menor elemento
	int aux;

	for (int i = 0; i < n - 1; i++) // percorrer o vetor
	{
		m = i; // menor posição = 0

		for (int j = i + 1; j < n; j++) // percorre o vetor p/ efetuar a comparação dos elementos
		{
			if (vet[j] < vet[m]) // se for menor o "M - menor" recebe a posição do menor elemento
				m = j;
		}
		aux = vet[m]; // trocas
		vet[m] = vet[i];
		vet[i] = aux;
	}
}

void Sort::SelectionSortDecres(int *vet, int n)
{
	int m; // menor posição que deve receber o menor elemento
	int aux;

	for (int i = 0; i < n - 1; i++) // percorrer o vetor
	{
		m = i; // menor posição = 0

		for (int j = i + 1; j < n; j++) // percorre o vetor p/ efetuar a comparação dos elementos
		{
			if (vet[j] > vet[m]) // se for maior o "M - maior" recebe a posição do maior elemento
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
// Este algoritmo garante na primeira iteração que o maior elemento está no fim do vetor

void Sort::BubbleSortCresc(int *vet, int n)
{
	int aux;

	for (int i = 0; i < n - 1; i++) // percorre todo o vetor
	{
		for (int j = 0; j < n - 1; j++) // percorre o vetor da posição i + 1 até o fim do vetor
		{
			if (vet[j] > vet[j + 1]) // se o vetor na posição j, for maior que o vetor na posição j+1, então faz a troca
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
		for (int j = 0; j < n - 1; j++) // percorre o vetor da posição i + 1 até o fim do vetor
		{
			if (vet[j] < vet[j + 1]) // se o vetor na posição j, for menor que o vetor na posição j+1, então faz a troca
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

//ordenação por inserção
// a cada avanço vai organizando os elementos

void Sort::InserctionSortCresc(int * vet, int n)
{
	int aux;

	for (int i = 1; i < n; i++) // percorre o vetor da esquerda para a direita, assim fazendo com que os elementos da esquerda
	{							// fiquem ordenados
		int j = i;
		
		while ((j != 0) && (vet[j] < vet[j-1])) // enquanto a posição atual for menor que a anterior vai fazer as trocas
		{										// até que a posição atual seja maior q a anterior
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
		MergeSortCresc(vet, inicio, meio); // divisão do vetor, do inicio até o meio dele
		MergeSortCresc(vet, meio + 1, fim); // divisão do vetor, do meio+1 até fim
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
		MergeSortDecres(vet, inicio, meio); // divisão do vetor, do inicio até o meio dele
		MergeSortDecres(vet, meio + 1, fim); // divisão do vetor, do meio+1 até fim
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
// o algoritmo consiste em fazer uma separação utilizando um pivo, onde todos os elementos menores que o pivo devem estar à esquerda dele
// e os elementos maiores devem estar à direita


void Sort::QuickSortCresc(int *vet, int inicio, int fim)
{
	// o algoritmo faz com que a cada iteração seja gerado um subvetor, onde o mesmo já está ordenado

	int pivo; 

	if (inicio < fim)
	{
		pivo = FindPivoCresc(vet, inicio, fim); // busca do pivo do vetor
		QuickSortCresc(vet, inicio, pivo-1); // parte do inicio do vetor até o pivo - 1, pivo -1 porque o pivo já está no lugar correto
		QuickSortCresc(vet, pivo + 1, fim); // parte da posição do pivo+1, pois do vetor pra trás já está ordenado, então é necessário a posição após o pivo para ordenar os demais elementos 
	}
}

int Sort::FindPivoCresc(int *vet, int inicio, int fim)
{
	int k = inicio; //fixo o meu pivo na posição inicial do vetor
	int j = inicio;
	int i = inicio + 1;
	int aux;

	for (int i = inicio + 1; i <= fim; i++)
	{
		if (vet[i] < vet[k]) // se o pivo for maior que a proxima posição faço a troca dos elementos
		{					// se for menor incrementa o j e troca o elemento da posição i com j
			j++;
			aux = vet[i];  // quando i for menor que o pivo, o j é incrementado e é feita a troca do elementos de vet[i] e vet[j]
			vet[i] = vet[j];  // quando chegar o no caso onde o vet[i] não é menor que vet[k], então incrementa o i até 
			vet[j] = aux;  // até que finalize todo o vetor
		}
	}
	aux = vet[k];  // ao percorrer todo o vetor e sair do "for", é feita a troca do pivo vet[k] ( que no caso tá no inicio) por vet[j]
	vet[k] = vet[j];
	vet[j] = aux;

	return j;
	// ao fim da função é retornado o pivo do vetor
}

void Sort::QuickSortDecres(int *vet, int inicio, int fim)
{
	// o algoritmo faz com que a cada iteração seja gerado um subvetor, onde o mesmo já está ordenado
	int pivo;

	if (inicio < fim)
	{
		pivo = FindPivoDecres(vet, inicio, fim); // busca do pivo do vetor
		QuickSortDecres(vet, inicio, pivo-1); // na primeira iteração recebe o inicio e o pivo, mas como o pivo e o inicio são os mesmos, eles já estão ordenados
		QuickSortDecres(vet, pivo + 1, fim); // parte da posição do pivo+1, pois do vetor pra trás já está ordenado, então é necessário a posição após o pivo para ordenar os demais elementos 
	}
}

int Sort::FindPivoDecres(int *vet, int inicio, int fim)
{
	int k = inicio; //fixo o meu pivo na posição inicial do vetor
	int j = inicio;
	int i = inicio + 1;
	int aux;

	for (int i = inicio + 1; i <= fim; i++)
	{
		if (vet[i] > vet[k]) // se o pivo for maior que a proxima posição faço a troca dos elementos
		{					// se for maior incrementa o j e troca o elemento da posição i com j
			j++;
			aux = vet[i];  // quando i for maior que o pivo, o j é incrementado e é feita a troca do elementos de vet[i] e vet[j]
			vet[i] = vet[j];  // quando chegar o no caso onde o vet[i] não é maior que vet[k], então incrementa o i até 
			vet[j] = aux;  // até que finalize todo o vetor
		}
	}
	aux = vet[k];  // ao percorrer todo o vetor e sair do "for", é feita a troca do pivo vet[k] ( que no caso tá no inicio) por vet[j]
	vet[k] = vet[j];
	vet[j] = aux;

	return j;
	// ao fim da função é retornado o pivo do vetor
}

void Sort::print(int * vet, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << vet[i] << "]" << " ";
	}
}

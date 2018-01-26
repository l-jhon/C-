#include <iostream>
#include <fstream>
#include <string>
#include "Smbolo.h"
#include "Huffman.h"

using namespace std;

int main()
{
	string palavra;
	int peso = 0;
	Simbolo *simbolo = new Simbolo();
	Huffman *huffman = new Huffman();

	ifstream entrada("entrada.txt");
	getline(entrada,palavra);

	char *vet = new char[palavra.size()];
	char *vetaux = new char[palavra.size()];

	for (int i = 0; i < palavra.size(); i++)
	{
		vet[i] = palavra[i];
		vetaux[i] = palavra[i];

		for (int k = 0; k < i; k++)
		{
			if (vet[i] == vet[k])
			{
				vet[i] = NULL;
			}
		}
	}

	for (int j = 0; j < palavra.size(); j++)
	{
		for (int v = 0; v < palavra.size(); v++)
		{
			if (vet[j] == vetaux[v])
			{
				peso++;
			}
		}
		if (peso > 0)
		{
			simbolo->setChar(vet[j]);
			simbolo->setPeso(peso);
			huffman->adicionarLista(simbolo);
		}
		peso = 0;
	}

	huffman->AlgoHuffman(huffman->lista);

	huffman->gerarSaida("entrada.txt", "saida.txt", palavra, &huffman->getLista());

	system("pause");

	return 0;
}
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <list>
#include "vetorobjeto.h"
using namespace std;
class hash{
public:
	int tamanho = 100;
	hash();
	vetorObjeto vetor[100];
	int Hash(string palavra, int i);
	bool verificaPosicao(int posicao, string palavra);
	void put(int posicao, vetorObjeto &objeto, doc &document);
	vetorObjeto get(int posicao);
	bool validate(string str);
};

#endif // HASH_H

#include "hash.h"
#include "vetorobjeto.h"
#include "termodoc.h"
#include <iostream>
#include <termodoc.h>
#include <string>
#include <cctype>
#include <math.h>

using namespace std;

hash::hash(){
	for (int i = 0; i<tamanho; i++)
		vetor[i].setKey("NULL");
}

//hash::~hash(){
//}

void hash::put(int posicao, vetorObjeto &objeto, doc &document){
	bool verifica = false;
	termoDoc ter;
	ter.setTermo(objeto.getKey());
	ter.setPtDoc(&document);
	if (vetor[posicao].getKey() == "NULL"){
		vetor[posicao] = objeto;
		std::list<termoDoc> *a = new std::list<termoDoc>;
		a->push_back(ter);
		objeto.setPtList(a);
	}
	else{
		std::list<termoDoc> *pt = vetor[posicao].getPtList();
		for (std::list<termoDoc>::iterator i = pt->begin(); i != pt->end(); i++) {
			termoDoc *aux = new termoDoc;
			*aux = *i;
			if (aux->getPtDoc()->getNomeArquivo() == ter.getPtDoc()->getNomeArquivo()){
				aux->setQuantidade(aux->getQuantidade() + 1);
				verifica = true;
				break;
			}

		}
		if (!verifica){
			std::list<termoDoc> *a = new std::list<termoDoc>;
			a->push_back(ter);
			//            objeto.setPtList(a);
		}
	}
}

vetorObjeto hash::get(int posicao){
	return vetor[posicao];
}

bool hash::validate(string str){
	if (str.length()<3){
		return false;
	}


	return true;
}

bool hash::verificaPosicao(int posicao, string palavra){
	string valor = vetor[posicao].getKey();
	if (vetor[posicao].getKey() == palavra || valor.compare("NULL") == 0){
		return true;
	}
	else{
		return false;
	}
}

int hash::Hash(string palavra, int i){
	int valorPalavra = 0;
	int x = 0;
	for (int j = 0; j < palavra.size(); j++){

		palavra[j] = tolower(palavra[j]);
	}
	cout << palavra << endl;

	for (int z = 0; z<palavra.length(); z++){//isso aqui agente vai saber quanto vale a palavra em int

		valorPalavra = valorPalavra + (int)palavra[z];
	}
	valorPalavra = valorPalavra % 127;

	x = ((valorPalavra % 503) + (i*((valorPalavra*valorPalavra) % 503))) % tamanho;
	cout << "Valor da palavra : " << valorPalavra << endl;
	cout << "Valor da posicao : " << x << endl;
	if (verificaPosicao(x, palavra)){
		return x;
	}
	else{
		cout << "Valor i : " << i << "\n\n";
		return Hash(palavra, i + 1);
	}
}

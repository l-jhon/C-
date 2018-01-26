#include "listavetor.h"

#include <iostream>
#include "listaVetor.h"
using namespace std;

listavetor::listavetor(){//CONSTRUTOR
	first = last = NULL;
	tamanhoLista = 0;
	tamanhoMax = 0;
}

listavetor::~listavetor(){//DESTRUTOR
	limparLista();
	delete first;
	delete last;
}

bool listavetor::listaVazia(){//VERIFICA SE A LISTA ESTA VAZIA
	if (first == NULL)
		return true;
	else
		return false;
}

void listavetor::addItemInicio(int item){//ADICIONA ITEM NO INICIO
	tamanhoLista++;
	first = new intNode(item, first);
	if (last == NULL)
		last = first;
}

void listavetor::imprimiLista(){//IMPRIMIR A LISTA
	intNode *aux;
	aux = first;
	cout << "\n\nLista: ";
	while (aux != NULL){
		cout << aux->dado << " ";
		aux = aux->next;
	}
	cout << "\n\n";
}

bool listavetor::testeItem(int item){//TESTAR O ELEMENTO DE ENTRADA
	if (item != 0)
		return true;
	else
		return false;

}

void listavetor::limparLista(){//LIMPAR LISTA
	intNode *aux;
	aux = first->next;
	if (first == last){
		delete first;
		delete last;
		first = last = NULL;
	}
	else{
		do{
			delete first;
			first = aux;
		} while (aux->next == NULL);
		first = last = NULL;
	}

}

int listavetor::getTamanho(){//PEGAR O TAMANHO DA LISTA
	cout << tamanhoLista;
}

bool listavetor::posicaoValida(int posicao){//VERIFICA SE A POSICAO E VALIDA
	if (posicao <= tamanhoLista && posicao != 0)
		return true;
	else
		return false;
}

bool listavetor::retornaItem(int item){//VERIFICA SE O ITEM ESTA NA LISTA TRUE E FALSE
	intNode *aux;
	aux = first;
	for (int i = 1; i <= tamanhoLista; i++){
		if (item == aux->dado){
			return true;
		}
		aux = aux->next;
	}
	return false;
}

void listavetor::verificaItem(int item){//VERIFICA EM QUANTAS POSICOES ESTA O ITEM
	intNode *aux;
	aux = first;
	cout << "\n\nPosicao(oes) que se encontra o item : ";
	for (int i = 1; i <= tamanhoLista; i++){
		if (item == aux->dado){
			cout << i << " ";
		}
		aux = aux->next;
	}
	cout << endl << endl;
}

void listavetor::getItem(int posicao){//RETONAR QUAL O ITEM NA POSICAO PASSADA POR PAREMETRO
	intNode *aux;
	aux = first;
	for (int i = 1; i<posicao; i++){
		aux = aux->next;
	}
	cout << "\n\nNa posicao" << posicao << "esta o item : " << aux->dado << "\n\n";
	aux = NULL;
}

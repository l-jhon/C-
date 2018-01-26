#ifndef PILHA_H
#define PILHA_H

#include<iostream>

using namespace std;

class Node
{
public:
	int x;
	Node *prox;
};

class Pilha
{
private:
	Node *topo;

public:
	Pilha(int);            // inicializa topo com NULL
	void push(int);    // empilhar
	int pop();          // desempilhar
	int get_top();      // obter elemento do topo da pilha
	bool is_emptyi();    // verifica se a pilha esta vazia
	void cleari();       // limpar pilha
	int sizei();         // tamanho da pilha;
	void inverter();    // inverte ordem dos elementos  da pilha
	void print(Node*);       // imprimir elementos da piilha na tela
	void inicial(int);
	void auxiliar();
	void desfazer();
	void refazer();
};

#endif // PILHA_H

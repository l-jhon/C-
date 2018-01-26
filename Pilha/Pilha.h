#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	int x;
	Node *prox;
	Node(int x) :x(x){};
};


class Pilha
{
private:
	Node *topo;

public:
	Pilha();            // inicializa topo com NULL
	void push(int);    // empilhar
	int pop();          // desempilhar
	int get_top();      // obter elemento do topo da pilha
	bool is_empty();    // verifica se a pilha esta vazia
	void clear();       // limpar pilha
	int size();         // tamanho da pilha;
	void inverter();    // inverte ordem dos elementos  da pilha
	void print();       // imprimir elementos da piilha na tela
};


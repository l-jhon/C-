#ifndef PILHADR_H
#define PILHADR_H

#include<iostream>

using namespace std;

class Node
{
public:
	int x;
	int y;
	Node *prox;
};

class pilhaDR
{
private:
	Node *topo;

public:
	pilhaDR();            // inicializa topo com NULL
	void push(int, int);    // empilhaDRr
	int pop();          // desempilhaDRr
	int get_top();      // obter elemento do topo da pilhaDR
	bool is_emptyi();    // verifica se a pilhaDR esta vazia
	void cleari();       // limpar pilhaDR
	int sizei();         // tamanho da pilhaDR;
};

#endif // pilhaDR_H

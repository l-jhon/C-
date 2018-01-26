#pragma once

#include<iostream>
#include<cstdlib>

using namespace std;

class Node
{
public:
	char x;
	Node *prox;
};


class Pilha
{
private:
	Node *topo;

public:
	Pilha();            // inicializa topo com NULL
	void push(char);    // empilhar
	char pop();          // desempilhar
	char get_top();      // obter elemento do topo da pilha
	string posfixa(string);

};

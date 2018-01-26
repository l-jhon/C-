#pragma once

#include <iostream>

using namespace std;

class Node1
{
public:
	float x;
	Node1 *prox;
};


class Pilha1
{
private:
	Node1 *topo;
	float resultado;

public:
	Pilha1(string);            // inicializa topo com NULL
	void push(float);    // empilhar
	float pop();          // desempilhar
	float get_top();      // obter elemento do topo da pilha
	void calculoEq(string);
	float getResultado();

};
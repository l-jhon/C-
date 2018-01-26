#pragma once
#include <iostream>
#include <string>
#include "vertice.h"

using namespace std;

class Aresta
{
private:
	int peso;
	int dest;

public:
	Aresta();

	void setPeso(int);
	void setDest(int);

	int getPeso();
	int getDestino();

};

Aresta::Aresta()
{
	peso = NULL;
	dest = NULL;
}

void Aresta::setPeso(int peso)
{
	this->peso = peso;
}

int Aresta::getPeso()
{
	return peso;
}

void Aresta::setDest(int destino)
{
	this->dest = destino;
}

int Aresta::getDestino()
{
	return dest;
}
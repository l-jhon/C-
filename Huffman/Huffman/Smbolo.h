#pragma once
#include <string>

using namespace std;

class Simbolo
{
public:
	char nome;
	int peso;
	Simbolo* esq;
	Simbolo* dir;
	bool visitado;
	string ident;

	Simbolo();
	void setChar(char);
	void setPeso(int);
	void setVisitado(bool);
	void setIdent(string);
	char getChar();
	int getPeso();
	bool getVisitado();
	string getIdent();

};

Simbolo::Simbolo()
{
	nome = ' ';
	peso = 0;
	esq = NULL;
	dir = NULL;
	visitado = false;
	ident = ' ';
}

void Simbolo::setChar(char nome)
{
	this->nome = nome;
}

char Simbolo::getChar()
{
	return nome;
}

void Simbolo::setPeso(int peso)
{
	this->peso = peso;
}

int Simbolo::getPeso()
{
	return peso;
}

void Simbolo::setVisitado(bool visit)
{
	this->visitado = visit;
}

bool Simbolo::getVisitado()
{
	return visitado;
}

void Simbolo::setIdent(string ident)
{
	this->ident = ident;
}

string Simbolo::getIdent()
{
	return ident;
}
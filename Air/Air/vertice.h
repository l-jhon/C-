#pragma once
#include <iostream>
#include "aresta.h"
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Vertice
{
public:
	Vertice();
	int idVertice;
	string voo;
	string cidade;
	int horario;
	string formatoHora;
	string tipoVertice;
	vector<Aresta> listAresta;

	void setId(int);
	void setVoo(string);
	void setHorario(string);
	void setFormatHora(string);
	void setTipo(string);
	void setCidade(string);
	void AdicionarAresta(Aresta);

	int getID();
	int getHorario();
	string getVoo();
	string getFormatHora();
	string getTipo();
	string getCidade();
	int converter(string);
	vector<Aresta> getAresta();
};

Vertice::Vertice()
{
	this->idVertice = NULL;
	this->horario = NULL;
	this->voo = "";
	this->cidade = "";
	this->formatoHora = "";
	this->tipoVertice = "";
}

void Vertice::setId(int id)
{
	this->idVertice = id;
}

int Vertice::getID()
{
	return idVertice;
}

void Vertice::setVoo(string voo)
{
	this->voo = voo;
}

string Vertice::getVoo()
{
	return voo;
}

void Vertice::setHorario(string horario)
{

	this->horario = converter(horario);
}

int Vertice::getHorario()
{
	return horario;
}

void Vertice::setFormatHora(string formatoHora)
{
	this->formatoHora = formatoHora;
}

string Vertice::getFormatHora()
{
	return formatoHora;
}

void Vertice::setTipo(string tipoVertice)
{
	this->tipoVertice = tipoVertice;
}

string Vertice::getTipo()
{
	return tipoVertice;
}

void Vertice::setCidade(string cidade)
{
	this->cidade = cidade;
}

string Vertice::getCidade()
{
	return cidade;
}

void Vertice::AdicionarAresta(Aresta a)
{
	listAresta.push_back(a);
}

int Vertice::converter(string horaHH)
{
	int HH;
	int MM;
	int minutos = 0;

	HH = atoi((horaHH.substr(0, 2)).c_str());
	MM = atoi((horaHH.substr(3, 5)).c_str());

	minutos = (HH * 60) + MM;

	return minutos;
}

vector<Aresta> Vertice::getAresta()
{
	return listAresta;
}

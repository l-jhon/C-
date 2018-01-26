#pragma once

#include<iostream>
#include<string>

using namespace std;

#define Template template <typename K, typename D>
#define tipo Node<K, D>
#define tipoAVL ArvoreAVL<K, D>

Template
class Node	
{
public:
	K key;
	D dado;
	int balance = 0;
	tipo *dir;
	tipo *esq;
	Node(K key, D dado) :key(key), dado(dado), esq(NULL), dir(NULL){}
};

class Pessoa
{
public:
	long long cpf;
	long long rg;
	string nome;
	string data;
	string cidade;

	Pessoa() :cpf(0),rg(0), nome(""), data(""), cidade(""){}
	void set_dados(long long,long long,string, string, string );
	
};


Template
class ArvoreAVL
{

private:
	tipo * raiz;
	bool verificar;

	tipo* inserir_rec(tipo*, K, D);
	tipo* remover_rec(tipo*, K, D);
	tipo* rotRR(tipo*);
	tipo* rotLL(tipo*);
	tipo* rotRL(tipo*);
	tipo* rotLR(tipo*);
	tipo* buscar_rec(tipo*, K, D);
	tipo* buscarCPF_rec(tipo*, K);
	string buscarNome_rec(tipo*, string);
	string buscarData_rec(tipo*, string, string);
	void print_rec(tipo*, int);

public:
	ArvoreAVL();

	void inserir(K, D);
	void remover(K, D);
	void print();
	K buscar();
	D buscarCPF(K);
	string buscarNome(string);
	string buscarData(string, string);
};

void Pessoa::set_dados(long long cpf, long long rg, string nome, string data, string cidade)
{
	this-> cpf = cpf;
	this -> nome = nome;
	this -> rg = rg;
	this->data = data;
	this -> cidade = cidade;
}

Template
tipoAVL::ArvoreAVL()
{
	raiz = NULL;
	verificar = true;
}

Template
void tipoAVL::inserir(K key, D dado)
{
	raiz = inserir_rec(raiz, key, dado);
}

Template
tipo* tipoAVL::inserir_rec(tipo *pto, K key, D dado)
{
	if (pto)
	{
		if (key < pto->key)
		{
			pto->esq = inserir_rec(pto->esq, key, dado);

			if (verificar)
			{
				switch (pto->balance)
				{
				case 1:
					pto->balance = 0;
					verificar = false;
					break;
				case 0:
					pto->balance = -1;
					break;
				case -1:
					if (pto->esq->balance == -1)
					{
						pto = rotLL(pto);
						pto->balance = 0;
						pto->dir->balance = 0;
					}
					else
					{
						pto = rotLR(pto);

						switch (pto->balance)
						{
						case 1:
							pto->esq->balance = -1;
							pto->dir->balance = 0;
							break;
						case -1:
							pto->esq->balance = 0;
							pto->dir->balance = 1;
							break;
						case 0:
							pto->esq->balance = 0;
							pto->dir->balance = 0;
							break;
						}
						pto->balance = 0;
					}
					verificar = false;
				}
			}
		}
		else
		{
			pto->dir = inserir_rec(pto->dir, key, dado);

			if (verificar)
			{
				switch (pto->balance)
				{
				case -1:
					pto->balance = 0;

					verificar = false;
					break;
				case 0:
					pto->balance = 1;
					break;
				case 1:
					switch (pto->dir->balance)
					{
					case 1:
						pto = rotRR(pto);
						pto->balance = 0;
						pto->esq->balance = 0;
						break;
					case -1:
						pto = rotRL(pto);
						switch (pto->balance)
						{
						case -1:
							pto->esq->balance = 0;
							pto->dir->balance = 1;
							break;
						case 1:
							pto->esq->balance = -1;
							pto->dir->balance = 0;
							break;
						case 0:
							pto->esq->balance = 0;
							pto->dir->balance = 0;
							break;
						}
						pto->balance = 0;
					}
					verificar = false;
					break;
				}
			}

		}
	}
	else
	{
		pto = new tipo (key, dado);
		verificar = true;
	}
	return pto;
}

Template
tipo* tipoAVL::rotRR(tipo *pto)
{
	tipo *aux1 = pto;
	tipo *aux2 = pto->dir;
	aux1->dir = aux2->esq;
	aux2->esq = aux1;
	return aux2;

	/*tipo* aux = pto->dir;
	pto->dir = aux->esq;
	aux->dir = pto;
	return aux;*/
}

Template 
tipo* tipoAVL::rotLL(tipo *pto)
{
	tipo *aux1 = pto;
	tipo *aux2 = pto->esq;	
	aux1->esq = aux2->dir;
	aux2->dir = aux1;
	return aux2;

	/*tipo* aux = pto->esq;
	pto->esq = aux->dir;
	aux->esq = pto;
	return aux;*/
}

Template
tipo* tipoAVL::rotRL(tipo * pto)
{
	pto->dir = rotLL(pto->dir);
	return rotRR(pto);
}

Template
tipo* tipoAVL::rotLR(tipo * pto)
{
	pto->esq = rotRR(pto->esq);
	return rotLL(pto);
}

Template
void tipoAVL::print()
{
	return print_rec(raiz, 0);
}

Template
void tipoAVL::print_rec(tipo *pto, int i)
{
	if (pto){
		i++;
		print_rec(pto->dir, i);
		for (int j = 0; j < i; j++)
			cout << "        ";
		cout << pto->dado.cpf << "<" << pto->balance << ">" << endl;
		print_rec(pto->esq, i);
		i--;
	}
}

Template 
D tipoAVL::buscarCPF(K cpf)
{
	return buscarCPF_rec(raiz, cpf)->dado;
}

Template
tipo* tipoAVL::buscarCPF_rec(tipo* pto, K cpf)
{
	if (pto)
	{
		if (cpf == pto->key)
		{
			return pto;
		}
		else
		{
			if (pto->key > cpf)
			{
				return buscarCPF_rec(pto->esq, cpf);
			}
			else
				return buscarCPF_rec(pto->dir, cpf);
		}
	}
	else
	{
		return NULL;
	}

}
Template
string tipoAVL::buscarNome(string nome)
{
	return buscarNome_rec(raiz, nome);
}

Template
string tipoAVL::buscarNome_rec(tipo* pto, string nome)
{
	string nomes = "";
	string c;
	string r;

	if (pto)
	{
		if (pto->key.compare(0, nome.size(), nome) == 0)
		{
			nomes += "\nCPF: " + to_string(pto->dado.cpf) +"\n" + "RG: " + to_string(pto->dado.rg) + "\n" + "NOME: " + pto->dado.nome + "\n" + "DATA DE NASCIMENTO: " + reverter(pto->dado.data) + "\n" + "CIDADE: " + pto->dado.cidade + "\n\n";
			nomes += buscarNome_rec(pto->esq, nome);
			nomes += buscarNome_rec(pto->dir, nome);
		}
		else
		{
			if (pto->key > nome)
			{
				nomes += buscarNome_rec(pto->esq, nome);
			}
			else
				nomes += buscarNome_rec(pto->dir, nome);
		}
		
	}
	return nomes; 
}

Template
string tipoAVL::buscarData(string dini, string dfim)
{
	return buscarData_rec(raiz, dini, dfim);
}

Template
string tipoAVL::buscarData_rec(tipo *pto, string ini, string fim)
{
	string names = "";

	if (pto)
	{
		string data = pto->key;

		if (data >= ini && data <= fim)
		{
			names += "\nCPF: " + to_string(pto->dado.cpf) + "\n" + "RG: " + to_string(pto->dado.rg) + "\n" + "NOME: " + pto->dado.nome + "\n" + "DATA DE NASCIMENTO: " + reverter(pto->dado.data) + "\n" + "CIDADE: " + pto->dado.cidade + "\n\n";
			names += buscarData_rec(pto->esq, ini, fim);
			names += buscarData_rec(pto->dir, ini, fim);
		}

		else
		{
			if (data < ini)
			{
				names += buscarData_rec(pto->dir, ini, fim);
			}
			else
			{
				if (data > fim)
				{
					names += buscarData_rec(pto->esq, ini, fim);
				}
			}
		}
	}
	return names;
}

string inverter(string a)
{
	string b = "";
	b += a.substr(6, 9) + '/' + a.substr(3, 2) + '/' + a.substr(0, 2);

	return b;
}

string reverter(string x)
{
	string y = "";
	y += x.substr(8, 9) + '/' + x.substr(5,2) + '/' + x.substr(0, 4);

	return y;
}

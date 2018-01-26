#ifndef DOC_H
#define DOC_H
#include <iostream>

using namespace std;

class doc{

private:
	string nomeArquivo;
	int quantidadeDistintas;
public:
	doc();
	doc(string a, int b){ nomeArquivo = a; quantidadeDistintas = b; }
	void setNomeArquivo(string arquivo){ nomeArquivo = arquivo; }
	string getNomeArquivo(){ return nomeArquivo; }
	void setQuantidade(int a){ quantidadeDistintas = a; }
	int getQuantidade(){ return quantidadeDistintas; }

};

#endif // DOC_H


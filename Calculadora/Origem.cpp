#include <iostream>
#include "pilha.h"
#include "pilha1.h"
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	char x;
	string expressao;
		
	Pilha *posf = new Pilha();

	system("cls");

	cout << "Digite uma expressao:";
	getline(cin,expressao);

	Pilha1 objPilha1(posf->posfixa(expressao));

	cout << endl << "Resultado = " << objPilha1.getResultado() << endl;

	delete posf;

	system("PAUSE");

	return main();
}

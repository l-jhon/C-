#include <iostream>
#include "ArvoreAVL.h"

using namespace std;

int main()
{
	ArvoreAVL<int> A;
	A.inserir(70);
	A.inserir(60);
	A.inserir(50);
	A.inserir(40);
	A.inserir(30);
	A.inserir(20);
	A.inserir(10);

	A.print();

system("PAUSE");

}
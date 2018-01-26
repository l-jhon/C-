#include <iostream>
#include "arvore.h"

using namespace std;

int main()
{
	Arvore A;
	A.add(20);
	A.add(10);
	A.add(30);
	A.print();
	A.remove(20);

system("PAUSE");

}
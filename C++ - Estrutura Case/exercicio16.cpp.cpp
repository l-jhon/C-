//Jhon Lucas Santos Silva/
/*Mostrando a classe eleitoral de um indiviudo*/
#include <iostream>
using namespace std;
int main ()
{
int i/*idade*/,op/*opcao*/;
cout<<"Digite a idade\n";
cin>>i;
cout<<"1-Menos de 16 anos\n2-Entre 18 e 65 \n3-Maior de 65\n";
cin>>op;
switch (op)
{
case 1:
cout<<"N??o-eleitor\n";
break;
case 2:
cout<<"Eleitor Obrigatorio\n";
break;
case 3:
cout<<"Eleitor Facultativo\n";
break;
}
system("pause");
}

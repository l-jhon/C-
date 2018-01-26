//Jhon Lucas Santos Silva
/*Convertendo Reais em Euro,Libra Esterlina, Dolar e Iene de acordo com a escolha do usuario*/
#include <iostream>
#include <cmath>
#define e 2.617
#define l 3.816
#define d 2.071
#define i 1.018
using namespace std;
int main ()
{
float r/*reais*/,re/*resultado*/;
int op/*opcao*/;
cout<<"Digite o valor em Reais\n";
cin>>r;
cout<<"Digite a Opcao Desejada\n1-Euro.\n2-Libra Esterlina.\n3-D??lar\n4-Iene\n";
cin>>op;
switch (op)
{
case 1:
re=r*e;
cout<<"??? "<<re<<endl;
break;
case 2:
re=r*l;
cout<<"?? "<<re<<endl;
break ;
case 3:
re=r*d;
cout<<"$ "<<re<<endl;
break;
case 4:
re=r*i;
cout<<"?? "<<re<<endl;
}
system("pause");
}

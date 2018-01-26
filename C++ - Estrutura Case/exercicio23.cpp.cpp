//Jhon Lucas Santos Silva
/*Informando o m s em que o emplacamento deve renovado*/
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
int p/*placa*/,u/*ultimo digito*/;
cout<<"Digite o numero da placa\n";
cin>>p;
u=p%10;
switch (u)
{
case 1:
cout<<"Renovar emplacamento em Setembro"<<endl;
break;
case 2:
cout<<"Renovar emplacamento em Setembro"<<endl;
break;
case 3:
cout<<"Renovar emplacamento em Outubro"<<endl;
break;
case 4:
cout<<"Renovar emplacamento em Outubro"<<endl;
break;
case 5:
cout<<"Renovar emplacamento em Outubro"<<endl;
break;
case 6:
cout<<"Renovar emplacamento em Novembro"<<endl;
break;
case 7:
cout<<"Renovar emplacamento em Novembro"<<endl;
break;
case 8:
cout<<"Renovar emplacamento em Novembro"<<endl;
break;
case 9:
cout<<"Renovar emplacamento em Dezembro"<<endl;
break;
case 0:
cout<<"Renovar emplacamento em Dezembro"<<endl;
break;
}
system ("pause");
}

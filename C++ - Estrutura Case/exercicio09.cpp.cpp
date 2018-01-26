//Jhon Lucas Santos Silva//
/*Dada um tipo de consumidor, calcular sua conta que deve ser paga a SANEAGO*/
#include <iostream>
#include <cmath>
#define r 5
#define c 500
#define i 800
using namespace std;
int main ( )
{
   int opcao,conta;
float co/*consumo*/,g/*gasto*/,aux;
   cout<<"Digite a conta do cliente\n";
   cin>>conta;
cout<<"Qual o tipo de consumidor\n1-Residencial.\n2-Comercial.\n3-Industrial.\n";
   cin>>opcao;
cout<<"\nDigite o consumo em m3: ";
   cin>>co;
   switch (opcao)
{
case 1:
   g=r+(0.05*co);
break;
case 2:

   if (co<=80)
   {
       g=c;
   }
   else
   {
       aux=co-80;
       g=c+(aux*0.25);
   }
break;
case 3:
       if (co<=100)
       {
           g=i;
       }
       else
       {
           aux=co-100;
           g=i+(aux*0.04);
       }
break;
}
   cout<<"Conta Numero:\n"<<con;
   cout<<"\nValor a ser pago de :\nR$:"<<g;
   system ("pause");
}

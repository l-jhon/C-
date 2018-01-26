// Jhon Lucas Santos Silva
/*Calculando o valor a ser pago por um produto , escolhendo diferentes formas de pagamento*/
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
float vp/*valor a ser pago*/,p/*preco de etiqueta*/,aux;
int op/*opcao*/;
cout<<"Digite o Valor de Etiqueta:\n";
cin>>p;
cout<<"Digite a Opcaoo desejada:\n1-A vista em Dinheiro ou Cheque:\n2-A vista com Cartao de Credito:\n3-Em 2x :\n4-Em 3x;\n";
cin>>op;
switch (op)
{
case 1:

aux=p*0.10;
vp=p-aux;
break;
case 2:

aux=p*0.05;
vp=p-aux;
break;
case 3:
vp=p/2;
break;
case 4:
aux=p*0.10;
vp=p+aux/3;
break;

}
cout<<"Valor a Ser Pago de : "<<vp<<endl;


system("pause");
}

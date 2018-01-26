//Jhon Lucas Santos Silva
/*Fazer um programa que calcule o valor a ser pago por um produto considerando o preço normal de etiqueta e a escolha da condição de pagamento     */
#include<iostream>
using namespace std;
int main ()
{
    float vp,/*valor do produto*/
	      pf;/*preco a ser pago*/
	cout<<"Digite o valor do produto:";
	cin>>vp;
	cout<<"Condicao de pagamento: 1-A vista dinheiro ou cheque , 2-A vista cartao de credito , 3-Em duas vezes , 4-Em tres vezes:";
	if ( 1 )
	{
	 pf= vp - (vp * 10/100);
	}
	if ( 2 )
	{
	 pf= vp - (vp * 5/100);
	}
	if ( 3 )
	{
	 pf= vp;
	}
	if ( 4 )
	{
	 pf= vp + (vp * 10/100);
	}
	cout<<"O preco a ser pago eh:"<<pf<<endl;
return 0;
}

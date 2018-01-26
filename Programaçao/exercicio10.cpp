//Jhon Lucas Santos Silva
/*Fazer um programa para ler o preco normal da fita alugada e sua categoria, e calcular e escrever o preco final a ser pago*/
#include<iostream>
using namespace std;
int main ()
{
    float precn,/*preco normal da fita alugada */
	      precf;/*preco final a ser pago*/
	cout<<"Menu de opcoes:1- Se o dia for segunda, terca e quinta , 2- Se o dia for quarta, sexta, sabado e domingo:";
	cout<<"Menu de opcoes:3- Se a categoria for comum, 4- Se a categoria for lancamento:";
	cout<<"digite o preco normal da fita alugada:";
	cin>>precn;
	if ( 1 && 3 )
	{
	 precf= precn * 40/100;
	}
	if ( 1 && 4 )
	{
	 precf= (precn * 40/100) + (precn * 15/100);
    }	 
	if ( 2 && 3 )
	{
	 precf= precn;
	}
	if ( 2 && 4 )
	{
	 precf= precn * 15/100;
	}
	cout<<"O preco final eh:"<<precf;
return 0;
}

//Jhon Lucas Santos Silva
/*Fazer um programa que converta uma determinada quantia dada em reais para uma das seguintes moedas de acordo com a opção do usuário      */
#include<iostream>
using namespace std;
int main ()
{
    int q;/*quantidade em reais*/
	float e,/*euro*/
	      l,/*libra esterlina*/
		  d,     /*dolar     */
		  i;     /*iene     */
	cout<<"Digite a quantidade em reais:";
	cin>>q;
	cout<<"Moedas: 1- Euro , 2- Libra esterlina , 3- Dolar , 4- Iene:";
	if ( 1 )
	{
	 e= q * 2.617;
	 cout<<"euro:"<<e<<endl;
	}
	if ( 2 )
	{
	 l= q * 3,816;
	 cout<<"libra esterlina:"<<l<<endl;
	}
	if ( 3 )
	{
	 d= q * 2.071;
	 cout<<"dolar:"<<d<<endl;
	}
	if ( 4 )
	{
	 i= q * 1.018;
	 cout<<"iene:"<<i<<endl;
	}
return 0;
}

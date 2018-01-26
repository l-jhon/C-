//Jhon Lucas Santos Silva
/*Fazer um programa que calcule o peso ideal de uma pessoa       */
#include<iostream>
using namespace std;
int main ()
{
    float h,/*altura */
	      p;/*peso ideal*/
	cout<<"Sexo: 1-Masculino , 2-Feminino:";
	cout<<"Digite a altura:";
	cin>>h;
	if ( 1 )
	{
	 p= 72.7 * h - 58;
	}
	if ( 2 )
	{
	 p= 62.1 * h - 44.7;
	}
	cout<<"O peso ideal eh:"<<p;
return 0;
}

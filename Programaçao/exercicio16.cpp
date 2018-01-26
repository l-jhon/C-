//Jhon Lucas Santos Silva
/*Fazer um programa que leia a idade de uma pessoa e que mostre a sua classe eleitoral       */
#include<iostream>
using namespace std;
int main ()
{
    int i;/*idade da pessoa*/
	cout<<"Digite a idade da pessoa:";
	cin>>i;
	if (i < 16)
	{
	 cout<<"Nao-leitor:"<<endl;
	}
	if (i >= 18 && i <= 65)
	{
	 cout<<"Eleitor obrigatorio:"<<endl;
	}
	if ((i >= 16 && i <=18) && i > 65)
	{
	 cout<<"eleitor facultativo:"<<endl;
	}
return 0;
}

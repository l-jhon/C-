//Jhon Lucas Santos Silva
//Fazer um programa que leia o mês e o ano de uma data e que exiba o número de dias da mesma/
#include<iostream>
using namespace std;
int main ()
{
    int d,/*dia*/
	    m,/*mes*/
		a;/*ano*/
	cout<<"Digite o dia:";
	cin>>d;
	cout<<"Digite o mes:";
	cin>>m;
	cout<<"Digite o ano:";
	cin>>a;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
	 cout<<"O mes tem 31 dias"<<endl;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
	 cout<<"O mes tem 30 dias"<<endl;
	}
	if (m == 2 && (a % 4 == 0 && a % 100 != 0 && a % 400 == 0))
	{
	 cout<<"O mes tem 29 dias"<<endl;
	}
	if (m == 2 && (a % 4 != 0 && a % 100 == 0 && a % 400 !=0))
	{
	 cout<<"O mes tem 28 dias"<<endl;
	}
	if (a % 4 == 0 && a % 100 != 0 && a % 400 == 0)
	{
	 cout<<"O ano tem 366 dias";
	}
	if (a % 4 != 0 && a % 100 == 0 && a % 400 !=0)
	{
	 cout<<"O ano tem 365 dias";
	}
return 0;
}

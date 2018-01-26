//Jhon Lucas Santos Silva
/*Fazer um programa que leia uma data no formato inteiro e escreva a mesma data no formato dia de (mês por extenso) de ano      */
#include<iostream>
using namespace std;
int main ()
{
    int d,/*dia*/
		a,/*ano*/
        m;/*mes */
	cout<<"Digite o dia:";
	cin>>d;
	cout<<"Digite o mes:";
	cin>>m;
	cout<<"Digite o ano:";
	cin>>a;
	if ( m == 1 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"janeiro:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 2 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"fevereiro:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 3 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<" marco:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 4 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"abril:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 5 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"maio:"<<endl;
	   cout<<"ano:"<<a<<endl;                                                                                      
	}
	if ( m == 6 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"junho:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 7 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"julho:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 8 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"agosto:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 9 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"setembro:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 10 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"outubro:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
	if ( m == 11 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"novembro:"<<endl;
	   cout<<"ano:"<<endl<<a;
	}
	if ( m == 12 )
	{
	   cout<<"dia:"<<d<<endl;
	   cout<<"dezembro:"<<endl;
	   cout<<"ano:"<<a<<endl;
	}
return 0;
}
		
	

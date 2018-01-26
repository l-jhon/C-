//Jhon Lucas Santos Silva
/* programa que leia um numero inteiro e mostre se ele eh divisivel por 5 e por 3 ao mesmo tempo   */
#include<iostream>
using namespace std;
int main ()
{
    int n;    /*numero inteiro     */
	cout<<"digite um numero inteiro:";
	cin>>n;
	if ( n / 5 && n / 3 )
	{
	 cout<<"O numero e divisivel"<<endl;
	}
	if (!( n / 5 && n / 3 ))
	{
	 cout<<"O numero nao e divisivel"<<endl;
	}
system ("pause");
}

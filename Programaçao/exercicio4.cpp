//Jhon Lucas Santos Silva
/*Fazer um programa que leia 3 numeros inteiros e mostre o maior deles        */
#include<iostream>
using namespace std;
int main ()
{
	int n1,/*numero 1*/
	      n2,/*numero 2*/
	      n3;/*numero 3 */
	char maior;/*maior valor*/
	cout<<"Digite o numero 1:";
	cin>>n1;
	cout<<"Digite o numero 2:";
	cin>>n2;
	cout<<"Digite o numero 3:";
	cin>>n3;
	if ((n1>n2) && (n1>n3))
	{
		maior=n1;
	}
	else
	{
		if( n2>n3 )
		{
			maior=n2;
		}
		else
		{
			maior=n3;
		}
	}
	cout<<"O maior valor eh:"<<maior<<endl;
return 0;
}

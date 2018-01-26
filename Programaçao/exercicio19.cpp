//Jhon Lucas Santos Silva 
/*Fazer um programa que leia o nome do fazendeiro, o tipo de pulverizacao e area a ser pulverizada, e calcule o custo final da pulverizacao e escrever o nome do fazendeiro e o valor a ser pago      */
#include<iostream>
using namespace std;
int main ()
{
    char n;     /*nome do fazendeiro     */
	int a;     /*area a ser pulverizada    */
	float c,   /*custo final da pulverizacao    */
	      vp;   /*valor a ser pago     */
	cout<<"Digite o nome do fazendeiro:";
	cin>>n;
	cout<<"Digite a area a ser pulverizada:";
	cin>>a;
	cout<<"Tipo de pulverizacao: 1-Pulverização contra ervas daninhas , 2- Pulverização contra gafanhotos , 3- Pulverização contra broca , 4- Pulverização contra todas as anteriores:";
	if ( 1 )
	{
	 c= 5.0 * a;
	}
	if ( 2 )
	{
	 c= 10.0 * a;
	}
	if ( 3 )
	{
	 c= 15.0 * a;
	}
	if ( 4 )
	{
	 c= 25.0 * a;
	}
	if ( a > 300 )
	{
     vp= c - (c * 5/100);
	}
	if (c > 1750.0)
	{
	 vp= c - (c * 10/100);
	}
	if ((a > 300) && (c > 1750.0))
	{
	 vp= c - (c * 5/100);
	}
	cout<<"O nome do fazendeiro eh:"<<n<<endl;
	cout<<"O custo da pulverizacao eh:"<<c<<endl;
	cout<<"O valor a ser pago eh:"<<vp<<endl;
return 0;
}

//Jhon Lucas Santos Silva
/*Fazer um programa com as opções de calcular e imprimir o volume e a área da superfície de um cone reto, de um cilindro ou de uma esfera      */
#include<cmath>
#include<iostream>
#define pi 3.1415
using namespace std;
int main ()
{
    float r,/*raio*/
	      h,/*altura*/
		  v,/*volume*/
		  a;/*area*/
    cout<<"Menu de opcoes: 1-Cone reto , 2-Cilindro , 3-Esfera:";
	cout<<"Digite o raio:";
	cin>>r;
	cout<<"Digite a altura:";
	cin>>h;
	if ( 1 )
	{
	 v= (pi * (r * r) * h)/3;
	 a= pi * r * sqrt((r * r) + (h * h));
	 cout<<"O volume do cone reto eh:";
	 cin>>v;
	 cout<<"A area do cone reto eh:";
	 cin>>a;
	}
	if ( 2 )
	{
	 v= pi * (r * r) * h;
	 a= 2 * pi * r * h;
	 cout<<"O volume do cilindro eh:";
	 cin>>v;
	 cout<<"A area do cilindro eh:";
	 cin>>a;
	}
	if ( 3 )
	{
	 v= (4/3) * pi * (r * r * r);
	 a= 4 * pi * (r * r);
	 cout<<"O volume da esfera eh:";
	 cin>>v;
	 cout<<"A area da esfera eh:";
	 cin>>a;
	}
return 0;
}

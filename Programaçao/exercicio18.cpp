//Jhon Lucas Santos Silva
/*Fazer um programa para calcular e imprimir o preço final de um carro     */
#include<iostream>
using namespace std;
int main ()
{
    float pi,/*preco inicial do carro     */
	      pf;     /*preco final do carro       */
	cout<<"digite o preco inicial do carro:";
	cin>>pi;
	cout<<"Escolha os adicionais: 1- Ar condicionado , 2- Pintura metalica , 3- Vidro eletrico , 4- Direcao hidraulica , 5- Nenhum adicional:";
	if ( 1 || 2 || 3 || 4 )
	{
	 if ( 1 )
	 {
	  pf= pi + 1750.0;
	 }
	 if ( 2 )
	 {
	  pf= pi + 800.0;
	 }
	 if ( 3 )
	 {
	  pf= pi + 1200.0;
	 }
	 if ( 4 )
	 {
	  pf= pi + 2000.0;
	 }
	 if ( 1 && 2 )
	 {
	  pf= pi + 1750.0 + 800.0;
	 }
	 if ( 1 && 3 )
	 {
	  pf= pi + 1750.0 + 1200.0;
	 }
	 if ( 1 && 4 )
	 {
	  pf= pi + 1750.0 + 2000.0;
	 }
	 if ( 1 && 2 && 3)
	 {
	  pf= pi + 1750.0 + 800.0 + 1200.0;
	 }
	 if ( 1 && 2 && 4 )
	 {
	  pf= pi + 1750.0 + 800.0 + 2000.0;
	 }
	 if ( 1 && 3 && 4 )
	 {
	  pf= pi + 1750.0 + 1200.0 + 2000.0;
	 }
	 if ( 2 && 3 )
	 {
	  pf= pi + 800.0 + 1200.0;
	 }
	 if ( 2 && 4 )
	 {
	  pf= pi + 800.0 + 2000.0;
	 }
	 if ( 2 && 3 && 4 )
	 {
	  pf= pi + 800.0 + 1200.0 + 2000.0;
	 }
	 if ( 3 && 4 )
	 {
	  pf= pi + 1200.0 + 2000.0;
	 }
	}
	if ( 5 )
	{
	 pf= pi;
	}
	cout<<"O preco final eh:"<<endl;
	cin>>pf;
return 0;
}

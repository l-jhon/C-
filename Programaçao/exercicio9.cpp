//Jhon Lucas Santos Silva 
/*Fazer um programa para calcular a conta de água para a SANEAGO */
#include<iostream>
using namespace std;
int main ()
{
    float c,/*consumo de agua de metros cubicos*/
	      ca,/*consumo de agua acima de 80 metros cubicos*/
		  cb,/*consumo de agua acima de 100 metros cubicos*/
		  vp;/*valor a ser pago*/
	cout<<"Menu de opcoes:1- Consumidor residencial,2- Consumidor comercial,3- Consumidor industrial,Digite em qual opcao se encaixa:";
	if ( 1 )
	{
	 cout<<"Digite o consumo de agua de metros cubicos:";
	 cin>>c;
	 vp= 5.0 + 0.05 * c;
	 cout<<"O valor a ser pago eh:"<<vp<<endl;
	}
	if ( 2 )
	{
	 cout<<"Digite o consumo de agua de metros cubicos:";
	 cin>>c;
	 cout<<"Digite o consumo de agua acima de 80 metros cubicos:";
	 cin>>ca;
	 vp= 500.0 + 0.25 * ca;
	 cout<<"O valor a ser pago eh:"<<vp<<endl;
	}
	if ( 3 )
	{
	 cout<<"Digite o consumo de agua de metros cubicos:";
	 cin>>c;
	 cout<<"Digite o consumo de agua acima de 100 metros cubicos:";
	 cin>>cb;
	 vp= 800.0 + 0.04 * cb;
	 cout<<"o valor a ser pago eh:"<<vp<<endl;
	}
return 0;
}
	

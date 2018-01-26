//Jhon Lucas Santos Silva 
/*Fazer um programa que dado um número inteiro positivo, calcule e escreva se este é ou não quadrado perfeito    */
#include<cmath>
#include<iostream>
using namespace std;
int main ()
{
    int n,/*numero inteiro positivo */
	    int_quad_n;/*quadrado do numero inteiro      */
    float quad_n,/*quadrado do numero      */
	      dif;/*diferenca    */
	cout<<"Digite o numero inteiro positivo:";
	cin>>n;
	quad_n= sqrt(n);
	int_quad_n=quad_n;
	dif=quad_n - int_quad_n;
	if (dif == 0)
	{
	 cout<<"O numero eh quadrado perfeito"<<endl;
	}
	if (dif != 0)
	{
	 cout<<"O numero nao e um quadrado perfeito"<<endl;
    }
return 0;
}	
	
	

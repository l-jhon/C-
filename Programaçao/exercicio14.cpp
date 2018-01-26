//Jhon Lucas Santos Silva
/*Fazer um programa que deve escrever o número do aluno, suas notas, a média dos exercícios, a média de aproveitamento, o conceito correspondente e a mensagem: aprovado se o conceito for A, B ou C e reprovado, se o conceito for D ou E           */
#include<iostream>
using namespace std;
int main ()
{
    int n;/*numero de identificacao*/
	float n1,/*nota 1*/
	      n2,/*nota 2*/
		  n3,/*nota 3*/
		  m,/*media dos exercicios*/
		  ma;/*media de aproveitamento*/
    cout<<"Digite o numero de identificacao:";
	cin>>n;
	cout<<"Digite a nota 1:";
	cin>>n1;
	cout<<"Digite a nota 2:";
	cin>>n2;
	cout<<"Digite a nota 3:";
	cin>>n3;
	cout<<"Digite a media dos exercicios:";
	cin>>m;
	ma= (n1 + n2 * 2 + n3 * 3 + m)/7;
	if (ma >= 9.1 && ma <= 10.0)
	{
	 cout<<"Conceito A, aprovado:"<<endl;
	}
	if (ma >= 7.6 && ma <= 9.0)
	{
	 cout<<"Conceito B, aprovado:"<<endl;
	}
	if (ma >= 6.1 && ma <= 7.5)
	{
	 cout<<"Conceito C, aprovado:"<<endl;
	}
	if (ma >= 4.1 && ma <= 6.0)
	{
	 cout<<"Conceito D, reprovado:"<<endl;
	}
	if (ma < 4.0)
	{
	 cout<<"Conceito E, reprovado:"<<endl;
	}
	cout<<"O numero de identificacao eh:"<<n<<endl;
	cout<<"O nota 1 eh:"<<n1<<endl;
	cout<<"A nota 2 eh:"<<n2<<endl;
	cout<<"A nota 3 eh:"<<n3<<endl;
	cout<<"A media dos exercicios eh:"<<m<<endl;
	cout<<"A media de aproveitamento eh:"<<ma<<endl;
return 0;
}

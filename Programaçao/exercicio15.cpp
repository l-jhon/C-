//Jhon Lucas Santos Silva
/*Fazer um programa que calcule o salário bruto e o salário líquido de um funcionário      */
#include<iostream>
using namespace std;
int main ()
{
    char n;/*nome do funcionario*/
	int h;/*horas extras trabalhadas*/
	float sh,/*salario hora extra*/
	      sb,/*salario bruto*/
		  sl;     /*salario liquido     */
    cout<<"Digite o nome do funcionario:";
	cin>>n;
	cout<<"Digite as horas extras trabalhadas:";
	cin>>h;
	sh= h * 10.0;
	sb= 3 * 350.0 + sh;
	if (sb > 1500.0 && sb < 2000.0)
	{
	 sl= sb - (sb * 12/100);
    }
	if (sb > 2000.0)
	{
	 sl= sb - (sb * 20/100);
	}
	cout<<"O nome do funcionario eh:"<<n<<endl;
	cout<<"O salario bruto eh:"<<sb<<endl;
	cout<<"O salario liquido eh:"<<sl<<endl;
return 0;
}

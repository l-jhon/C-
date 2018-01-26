// Jhon Lucas Santos Silva 
// Criar um programa para calcular a quantidade de gotas  do medicamento que o paciente deve tomar por dose.
#include <iostream>
using namespace std;
int main()
{
	int idade;
	float peso,gotas;
	cout<<"Digite o peso:";
	cin>>peso;
	cout<<"Digite a idade:";
	cin>>idade;
	if((idade>12)&&(peso>=60))
	{
		gotas=1000/25;
	}
	if((idade>=12)&&(peso<60))
	{
		gotas=875/25;
	}
	if((idade<=12)&&(peso>=5&&peso<=9))
	{
		gotas=125/25;
	}
	if((idade<=12)&&(peso>=9&&peso<=16))
	{
		gotas=250/25;
	}
	if((idade<=12)&&(peso>=16&&peso<=4))
	{
		gotas=375/25;
	}
	if((idade<=12)&&(peso>=24&&peso<=30))
	{
		gotas=500/25;
	}
	if((idade<=12)&&(peso>30))
	{
		gotas=750/25;
	}
	cout<<"Quantidade de gotas por dose que um paciente pode tomar:"<<gotas<<endl;
	
return 0;
}
	
	
	

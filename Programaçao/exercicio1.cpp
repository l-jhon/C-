//Jhon Lucas Santos Silva
/* calcular a media aritmetica de um aluno e mostrar uma mensagem de aprovado ou reprovado*/
#include<iostream>
using namespace std;
int main ()
{
    float not1,    /*primeira nota     */
	      not2,     /*segunda nota     */
		  not3,     /*terceira nota     */
		  ma;     /*media aritmetica    */
    cout<<"Digite a primeira nota:";
	cin>>not1;
	cout<<"Digite a segunda nota:";
	cin>>not2;
	cout<<"Digite a terceira nota:";
	cin>>not3;
	ma= (not1 + not2 + not3)/3.0;
	cout<<"A media e:"<<ma;
	if (ma < 6.0)
	{
	 cout<<"Reprovado"<<endl;
	}
	if (ma >= 6.0)
	{
	 cout<<"Aprovado"<<endl;
	}
return 0;
}

//Jhon Lucas Santos Silva
/*Descubrir se um ano lido é bissexto     */
#include<iostream>
using namespace std;
int main ()
{
    int a;     /*ano     */
	cout<<"Digite o ano:";
	cin>>a;
	if (a > 0)
	{
	 if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
	 {
	  cout<<"O ano eh bissexto:"<<endl;
	 }
	 if (!(a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
	 {
	  cout<<"O ano nao eh bissexto:"<<endl;
	 }
	}
	if (!(a > 0))
	{
	 cout<<"Ano invalido:"<<endl;
	}
return 0;
}

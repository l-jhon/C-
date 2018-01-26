//Jhon Lucas Santos Silva
/*Calculando o valor a ser pago por um certo tipo de pulverizaçao de lavouras*/
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
float des1/*desconto1*/,des2/*desconto2*/,p/*preco de puverizacao*/,pf/*preco final*/;
char nf[30]/*nome do fazendeiro*/;
int ar/*area em acre*/,tp/*tipo de pulveriza????o*/;
cout<<"Digite o nome do fazendeiro\n";
cin>>nf;
cout<<"Digite a area a ser pulverizada em acre\n";
cin>>ar;
cout<<"Escolha o tipo de pulveriza????o:\n1-Contra Ervas Daninhas.\n2-Contra Gafanhotos.\n3-Contra Broca.\n4-Contra Tudo Acima.\n";
cin>>tp;
switch (tp)
{
case 1:
p=ar*5;
break;
case 2:
p=ar*10;
break;
case 3:
p=ar*15;
break;
case 4:
p=ar*25;
break;
}
if (ar>300)
{
des1=p*0.05;
}
if (ar<=300)
{
des1=0;
}
if (p>1750)
{
des2=(p-1750)*0.10;
}
if (p<=1750)
{
des2=0;
}
pf=p-(des1+des2);
cout<<"Fazendeiro: "<<nf<<"\nValor a Ser Pago: "<<pf<<endl;

system ("pause");
}

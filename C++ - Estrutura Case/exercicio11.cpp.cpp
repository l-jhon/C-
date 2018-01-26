// Jhon Lucas Santos Silva
/*Calculando area e volume de um cone reto,de um cilindro ou de uma esfera*/
#include <iostream>
#include <cmath>
#define pi 3.1415
using namespace std;
int main ()
{
int r/*raio*/,h/*altura*/,op/*opcao*/,v/*volume*/,a/*area*/;
cout<<"Digite o Raio e a Altura\n";
   cin>>r;
   cin>>h;
cout<<"Digite a Opacao Desejada:\n1_Cone Reto:\n2_Cilindro:\n3_Esfera:\n";
   cin>>op;
switch (op)
{
case 1:
 
       v=pi*(r*r)*h/3;
       a=pi*r*sqrt((r*r)+(h*h));
          cout<<"Volume: "<<v<<"\nArea: "<<a<<endl;
break;
 case 2:

       v=pi*(r*r)*h;
       a=2*pi*r*h;
          cout<<"Volume: "<<v<<"\nArea: "<<a<<endl;
  break;
   case 3:
           v=(4/3)*pi*(r*r*r);
       a=4*pi*(r*r);
          cout<<"Volume: "<<v<<"\nArea: "<<a<<endl;
       break;
}

   system("pause");
}

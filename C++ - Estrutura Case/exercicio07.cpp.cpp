//Jhon Lucas Santos Silva
/* Dada a data transforma-la em dias*/
#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
int m/*mes*/,a/*ano*/;
cout<<"Digite o mes e o ano\n";
cin>>m;
cin>>a;
switch (m)
{
case 1:
cout<<"31 Dias";
break;
case 2:
if ((a%4==0&&a%100!=0)||(a%400==0))
{
cout<<"29 Dias\n";
}
else
{
cout<<"28 Dias\n";
}
break;
case 3:
cout<<"31 Dias";
break;
case 5:
cout<<"31 Dias";
break;
case 7:
cout<<"31 Dias";
break;
case 8:
cout<<"31 Dias";
break;
case 10:
cout<<"31 Dias";
break;
case 12:
cout<<"31 Dias";
break;
default:
cout<<"30 Dias";
break;
}
return 0;
}

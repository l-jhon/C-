// Jhon Lucas Santos Silva //
//Dizer se os lados dados formam um triângulo: retângulo, obtusângulo ou acutângulo//
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int ladoa, ladob, ladoc;
    double aux1, aux2, aux3;
    cout<<"Lado a:";
    cin>>ladoa;
    cout<<"Lado b:";
    cin>>ladob;
    cout<<"Lado c:";
    cin>>ladoc;
    aux1=pow((ladoa),2);
    aux2=pow((ladob),2);
    aux3=pow((ladoc),2);
    if(aux1==aux2+aux3)
    {
                       cout<<"O triangulo e Retangulo"<<endl;
                       }
    if(aux1>aux2+aux3)
    {
                     cout<<"O triangulo e Obtusangulo"<<endl;
                     }
    if(aux1<aux2+aux3)
    {
                      cout<<"O triangulo e Acutangulo"<<endl;
                      }
    return system("pause");
}
    

    

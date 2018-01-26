// Jhon Lucas Santos Silva //
// Fazer um algoritmo que dado um número de 4 dígitos calcule a soma do 2 primeiros digitos com os ultimos e sua potencia seja igual ao nº inicial
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int numero,aux1,aux2,soma;
    double potenciacao;
    cout<<"Digite o numero:";
    cin>>numero;
    aux1=numero/100;
    aux2=numero%100;
    soma=aux1+aux2;
    potenciacao=pow(soma,2);
    cout<<"Soma:"<<soma<<endl;
    cout<<"Potenciacao:"<<potenciacao<<endl;
    if((soma%2)!=0)
    {
                   cout<<"Possui as caratcteristicas do exercicio"<<endl;
                   }
                   if((soma%2)==0)
                   {
                                  cout<<"Nao possui as caracteristicas do exercicio"<<endl;
                                  }
    return system("pause");
}
                                  
                   
                   

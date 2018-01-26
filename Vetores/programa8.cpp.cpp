//ithallo franck
//programa para colocar numeros em ordem crescente
#include<iostream>
using namespace std;
int main( )
{
        int Vetor[10],aux,i,j;
        for(i=0;i<10;i++)
        {
                cout<<"Digite um numero do vetor: ";
                cin>>Vetor[i];
        }
        for(j=9; j>=1; j--)
        {
                for(i=0; i<j; i++)
                {
                if(Vetor[i]>Vetor[i+1])
                {
                        aux=Vetor[i];
                        Vetor[i]=Vetor[i+1];
                        Vetor[i+1]=aux;
                }
                }
        }
        cout<<"Vetor=| ";
     for(i=0;i<10;i++)
     {
                cout<<Vetor[i]<<"  ";
        }
        cout<<"|"<<endl;
        system("pause");
}

//Jhon Lucas Santos Silva
//Questao 02 programa para calcular um vetor inteiro
#include<iostream>
using namespace std;
int main()
{
        int vetor[10],Cont;
        for(Cont=0;Cont<10;Cont++)
        {
        cout<<"Digite o "<<Cont+1<<"?? numero inteiro:";
        cin>>vetor[Cont];
        }
        cout<<"Posiçoes:\t";
        for(Cont=0;Cont<10;Cont++)
        {
                if(vetor[Cont]%2!=0)
                {
                        cout<<Cont<<"\t";
                }
        }
        cout<<" "<<endl;
        system("pause");
}

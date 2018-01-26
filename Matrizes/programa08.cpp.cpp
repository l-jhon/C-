//Jhon Lucas Santos Silva
//Questao 08, programa para ler uma matriz M, e matriz modificada
#include<iostream>
#define L 10
#define C 10
using namespace std;
int main ( )
{
        long int M[L][C],ContL,ContC,Aux;
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<"Digite o valor da posiçao M=["<<ContL<<","<<ContC<<"]: ";
                        cin>>M[ContL][ContC];
                }
        }
        cout<<"Matriz Original:"<<endl;
        for(ContL=0;ContL<L;ContL++)
        {
                cout<<"| ";
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<M[ContL][ContC]<<" ";
                }
                cout<<" |"<<endl;
        }
        for(ContC=0;ContC<C;ContC++)
        {
                Aux=M[1][ContC];
                M[1][ContC]=M[7][ContC];
                M[7][ContC]=Aux;
        }
        for(ContL=0;ContL<L;ContL++)
        {
                Aux=M[ContL][3];
                M[ContL][3]=M[ContL][9];
                M[ContL][9]=Aux;
        }
        cout<<"Matriz Modificada:"<<endl;
        for(ContL=0;ContL<L;ContL++)
        {
                cout<<"| ";
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<M[ContL][ContC]<<" ";
                }
                cout<<" |"<<endl;
        }
        system("pause");
}

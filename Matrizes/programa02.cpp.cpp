//Jhon Lucas SAntos Silva
//Questao 02 , programa para calcular o fatorial e mostrar a matriz B
#include<iostream>
#define L 3
#define C 3
using namespace std;
int main ( )
{
        long long A[L][C],B[L][C],ContL,ContC,ContF,Fat;
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<"Digite um numero para a posiçao A=|"<<ContL<<","<<ContC<<"|:";
                        cin>>A[ContL][ContC];
                }
        }
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        Fat=A[ContL][ContC];
                        for(ContF=A[ContL][ContC]-1;ContF>=1;ContF--)
                        {
                                Fat=Fat*ContF;
                        }
                B[ContL][ContC]=Fat;
                }
        }
        cout<<"B:"<<endl;
        for(ContL=0;ContL<L;ContL++)
        {
                cout<<"|\t";
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<B[ContL][ContC]<<"\t";
                }
                cout<<"|"<<endl;
        }
        system("pause");
}

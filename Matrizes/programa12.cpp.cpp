//Jhon Lucas Santos Silva
//Questao 12 , programa para ler uma matriz 10x10
#include<iostream>
#define L 10
#define C 10
using namespace std;
int main ( )
{
        long int  M[L][C],N[L][C],ContL,ContC,ContDP;
        ContDP=0;
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<"Digite o valor da posiçao M=["<<ContL<<","<<ContC<<"]: ";
                        cin>>M[ContL][ContC];
                
        }
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        N[ContL][ContC]=M[ContL][ContC]*M[ContDP][ContDP];              
                }
                ContDP=ContDP+1;
        }
        cout<<"\nM:"<<endl;
        for(ContL=0;ContL<L;ContL++)
        {
                cout<<"|\t";
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<N[ContL][ContC]<<"\t";
                }
                cout<<"|"<<endl;
        }
        cout<<endl;
}
system("pause");
}

//Jhon Lucas SAntos Silva
//Questao 06 , programa para mostrar a soma de M 
#include<iostream>
#define L 5
#define C 5
using namespace std;
int main ( )
{
        long int M[L][C],ContL,ContC,SomaL,SomaC,SomaDP;
        SomaL=0;
        SomaC=0;
        SomaDP=0;
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<"Digite o valor para a posiçao M=|"<<ContL<<","<<ContC<<"|: ";
                        cin>>M[ContL][ContC];
                }
        }
        for(ContC=0;ContC<C;ContC++)
        {
                SomaL=SomaL+M[3][ContC];
        }
        for(ContL=0;ContL<L;ContL++)
        {
                SomaC=SomaC+M[ContL][1];
        }
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        if(ContL==ContC)
                        {
                                SomaDP=SomaDP+M[ContL][ContC];
                        }
        }
        cout<<"\nM:"<<endl;
        for(ContL=0;ContL<L;ContL++)
        {
                cout<<"|\t";
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<M[ContL][ContC]<<"\t";
                }
                cout<<"|"<<endl;
        }
        cout<<"\nA soma da linha 4 da matriz M: "<<SomaL<<"\n\nA soma da coluna 2 da matriz M: "<<SomaC<<"\n\nA soma da diagonal principal da matriz M: "<<SomaDP<<"\n"<<endl;
}
system("pause");
}


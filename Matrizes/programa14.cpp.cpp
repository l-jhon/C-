//Jhon Lucas Santos Silva
//Questao 14, programa para ordenar a matriz linha por linha
#include<iostream>
#define L 5
#define C 5
using namespace std;
int main( )
{
        float M[L][C],Aux[L][C];
        int ContL,ContC,Cont;
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<"Digite o numero da posiçao M=["<<ContL<<","<<ContC<<"]: ";
                        cin>>M[ContL][ContC];
                }
        }
        Cont=0;
        while(Cont<L)
        {
                for(ContL=9;ContL<=0;Cont--)
                {
                        for(ContC=0;ContC<C;ContC++)
                        {
                                if(M[ContL][ContC]>M[ContL][ContC+1])
                                {
                                        Aux[ContL][ContC]=M[ContL][ContC];
                                        M[ContL][ContC]=M[ContL][ContC+1];
                                        M[ContL][ContC+1]=Aux[ContL][ContC];
                                }
                        }
                }
                Cont++; 
        }
        cout<<"M="<<endl;
     for(ContL=0;ContL<L;ContL++)
     {
        cout<<"|\t";
        for(ContC=0;ContC<C;ContC++)
        {
                cout<<M[ContL][ContC]<<"\t";
                }
                cout<<"|"<<endl;
        }
        cout<<"]"<<endl;
        system("pause");
}

//Jhon Lucas Santos Silva
//Questao 10, programa para calcular a media dos elementos da matriz M
#include<iostream>
#define L 5
#define C 5
using namespace std;
int main ( )
{
        long int ContL,ContC,ContMedia;
        double M[L][C],Media;
        Media=0;
        ContMedia=0;
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        cout<<"Digite o numero da posiçao M=|"<<ContL<<","<<ContC<<"|:";
                        cin>>M[ContL][ContC];
                }
        }
        for(ContL=0;ContL<L;ContL++)
        {
                for(ContC=0;ContC<C;ContC++)
                {
                        if(ContL==ContC)
                        {
                                Media=Media+(M[ContL][ContC]);
                                ContMedia=ContMedia+1;
                        }
        }       
        Media=Media/ContMedia;
        cout<<"A media dos elementos da diagonal principal: "<<Media<<endl;
}
system("pause");
}

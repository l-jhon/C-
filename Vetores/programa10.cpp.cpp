//Jhon Lucas Santos Silva
//Questao 10
#include<iostream>
#include<string>
using namespace std;
int main()
{
        int N;
        cout<<"Digite a quantidade de pessoas: ";
        cin>>N;
        string Nome[N],Sexo[N];
        int Idade[N],Cont;
        for(Cont=0;Cont<N;Cont++)
        {
                cout<<"\nDigite o primeiro nome da pessoa: ";
                cin>>Nome[Cont];
                cout<<"Digite a idade da pessoa: ";
                cin>>Idade[Cont];
                cout<<"Digite o sexo da pessoa (M ou F): ";
                cin>>Sexo[Cont];
        }
        cout<<"\nNome, idade e sexo das pessoas cuja ?? maior que idade ?? maior que a da primeira pessoa."<<endl;
        for(Cont=1;Cont<N;Cont++)
        {
                if(Idade[0]<Idade[Cont])
                {
                        cout<<"\nNome= "<<Nome[Cont]<<"\nIdade= "<<Idade[Cont]<<"\nSexo= "<<Sexo[Cont]<<endl;
                }
        }
        cout<<"\nNome e idade de todas as mulheres.\n"<<endl;
        for(Cont=0;Cont<N;Cont++)
        {
                if(Sexo[Cont]=="F")
                {
                        cout<<"Nome= "<<Nome[Cont]<<"\nIdade= "<<Idade[Cont]<<endl;
                }
        }
        cout<<"\nNome dos homens menores de 21 anos.\n"<<endl;
        for(Cont=0;Cont<N;Cont++)
        {
                if(Sexo[Cont]=="M"&&Idade[Cont]<21)
                {
                        cout<<"Nome= "<<Nome[Cont]<<endl;
                }
        }
}
return 0;
}

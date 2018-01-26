//Jhon Lucas SAntos Silva
//Questao 04, programa para calcular o numero inteiro A e B
#include<iostream>
using namespace std;
int main()
{
  int A[5],B[5],C[5],i;
  for(i=0;i<5;i++)
  {
    cout<<"Digite o "<<i+1<<"numero inteiro do vetor A:";
    cin>>A[i];
    cout<<"Digite o "<<i+1<<"numero inteiro do vetor B:";
    cin>>B[i];
  }
  for(i=0;i<5;i++)
  {
    if(i%2==0)
    {
      C[i]=A[i]+B[i];
    }
    else
    {
      C[i]=A[i]*B[i];
    }
  }
  cout<<"A=\t";
  for(i=0;i<5;i++)
  {
    cout<<A[i]<<"\t";
  }
  cout<<" \nB=\t";
  for(i=0;i<5;i++)
  {
    cout<<B[i]<<"\t";
  }
  cout<<"\nC=\t";
  for(i=0;i<5;i++)
  {
    cout<<C[i]<<"\t";
  }
  cout<<"\n";
  system("pause");
}

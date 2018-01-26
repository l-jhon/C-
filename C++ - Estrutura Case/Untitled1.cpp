#include <iostream>
using namespace std;
int main()
{
    int codigo, prece;
    float preco;
    cout<<"Digite o preço do produto:";
    cin>>preco;
    cout<<"Digite o codigo de origem do produto:";
    cin>>codigo;
    if(codigo==1)
    {
      cout<<"Precedencia:Sul"<<endl;
       }
     else{
       if(codigo==2)
       {
       cout<<"Precedencia:Norte"<<endl;
       }
       else{
       if(codigo==3)
       {
       cout<<"Precedencia:Leste"<<endl;
       }
       else{
       if(codigo==4)
       {
       cout<<"Precedencia:Oeste"<<endl;
       }
       else{
       if(codigo==5 || codigo==6)
       {
       cout<<"Precedencia:Nordeste"<<endl;
       }
       else{
       if(codigo==7 || codigo==8 || codigo==9)
       {
       cout<<"Precedencia:Sudeste"<<endl;
       }
       else{
       if(codigo==10 || codigo==20)
       {
       cout<<"Precedencia:Centro-Oeste"<<endl;
       }
       else{
       if(codigo==21 || codigo==30)
       {
       cout<<"Precedencia:Noroeste"<<endl;
       }
       else
       {
       cout<<"Codigo invalido"<<endl;
       }
       }
       }
       }
       }
       }
       }
       }
       system("pause");
       }
                                                                                                 

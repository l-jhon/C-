// Jhon Lucas Santos Silva
/* programa para ler coeficientes de uma equacao do segundo grau e que calcule suas raizes */
#include<iostream>
using namespace std;
int main ()
{
    int a,      /*coeficiente 1     */
        b,       /*coeficiente 2     */
        c,       /*coeficiente 3     */
        d;       /*delta      */
    cout<<"Digite o coeficiente 1:";
    cin>>a;
    cout<<"Digite o coeficiente 2:";
    cin>>b;
    cout<<"Digite o coeficiente 3:";
    cin>>c;
    d= (b * b)- 4 * a * c;
    if ( d < 0 )
    {
        cout<<"Raizes imaginarias:"<<endl;
    }
    if ( d > 0 )
    {
        cout<<"Raizes distintas:"<<endl;
    }
    if ( d == 0 )
    {
        cout<<"Raiz unica:"<<endl;
    }
return 0;
}

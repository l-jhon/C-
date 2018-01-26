%{

#include <iostream>
#include <stdlib.h>

using namespace std;
int tk;

void DecRoma(const char *);
void ImprimirDecimal(const char *);

%}

/* def regulares */
digito      [0-9]
numero      {digito}+

%%

{numero}    {ImprimirDecimal(yytext); cout << " \nROMANO = "; DecRoma(yytext);}

%%

int main (int argc, char *argv[]) 
{
    yyin = fopen(argv[1], "r");

    while(tk = yylex());
    fclose(yyin);

    return 0;
}

void DecRoma(const char *var)
{
    char *romanos[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int decimais[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int indice = (sizeof(decimais) / sizeof(decimais[0])) - 1;

    int numero = atoi(var);


    while (numero > 0) 
    {
        if (numero >= decimais[indice]) 
        {
            cout << romanos[indice];
            numero -= decimais[indice];
        } 
        else 
        {
            indice--;
        }
    }
    cout << "\n";
}

void ImprimirDecimal(const char *num)
{
    cout << "DECIMAL = " << num;
}
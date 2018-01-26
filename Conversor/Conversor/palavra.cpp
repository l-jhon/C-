#include "palavra.h"

Palavra::Palavra()
{
    palavra = "";
    vetCPlus = new vector<string>();
    vetCSharp = new vector<string>();
    vetVariavel = new vector<string>();
    vetnum = new vector<char>(10);
    vetnum->at(0) = '0';
    vetnum->at(1) = '1';
    vetnum->at(2) = '2';
    vetnum->at(3) = '3';
    vetnum->at(4) = '4';
    vetnum->at(5) = '5';
    vetnum->at(6) = '6';
    vetnum->at(7) = '7';
    vetnum->at(8) = '8';
    vetnum->at(9) = '9';
}

void Palavra::setPalavra(string palavra)
{
    this->palavra = palavra;
}

string Palavra::getPalavra()
{
    return palavra;
}

bool Palavra::Numero(string variavel){
    bool resultado = false;

    for(int i = 0; i < vetnum->size(); i++ ){
        if (vetnum->at(i) == variavel[0]){
            resultado = true;
        }
    }

    return resultado;
}

bool Palavra::ValidarVariavel(string variavel){
    int i;
    bool resultado = false;

    if (vetVariavel->size()){
        for ( i = 0; i < vetVariavel->size(); i++){
            if (vetVariavel->at(i) == variavel)
                resultado = true;
        }
    }

    return resultado;
}

void Palavra::DeclararVariavel(string variavel){
    int i;
    if (vetVariavel->size()){
        for ( i = 0; ( i < vetVariavel->size());i++){
            if (vetVariavel->at(i) == variavel) {
                cout<<"Erro. Varivel " << variavel<<" ja declarada" << endl;
                break;
            }
        }

        if(i = vetVariavel->size()){
            vetVariavel->push_back(variavel);
        }
    }else {
        vetVariavel->push_back(variavel);
    }
}

void Palavra::Condicao(string linha_aux){
    int contador = 0;
    string variavel;

    while(linha_aux[contador] != '\0'){
        variavel = "";
        while (linha_aux[contador] != '<' && linha_aux[contador] != '>' && linha_aux[contador] != '|' && linha_aux[contador] != '&' && linha_aux[contador] != '!' && linha_aux[contador] != '=' && linha_aux[contador] != '\0' && linha_aux[contador] != '{') {
            if (linha_aux[contador] != ' ') {
                variavel = variavel + linha_aux[contador];
                linha_aux[contador] = ' ';
            }
            contador++;
        }
        if (linha_aux[contador] == '<' || linha_aux[contador] == '>' || linha_aux[contador] == '!' || linha_aux[contador] == '=' || linha_aux[contador] == '&' || linha_aux[contador] == '|' || linha_aux[contador] == '{'){
            if(linha_aux[contador + 1] == '=' || linha_aux[contador + 1] == '&' || linha_aux[contador + 1] == '|')
                linha_aux[contador + 1] = ' ';
            if (linha_aux[contador] != '{')
                linha_aux[contador] = ' ';

            if (!ValidarVariavel(variavel)){
                if (!Numero(variavel)){
                    cout<<"Erro. Varivel " << variavel<<"  nao declarada" << endl;
                    exit;
                }
            }
            if (linha_aux[contador] == '{')
                linha_aux[contador] = '\0';

        }else{
            if (!ValidarVariavel(variavel)){
                if (!Numero(variavel)){
                    cout<<"Erro. Varivel " << variavel<<"  nao declarada" << endl;
                    exit;
                }
            }
        }
    }
}

void Palavra::Expressao(string linha){
    int contador = 0;
    string variavel = "";
    string linha_aux;
    linha_aux = linha;
    variavel = "";

    while((linha_aux[contador] != '+' && linha_aux[contador] != '-' && linha_aux[contador] != '*' && linha_aux[contador] != '/') && ( linha_aux[contador] != '\0'))
        contador++;

    if (linha_aux[contador] == '+' || linha_aux[contador] == '-' || linha_aux[contador] == '*' || linha_aux[contador] == '/' ) {
        contador = 0;
        while (linha_aux[contador] != '=' && linha_aux[contador] != '\0') {
            if (linha_aux[contador] != ' ') {
                variavel = variavel + linha_aux[contador];
                linha_aux[contador] = ' ';
            }
            contador++;
        }
        if (linha_aux[contador] == '='){
            linha_aux[contador] = ' ';

            if (!ValidarVariavel(variavel)){
                if (!Numero(variavel)){
                    cout<<"Erro. Varivel " << variavel<<"  nao declarada" << endl;
                    exit;
                }
            }

        }
    }
    while (linha_aux[contador] != '\0'){
        variavel = "";
        while((linha_aux[contador] != '+' && linha_aux[contador] != '-' && linha_aux[contador] != '*' && linha_aux[contador] != '/') && (linha_aux[contador] != ';')&& ( linha_aux[contador] != '\0')) {
            if (linha_aux[contador] != ' ') {
                variavel = variavel + linha_aux[contador];
                linha_aux[contador] = ' ';
            }
            contador++;
        }
        if(linha_aux[contador] == '+' || linha_aux[contador] == '-' || linha_aux[contador] == '*' || linha_aux[contador] == '/' || linha_aux[contador] == ';'){
            linha_aux[contador] =  ' ';

            if (!ValidarVariavel(variavel)){
                if (!Numero(variavel)){
                    cout<<"Erro. Varivel " << variavel<<"  nao declarada" << endl;
                    exit;
                }
            }
        }
    }
}

void Palavra::Declaracao(string linha, string palavra){
    int x;
    int y = 0;
    int contador = 0;
    string variavel = "";
    string linha_aux = linha;
    x = linha_aux.find(palavra);
    y = palavra.length() + 1;
    variavel = "";

    if (x != -1) {
        linha_aux = linha_aux.replace(x, y, " ");

        while (linha_aux[contador] != ';') {
            if (linha_aux[contador] != ' ') {
                variavel = variavel + linha_aux[contador];
            }
            contador++;
        }

        DeclararVariavel(variavel);

        for (int i = 0; i < vetCSharp->size(); i++)
        {
            if (vetCSharp->at(i) == palavra)
            {
                linha = linha.replace(x, y, vetCPlus->at(i) + " ");// funcao replace (subtituir)
            }
        }
    }
}

string Palavra:: findPalavra(string linha) {
    int x;
    int i;
    int y = 0;
    int contador;
    string palavra;
    string variavel = "";
    string linha_aux = linha;
    palavra = "using System;";
    x = linha.find(palavra); // função find (procurar)

    if (x != -1) {
        linha = "";
    }

    palavra = "namespace";
    x = linha.find(palavra);

    if (x != -1) {
        linha = "";
    }

    palavra = "class";
    x = linha.find(palavra);

    if (x != -1) {
        linha = "";
    }

    palavra = "static void Main";
    x = linha.find(palavra);

    if (x != -1) {
        linha = "";
    }

    palavra = "int";
    Declaracao(linha, palavra);

    palavra = "float";
    Declaracao(linha, palavra);


    palavra = "double";
    Declaracao(linha, palavra);

    palavra = "string";
    Declaracao(linha, palavra);

    palavra = "bool";
    Declaracao(linha, palavra);

    palavra = "if";
    x = linha.find(palavra);
    y = palavra.length() + 1;
    linha_aux = linha;
    if (x != -1) {
        for(i = 0; i < vetCSharp->size(); i++)
        {
            if (vetCSharp->at(i) == palavra)
            {
                linha = linha.replace(x, y, vetCPlus->at(i) + " ");// funcao replace (subtituir)
            }
        }
        linha_aux = linha_aux.replace(x, y, " ");

        palavra = "(";
        x = linha_aux.find(palavra);
        y = palavra.length();
        linha_aux = linha_aux.replace(x, y, " ");

        palavra = ")";
        x = linha_aux.find(palavra);
        y = palavra.length();
        linha_aux = linha_aux.replace(x, y, " ");

        Condicao(linha_aux);
    }

    palavra = "else";
    x = linha.find(palavra);
    y = palavra.length();
    linha_aux = linha;
    if (x != -1) {
        for(i = 0; i < vetCSharp->size(); i++)
        {
            if (vetCSharp->at(i) == palavra)
            {
                linha = linha.replace(x, y, vetCPlus->at(i) + " ");// funcao replace (subtituir)
            }
        }
        linha_aux = linha_aux.replace(x, y, " ");
    }

    Expressao(linha);

    palavra = "Console.WriteLine";
    x = linha.find(palavra);
    y = palavra.length() + 1;
    if (x != -1) {
        linha = linha.replace(x, y, "cout << ");
        linha = linha.substr(0, linha.length() - 2);
        linha = linha + " << endl;";

        palavra = ",";
        x = linha.find(palavra);
        y = palavra.length() + 1;

        if (x != -1) {
            linha = linha.replace(x, y, " << ");
        }
    }

    palavra = "Console.ReadLine()";
    x = linha.find(palavra);
    contador = 0;

    if (x != -1) {
        while (linha[contador] != '=') {
            if (linha[contador] != ' ') {
                variavel = variavel + linha[contador];
            }
            contador++;
        }

        if (!ValidarVariavel(variavel)){
            cout<<"Erro. Varivel " << variavel<<"  nao declarada" << endl;
            exit;
        }

        linha =  "    cin >> " + variavel + ";";
    }

    return linha;
}

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<stdlib.h>
#include<stdio.h>
#include "Palavra.h"

using namespace std;

int main() {

    Palavra *palavra = new Palavra();
    string linha;
    string cPlus;
    string cSharp;
    ifstream arquivoCSharp("C:/Users/raian/Documents/Conversor/codigo.txt");
    ifstream palavrasCplus("C:/Users/raian/Documents/Conversor/c++.txt");
    ifstream palavrasCSharp("C:/Users/raian/Documents/Conversor/c#.txt");

    if(palavrasCplus.is_open()) {
        while (!palavrasCplus.eof())
        {
            getline(palavrasCplus, cPlus);
            palavra->vetCPlus->push_back(cPlus);
        }
    }else{
        cout<<"Erro. Arquivo nao encontrado";
    }

    if(palavrasCSharp.is_open()) {
        while (!palavrasCSharp.eof())
        {
            getline(palavrasCSharp, cSharp);
            palavra->vetCSharp->push_back(cSharp);
        }
    }else{
        cout<<"Erro. Arquivo nao encontrado";
    }

    int quantidadeLinha = 0;
    if (arquivoCSharp.is_open()) {
        while (!arquivoCSharp.eof()) {
            getline(arquivoCSharp, linha);
            quantidadeLinha++;
        }

        arquivoCSharp.close();
    }else{
        cout<<"Erro. Arquivo nao encontrado";
    }
    //quantidadeLinha = quantidadeLinha - 2;

    FILE *arquivoEscrita;
    arquivoEscrita = fopen("C:/Users/raian/Documents/Conversor/arqC.cpp", "w");


    char bibliotecaIostream[20] = "#include<iostream>";
    char bibliotecaString[20] = "#include<string>";
    char usingNamespace[30] = "using namespace std;";
    char intMain[40] = "int main(){";

    fprintf(arquivoEscrita, "%s\n", bibliotecaIostream);
    fprintf(arquivoEscrita, "%s\n", bibliotecaString);
    fprintf(arquivoEscrita, "%s\n", usingNamespace);
    fprintf(arquivoEscrita, "%s\n", intMain);

    string linhaAux;
    ifstream codigo("C:/Users/raian/Documents/Conversor/codigo.txt");
    int i = 0;
    if (codigo.is_open()) {
        while (i < quantidadeLinha) {
            getline(codigo, linha);
            linhaAux = palavra->findPalavra(linha);
            if (linhaAux != "") {
                fprintf(arquivoEscrita, "%s\n", linhaAux.c_str());
            }
            i++;
        }
        codigo.close();
    }
    char penultimaLinha[11] = "return 0;";
    char ultimaLinha[2] = "}";

    fprintf(arquivoEscrita, "%s\n", penultimaLinha);
    fprintf(arquivoEscrita, "%s\n", ultimaLinha);
    fclose(arquivoEscrita);

    system ("pause");

    return 0;
}

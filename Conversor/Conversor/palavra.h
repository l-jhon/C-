#ifndef PALAVRA_H
#define PALAVRA_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Palavra
{
public:
    string palavra;
    vector<string> *vetCPlus;
    vector<string> *vetCSharp;
    vector<string>*vetVariavel;
    vector<char>*vetnum;

    void setPalavra(string);
    string getPalavra();
    string findPalavra(string);
    void Declaracao(string, string);
    void Expressao(string);
    void DeclararVariavel(string);
    bool ValidarVariavel(string);
    void Condicao(string);
    bool Numero(string);
    Palavra();
};

#endif // PALAVRA_H


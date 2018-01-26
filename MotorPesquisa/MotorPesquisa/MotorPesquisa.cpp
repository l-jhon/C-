#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <string.h> // teste
#include <stdlib.h> // teste
#include "hash.h"
#include "termodoc.h"
#include "doc.h"
#include "vetorobjeto.h"


using namespace std;
int main(){

	//    hash obj;
	//    fstream file;
	//    file.open("a_guerra_dos_tronos-george_rr_martin.txt",fstream::in);
	//    doc documento;
	//    documento.setNomeArquivo("a_guerra_dos_tronos-george_rr_martin.txt");
	//    string line;
	//    int i=0,j=0;
	//    string aux;
	//    int exit=0;
	//    vetorObjeto ObjVetor;

	// .........................................................//
	fstream num, file1;
	string linha1, linha, nome;
	num.open("entrada.txt", fstream::in);
	std::getline(num, linha);
	string quant = linha.substr(0, 1);
	char *name = new char[quant.length() + 1];
	memcpy(name, quant.c_str(), quant.length() + 1);
	int interador = atoi(name);
	string arqEntrada[interador];
	num.close();

	file1.open("entrada.txt", fstream::in);
	int var = 0, a = 0, b = 0, exit2 = 0;
	while (std::getline(file1, linha1)){
		a = b = 0;
		b = linha1.find("txt", a + 1);
		cout << linha1 << "\n\n";
		while (b != string::npos){
			if (b == string::npos){
				b = linha1.length();
				exit2 = 1;
			}
			nome = linha1.substr(a, b);
			cout << "\nNome : " << nome << "\n";
			arqEntrada[var] = nome;

			if (exit2)
				break;
			a = b + 1;
			b = linha1.find("txt", a);
			if (b == string::npos){
				b = linha1.length();
				exit2 = 1;
			}
		}
		var++;
		exit2 = 0;
	}
	file1.close();






	//    while(std::getline(file, line)){
	//        i=j=0;
	//        j = line.find(" ",i+1);
	//        cout<<line<<endl;
	//        while(j!=string::npos){
	//            if(j==string::npos){
	//                j=line.length();
	//                exit=1;
	//            }
	//            aux=line.substr(i,j-i);
	//            if(aux.substr(aux.length()-1,1)=="." || aux.substr(aux.length()-1,1)=="," ){
	//                aux=line.substr(i,j-i-1);
	//            }
	//            if(obj.validate(aux)){
	//                cout<<aux<<endl;
	//                int a=obj.Hash(aux,0);
	//                cout<<a<<endl;
	//                ObjVetor.setKey(aux);
	//                //                if(){
	//                obj.put(a,ObjVetor,documento);
	//                //                }
	//            }
	//            if(exit)
	//                break;
	//            i=j+1;
	//            j = line.find(" ",i+1);
	//            if(j==string::npos){
	//                j=line.length();
	//                exit=1;
	//            }
	//        }
	//        exit=0;
	//    }
	//    file.close();

	//    for(int i=0; i<100; i++){
	//        cout<<obj.vetor[i].getKey()<<" ";
	//    }
	//    cout<<endl;

	//    std::list<termoDoc> *c = obj.vetor[52].getPtList();
	//    termoDoc *teste = new termoDoc;
	//    *teste= c->front();
	//    string z = teste->getTermo();
	//    cout<<"\n\n"<<z<<"\n\n";

	for (int i = 0; i<interador; i++){
		cout << arqEntrada[i] << "\n";
	}
	cout << endl;


}//fim main


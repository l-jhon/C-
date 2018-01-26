#include <iostream>
#include <fstream>
#include "Fila.class.h"
#include "Pilha.class.h"
using namespace std;

class Grafo{
private:
	int qtdVertices;
	int qtdArestas;
	bool** Arestas;
	int* visitante;
	bool* visitado;
public:
	Grafo(string);
	Grafo();
	bool menorCaminho(int, int, Pilha<int>*);
	int getQtdVertices();
};
int Grafo::getQtdVertices(){
	return qtdVertices;
}
Grafo::Grafo(){
	system("cls");
	cout << "Informe a quantidade de vertices: ";
	cin >> qtdVertices;
	cout << "Informe a quantidade de arestas: ";
	cin >> qtdArestas;

	// CRIANDO UMA MATRIZ BOOLEANA DINAMICAMENTE DE DIMENSAO qtdVertices x qtdVertices 
	// ESTA MATRIZ VAI REPRESENTAR AS ARESTAS DO GRAFO DIRECIONADO, SE NA POSIÇÃO [0][1] FOR TRUE, ENTÃO
	// EXISTE UMA ARESTA LIGANDO 0 PARA 1, SE FOR FALSE, NAO EXISTE UMA ARESTA LIGANDO 0 PARA 1
	Arestas = new bool*[qtdVertices];
	for (int i = 0; i < qtdVertices; i++){
		Arestas[i] = new bool[qtdVertices];

	}

	/* INICIALIZA TODAS AS POSIÇOES DA MATRIZ COMO FALSE */
	for (int i = 0; i < qtdVertices; i++){
		for (int j = 0; j < qtdVertices; j++){
			Arestas[i][j] = false;
		}
	}

	/* SETA AS COORDENADAS DA MATRIZ COMO TRUE DE ACORDO COM AS ARESTAS DEFINIDAS NO ARQUIVO*/
	for (int i = 0; i < qtdArestas; i++){
		system("cls");
		cout << "Agora voce devera informar o vertice de origem e o vertice de destino de cada aresta.";
		cout << "Aresta N " << i + 1 << ": " << endl;
		int l;
		int c;
		cout << "Origem: ";
		cin >> l;
		cout << "Destino: ";
		cin >> c;
		Arestas[l][c] = true;
	}

	/* CRIA DOIS VETORES, UM PARA SABER SE UM DETERMINADO VERTICE JA FOI VISITADO E OUTRO PRA DIZER QUEM O VISITOU */
	visitante = new int[qtdVertices];
	visitado = new bool[qtdVertices];
	for (int i = 0; i < qtdVertices; i++){ // INICIALIZA OS VETORES
		visitado[i] = false;
		visitante[i] = -1;
	}

}







Grafo::Grafo(string arquivo){
	ifstream Arq(arquivo);
	Arq >> qtdVertices; //ARMAZENANDO A PRIMEIRA LINHA DO ARQUIVO
	Arq >> qtdArestas; //ARMAZENANDO A SEGUNDA LINHA DO ARQUIVO


	// CRIANDO UMA MATRIZ BOOLEANA DINAMICAMENTE DE DIMENSAO qtdVertices x qtdVertices 
	// ESTA MATRIZ VAI REPRESENTAR AS ARESTAS DO GRAFO DIRECIONADO, SE NA POSIÇÃO [0][1] FOR TRUE, ENTÃO
	// EXISTE UMA ARESTA LIGANDO 0 PARA 1, SE FOR FALSE, NAO EXISTE UMA ARESTA LIGANDO 0 PARA 1
	Arestas = new bool*[qtdVertices];
	for (int i = 0; i < qtdVertices; i++){
		Arestas[i] = new bool[qtdVertices];

	}

	/* INICIALIZA TODAS AS POSIÇOES DA MATRIZ COMO FALSE */
	for (int i = 0; i < qtdVertices; i++){
		for (int j = 0; j < qtdVertices; j++){
			Arestas[i][j] = false;
		}
	}

	/* SETA AS COORDENADAS DA MATRIZ COMO TRUE DE ACORDO COM AS ARESTAS DEFINIDAS NO ARQUIVO*/
	for (int i = 0; i < qtdArestas; i++){
		int l;
		int c;
		Arq >> l;
		Arq >> c;
		Arestas[l][c] = true;
	}

	/* CRIA DOIS VETORES, UM PARA SABER SE UM DETERMINADO VERTICE JA FOI VISITADO E OUTRO PRA DIZER QUEM O VISITOU */
	visitante = new int[qtdVertices];
	visitado = new bool[qtdVertices];
	for (int i = 0; i < qtdVertices; i++){ // INICIALIZA OS VETORES
		visitado[i] = false;
		visitante[i] = -1;
	}

	Arq.close(); // FECHA O ARQUIVO
}

bool Grafo::menorCaminho(int Origem, int Destino, Pilha<int>* P){
	if (Origem == Destino){
		P->clear();
		P->push(Origem);
		return true;
	}
	else{
		Fila<int>* F = new Fila<int>();
		F->queue(Origem);
		visitado[Origem] = true;
		int verticeEmTratamento;
		while (!F->isEmpty()){
			if (visitado[Destino]){
				F->clear();
			}
			else{
				verticeEmTratamento = F->dequeue();
				for (int i = 0; i < qtdVertices; i++){
					if (Arestas[verticeEmTratamento][i]){
						if (!visitado[i]){
							F->queue(i);
							visitado[i] = true;
							visitante[i] = verticeEmTratamento;
						}
					}
				}	
			}
		}
		if (visitado[Destino]){
			P->clear();
			P->push(Destino);
			for (int i = Destino; visitante[i] != -1; i = visitante[i]){
				P->push(visitante[i]);
			}
			return true;
		}
		else{
			return false;
		}
	}	
}
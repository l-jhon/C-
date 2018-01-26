#ifndef LISTAVETOR_H
#define LISTAVETOR_H
#include<iostream>
using namespace std;

class intNode{//criando o no
public:
	string dado;
	int quantidadeRepete;
	intNode *next;
	intNode(string palavra, int quantidade, intNode *ptr = NULL){
		dado = palavra;
		quantidadeRepete = quantidade;
		next = ptr;
	}
};

class listavetor{
private:
	intNode *first, *last;
	int tamanhoLista;
	int tamanhoMax;
public:
	listavetor();//construtor
	~listavetor();//destrutor
	bool listaVazia();//verifica se a lista esta vazia
	int getTamanho();//retorna o tamanho da lista
	void addItemInicio(int item);//adiciona item no inicio
	void addItemFinal(int item);//adiciona item no final
	void imprimiLista();//imprime os itens da lista
	void limparLista();//limpa a lista(first=last=NULL)
	void verificaItem(int item);//verifica se o item esta na lista e retorna a sua POSICAO
	void alteraItem(int posicao, int item);//altera um item ja instanciado
	void addItemPosicao(int item, int posicao);//adiciona item na posicao desejada
	bool testeItem(int item);//testa o item a ser adicionado
	bool posicaoValida(int posicao);//verifica a posicao do item
};

#endif // LISTAVETOR_H

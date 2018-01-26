#include "Node.class.h"
#include <iostream>
template <typename T>
class Fila{
private:
	Node<T>* Inicio;
	Node<T>* Fim;
public:
	Fila();
	void queue(T);
	T dequeue();
	T first();
	T last();
	bool isEmpty();
	void clear();
	int size();
	void print();
};
template <typename T>
Fila<T>::Fila(){
	Inicio = NULL;
	Fim = NULL;
}

template <typename T>
void Fila<T>::queue(T x){
	Node<T>* PTO = new Node<T>(x);
	PTO->Prox = NULL;
	if (Fim){
		Fim->Prox = PTO;		
		Fim = PTO;
	}
	else{
		Inicio = PTO;
		Fim = PTO;
	}
}

template <typename T>
T Fila<T>::dequeue(){
	if (Inicio){
		Node<T>* PTO = Inicio;
		Inicio = Inicio->Prox;
		T x = PTO->x;
		delete PTO;
		if (!Inicio){
			Fim = NULL;
		}
		return x;
	}
	else{
		return 0;
	}
}

template <typename T>
T Fila<T>::first(){
	if (Inicio){
		return Inicio->x;
	}
	else{
		return 0;
	}
}

template <typename T>
T Fila<T>::last(){
	if (Fim){
		return Fim->x;
	}
	else{
		return 0;
	}
}

template <typename T>
bool Fila<T>::isEmpty(){
	if (!Inicio){
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
void Fila<T>::clear(){
	Fim = NULL;
	while (Inicio){
		Node<T>* PTO = Inicio;
		Inicio = Inicio->Prox;
		delete PTO;
	}
	Inicio = NULL;
}

template <typename T>
int Fila<T>::size(){
	Node<T>* PTO = Inicio;
	int cont = 0;
	while (PTO){
		PTO = PTO->Prox;
		cont++;
	}
	return cont;
}

template <typename T>
void Fila<T>::print(){
	Node<T>* PTO = Inicio;
	while (PTO){
		cout << PTO->x << "\t";
		PTO = PTO->Prox;
	}
}
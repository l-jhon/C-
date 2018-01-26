#include <iostream>
using namespace std;


template <typename T>
class Pilha{
private:
	Node<T>* topo;
	void print(Node<T>*);
	void printInvertido(Node<T>*);
public:
	Pilha() :topo(NULL){};
	void push(T);
	T pop();
	T getTopo();
	bool isEmpty();
	void clear();
	int size();
	void inverter();
	void print();
	void printInvertido();
};

/* IMPLEMENTA플O DO METODO PUSH */
template <typename T>
void Pilha<T>::push(T x){
	Node<T>* PTO = new Node<T>(x);
	PTO->Prox = topo;
	topo = PTO;
}

/* IMPLEMENTA플O DO METODO POP */
template <typename T>
T Pilha<T>::pop(){
	if (topo){
		Node<T>* PTO = topo;
		T aux = PTO->x;
		topo = PTO->Prox;
		delete PTO;
		return aux;
	}
	else{
		//return NULL;
	}
}

/* IMPLEMENTA플O DO METODO PARA VISUALIZAR O TOPO */
template <typename T>
T Pilha<T>::getTopo(){
	if (topo){
		return topo->x;
	}
	else{
		return 0;
	}
}

/*IMPLEMENTA플O DO METODO QUE VERIFICA SE A PILHA ESTA VAZIA*/
template <typename T>
bool Pilha<T>::isEmpty(){
	if (topo){
		return false;
	}
	else{
		return true;
	}
}

/* IMPLEMENTA플O DO METODO QUE LIMPA A PILHA */
template <typename T>
void Pilha<T>::clear(){
	Node<T>* PTO = topo;
	while (PTO){
		Node<T>* PTO2 = PTO->Prox;
		delete PTO;
		PTO = PTO2 ;
	}
	topo = NULL;
}

/*IMPLEMENTA플O DO METODO PARA VERIFICAR O TAMANHO DA PILHA*/
template <typename T>
int Pilha<T>::size(){
	Node<T>* PTO = topo;
	int cont = 0;
	while (PTO){
		cont++;
		PTO = PTO->Prox;
	}
	return cont;
}

/*IMPLEMENTA플O DO METODO QUE INVERTE A PILHA*/
template <typename T>
void Pilha<T>::inverter(){
	Pilha<T>* P1 = new Pilha<T>();
	Pilha<T>* P2 = new Pilha<T>();
	while (!this->isEmpty()){
		P1->push(pop());
	}
	while (!P1->isEmpty()){
		P2->push(P1->pop());
	}
	while (!P2->isEmpty()){
		this->push(P2->pop());
	}
}

/* IMPLEMENTA플O DO METODO DE IMPRIMIR RECURSIVO */
template <typename T>
void Pilha<T>::print(){
	print(topo);
}
template <typename T>
void Pilha<T>::print(Node<T>* PTO){
	if (PTO){
		cout << PTO->x << "  ";
		print(PTO->Prox);
	}
}

/* IMPLEMENTA플O DO METODO DE IMPRIMIR RECURSIVO INVERTIDO */
template <typename T>
void Pilha<T>::printInvertido(){
	printInvertido(topo);
}
template <typename T>
void Pilha<T>::printInvertido(Node<T>* PTO){
	if (PTO){
		printInvertido(PTO->Prox);
		cout << PTO->x << "\t";
	}
}

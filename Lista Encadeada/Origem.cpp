#include <iostream>
#include "Lista_Encadeada.h"

using namespace std;

int main(){
	bool retorno;
	int elemento;
	int A, B, x, op, y, indice;
	Lista_Encadeada* lst = new Lista_Encadeada();
	do {
		system("cls");
		cout << " 1 - Inserir no inicio\n 2 - Inserir no final\n 3 - Inserir em uma posição\n";
		cout << " 4 - Substituir valor pelo índice\n 5 - Retorna valor pelo índice\n 6 - Retorna índice pelo elemento\n";
		cout << " 7 - Remover pelo índice \n";
		cout << " 8 - Imprimir lista\n 9 - Limpar Lista\n 10 - Sair do Programa\n ";
		cout << "\nDigite a opcao desejada: ";
		cin >> op;

		switch (op){
		case 1:
			system("cls");
			do{
				cout << "Digite o valor a ser inserido: ";
				cin >> x;
				lst->add_begin(x);
				cout << "Inserir outro valor? 0 - Nao 1 - Sim: ";
				cin >> y;
			} while (y);
			break;


		case 2:
			system("cls");
			do{
				cout << "Digite o valor a ser inserido: ";
				cin >> x;
				lst->add_pto(x);
				cout << "Inserir outro valor? 0 - Nao 1 - Sim: ";
				cin >> y;
			} while (y);
			break;


		case 3:
			system("cls");
			do{
				cout << "Digite o valor a ser inserido: ";
				cin >> y;
				cout << "Digite o índice do valor à ser inserido:";
				cin >> x;
				lst->add_at(x,y);
				cout << "Inserir outro valor? 0 - Nao 1 - Sim: ";
				cin >> y;
			} while (y);
			break;


		case 4:
			system("cls");
			cout << "Digite o indice: ";
			cin >> x;
			cout << "Digite o valor:";
			cin >> y;

			retorno = lst->set(x, y);

			if (retorno = true)
			{
				cout << "Operação realizada!" << endl;
			}
			else
				cout << "Operação não realizada!" << endl;
			break;


		case 5:
			system("cls");
			cout << "Digite o indice: ";
			cin >> x;
			elemento = lst->get(x);
			cout << "Elemento:" << elemento << endl;
			system("PAUSE");
			break;

		case 6:
			system("cls");
			cout << "Digite o valor: ";
			cin >> x;
			elemento = lst->find(x);
			cout << "Índice do elemento:" << elemento << endl;
			break;

		case 7:
			system("cls");
			cout << "Digite o indice: ";
			cin >> x;

			retorno = lst->remove(x);

			if (retorno = true)
			{
				cout << "Operação realizada!" << endl;
			}
			else
				cout << "Operação não realizada!" << endl;
			system("PAUSE");
			break;

		case 8:
			system("cls");
			lst->print();
			system("PAUSE");
			break;

		case 9:
			system("cls");
			lst->clear();
			system("PAUSE");
			break;

		}
	} while (op != 10);
				
	//system("PAUSE");
	return 0;
}

w
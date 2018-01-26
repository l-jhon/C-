#include <iostream>
#include "Pilha.h"

using namespace std;

int main(void)
{
	int x, op, y;
		Pilha *ObjPilha = new Pilha();

		do {
			system("cls");
			cout << " 1 - Empilhar\n 2 - Desempilhar\n 3 - Obter elemento do topo da Pilha\n";
			cout << " 4 - Verifica se a Pilha esta vazia\n 5 - Limpar Pilha\n 6 - Tamanho da Pilha\n";
			cout << " 7 - Inverter ordem dos elementos da Pilha \n";
			cout << " 8 - Imprimir elementos da Pilha\n";
			cout << "\nDigite a opcao desejada: ";
			cin >> op;

			switch (op){
			case 1:
				system("cls");
				do{
					cout << "Digite o valor a ser empilhado: ";
					cin >> x;
					ObjPilha -> push(x);
					cout << "Empilhar outro valor? 0 - Nao 1 - Sim: ";
					cin >> y;
				} while (y);
				break;


			case 2:
				system("cls");
				do{
					if (ObjPilha->is_empty())
					{
						cout << "Pilha Vazia!" << endl;
					}
					else
					{
						cout << "Elemento do topo que foi desempilhado: " << ObjPilha->get_top()<< endl;
						ObjPilha->pop();
					}
						cout << "Desempilhar novo topo? 0 - Nao 1 - Sim: ";
						cin >> y;
				} while (y);
				system("PAUSE");
				break;

			case 3:
				system("cls");
				if (ObjPilha->is_empty())
				{
					cout << "Pilha vazia!" << endl;
				}
				else
				{
					cout <<"Topo da pilha: " << ObjPilha->get_top() << endl;
				}
				system("PAUSE");
				break;

			case 4:
				system("cls");
				if (ObjPilha->is_empty())
				{
					cout << "A Pilha esta vazia!" << endl;
				}
				else
				{
					cout << "A Pilha nao esta vazia!" << endl;
				}
				system("PAUSE");
				break;

			case 5:
				system("cls");
				ObjPilha->clear();
				cout << "Toda a Pilha foi desempilhada!" << endl;
				system ("PAUSE");
				break;


			case 6:
				system("cls");
				if (ObjPilha->size() == NULL)
				{
					cout << "A Pilha esta vazia!" << endl;
				} 
				else
				{
					cout << "Quantidade de elementos na pilha:" << ObjPilha->size() << endl;
				}
				system("PAUSE");
				break;

			case 7:
				system("cls");
				ObjPilha->inverter();
				cout << "Pilha Invertida!" << endl;
				system("PAUSE");
				break;

			case 8:
				system("cls");
				ObjPilha->print();
				system("PAUSE");
				break;

			}
		} while (op != 10);

		//system("PAUSE");
		return 0;
	}

#pragma once

class Node
{
public:
	int x;
	Node *prox;
	Node (int x) :x(x){};
};

class Lista_Encadeada
{
private:
	Node *inicio;
	Node *fim;
	int s;

public:
	Lista_Encadeada();
	void add(int x);
	void add_pto(int x);
	void add_begin(int x);
	void add_at(int i, int x);
	bool set(int i, int x);
	int get(int x);
	int find(int x);
	bool remove(int i);
	int size();
	bool is_empty();
	void clear();
	void set(int x);
	void print();
	void print_desc(Node *);
};


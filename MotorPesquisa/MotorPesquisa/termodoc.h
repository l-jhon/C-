#ifndef TERMODOC_H
#define TERMODOC_H
#include <iostream>
#include "doc.h"

using namespace std;

class termoDoc{
private:
	string termo;
	int quantidadeDistintos;
	doc *ptDoc;

public:
	termoDoc(){
		termo = "";
		quantidadeDistintos = 1;
		ptDoc = 0;

	}
	void setTermo(string p){ termo = p; }
	string getTermo(){ return termo; }
	void setQuantidade(int quant){ quantidadeDistintos = quant; }
	int getQuantidade(){ return quantidadeDistintos; }
	void setPtDoc(doc *t){ ptDoc = t; }
	doc* getPtDoc(){ return ptDoc; }

};

#endif // TERMODOC_H

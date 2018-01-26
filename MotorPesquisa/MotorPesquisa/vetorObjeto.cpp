#ifndef VETOROBJETO_H
#define VETOROBJETO_H
#include "termodoc.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class vetorObjeto{
private:
	string key;
	std::list<termoDoc>* ptList;
public:

	vetorObjeto();
	void setKey(string k){ key = k; }
	string getKey(){ return key; }
	void setPtList(std::list<termoDoc>* lista){ ptList = lista; }
	std::list<termoDoc>* getPtList(){ return ptList; }
	vetorObjeto(string k, std::list <termoDoc>* l = NULL){
		key = k;
		ptList = l;
	}
};

#endif // VETOROBJETO_H

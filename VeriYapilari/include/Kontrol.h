#ifndef KONTROL_H
#define KONTROL_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node{
	
	string isim;
	Node* next;
	Node* prev;
};

class Kontrol
{

public:
    void NodeEkle(int,string);
	void NodeSil(int);
	void bastir(Node*);
	void DosyaIslemleri();
	void Temizle(Node*);
};


#endif
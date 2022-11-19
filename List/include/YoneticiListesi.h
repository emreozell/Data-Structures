#ifndef YONETICILISTESI_H
#define YONETICILISTESI_H
#include "SayiListesi.h"
class YoneticiListesi{
	public:
	YoneticiListesi* next;
	YoneticiListesi* prev;
	SayiListesi* sayilistesi;
	~YoneticiListesi(){
		while (this->next != this)
		{
		YoneticiListesi* p = this->next;
		p->next->prev = this;
		this->next = p->next;
		delete p;
		}
		delete this;
	}
	
	
};
#endif
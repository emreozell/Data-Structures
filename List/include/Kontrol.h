#ifndef KONTROL_H
#define KONTROL_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Node.h"
#include "SayiListesi.h"
#include "YoneticiListesi.h"
using namespace std;



class Kontrol
{

public:
	YoneticiListesi* DosyaIslemleri(YoneticiListesi*);
	YoneticiListesi* ekle(YoneticiListesi*,SayiListesi*);
	YoneticiListesi* ekranaBas(YoneticiListesi*);
	YoneticiListesi* guncelle(YoneticiListesi*);
};


#endif
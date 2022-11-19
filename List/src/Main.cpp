#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Kontrol.h"
#include "YoneticiListesi.h"


using namespace std;


int main()
{
	YoneticiListesi* yonetici_=new YoneticiListesi();
	Kontrol *k=new Kontrol();
	yonetici_=k->DosyaIslemleri(yonetici_);
	k->ekranaBas(yonetici_);

}
#include "Kontrol.h"
#include "Node.h"
#include "Sayilistesi.h"
#include "YoneticiListesi.h"
#include <iomanip>
#include<cstdlib>
void cizgiyaz(YoneticiListesi* iter,YoneticiListesi*sayfason){
	do{
		
		cout<<"----------"<<setw(8)<<"";
		iter=iter->next;
	}while(iter!=sayfason->next);
	cout<<endl;
}
void adresyaz1(YoneticiListesi* iter,YoneticiListesi* sayfason){
	do{
		
		cout<<iter<<setw(10)<<"";
		iter=iter->next;
		
	}while(iter!=sayfason->next);
	cout<<endl;
}
void adresyaz2(YoneticiListesi* iter,YoneticiListesi* sayfason,int a){
	if(a==1){
	do{
		
		cout<<"|"<<iter->prev<<"|"<<setw(8)<<"";
		iter=iter->next;
	
	}while(iter!=sayfason->next);
	cout<<endl;
	}
	else if(a==2){
		do{
		
		cout<<"|"<<iter->next<<"|"<<setw(8)<<"";
		iter=iter->next;
	
		}while(iter!=sayfason->next);
		cout<<endl;
			
	}
}
void adresyaz3(YoneticiListesi* iter,YoneticiListesi* sayfason){
	
	
	do{
		
		cout<<"|"<<iter->next<<"|"<<setw(8)<<"";
		iter=iter->next;
		
	}while(iter!=sayfason->next);
}
YoneticiListesi* Kontrol::guncelle(YoneticiListesi* ilk_){
	
	YoneticiListesi* iter=ilk_;
	while(iter->next!=ilk_){
		YoneticiListesi* yedek;
		yedek=iter;
		while(yedek->next!=ilk_){
			
			if(yedek->sayilistesi->aritmetikOrtalama >yedek->next->sayilistesi->aritmetikOrtalama){
				YoneticiListesi* temp;
				YoneticiListesi* ab;
				ab=yedek;
				temp=yedek->next;
				temp->prev=yedek->prev;
				ab->prev->next=temp;
				ab->next=temp->next;
				temp->next->prev=ab;
				temp->next=ab;
				ab->prev=temp;
				
				
			}
			yedek=yedek->next;
		}
		
		iter=iter->next;
		
	}
	
	
	return ilk_;
	
	
}
YoneticiListesi* Kontrol:: ekle(YoneticiListesi* ilk,SayiListesi* SatirSayiListesi){
	YoneticiListesi *yeni= NULL, *gecici, *silGecici;
		 if (ilk ->next== NULL) {
      
        ilk->sayilistesi = SatirSayiListesi;
        ilk->next = ilk;
		ilk->prev=ilk;
		
    } else {
		
        //Girilen sayi ilk sayidan kucuk ise
        if ((ilk->sayilistesi->aritmetikOrtalama) > (SatirSayiListesi->aritmetikOrtalama)) {
            yeni = new YoneticiListesi();
            yeni->sayilistesi = SatirSayiListesi;
            yeni->next = ilk;
			yeni->prev=ilk->prev;
			ilk->prev->next=yeni;
			ilk->prev=yeni;
			ilk=yeni;
			
            ilk = yeni;
        } else {
            gecici = ilk;
            yeni = new YoneticiListesi();
            yeni->sayilistesi =SatirSayiListesi;
            do{

				
                //gecici elemaninin sonraki null ise ve son elemandan buyukse
                if (gecici->next == ilk && (gecici->sayilistesi->aritmetikOrtalama) <= (SatirSayiListesi->aritmetikOrtalama)) {
                    yeni->next = ilk;
					yeni->prev=gecici;
                    gecici->next = yeni;
					ilk->prev=yeni;
                    break;
                }
                //Araya Ekleme
                if ((gecici->next->sayilistesi->aritmetikOrtalama) > (SatirSayiListesi->aritmetikOrtalama)) {
                    yeni->next = gecici->next;
					yeni->next->prev=yeni;
					yeni->prev=gecici;
                    gecici->next = yeni;
                    break;
                }
                gecici = gecici->next;
				
            }while(gecici!=ilk);
        }
    }
	
	return ilk;
	
}
YoneticiListesi* Kontrol:: ekranaBas(YoneticiListesi* ilk){
	
	
	char girilen;
	YoneticiListesi* sayfabas;
	YoneticiListesi* secili;
	YoneticiListesi* yedek;
	YoneticiListesi* sayfason;
	sayfabas=ilk;
	sayfason=sayfabas;
	secili=sayfabas;
	yedek=sayfabas;
	int sayac=0;
	bool kBasma=true;
	srand((unsigned) time(NULL));

		
	
	
	while(true){
		
		while(sayfason->next!=ilk && sayac<7){
		
		sayfason=sayfason->next;
		sayac++;
		}
	
	YoneticiListesi* iter;
	

	system("cls");
	
	if(sayfabas==ilk){
		cout<<"ilk-->";
	}else{
		
		cout<<"<---";
	}
	if(sayfason->next==ilk){
		cout<<setw(18*sayac)<<"<--son"<<endl;
		
	}else{
	cout<<setw(18*sayac)<<""<<"--->"<<endl;
	}
	cout<<" ";
	
	iter=sayfabas;
	
	adresyaz1(iter,sayfason);
	cizgiyaz(iter,sayfason);
	adresyaz2(iter,sayfason,1);
	cizgiyaz(iter,sayfason);
	
	do{
		
			cout << "|"<<setw(8)<<setprecision (1) << fixed << iter->sayilistesi->aritmetikOrtalama<<"|"<<setw(8)<<"";
		
		iter=iter->next;
		
	}while(iter!=sayfason->next);
	
	cout<<endl;
	iter=sayfabas;
	cizgiyaz(iter,sayfason);
	adresyaz2(iter,sayfason,2);
	cizgiyaz(iter,sayfason);
	
	int sayac2=0;
	yedek=sayfabas;
	int random=0;
	while(yedek!=secili){
		sayac2++;
		yedek=yedek->next;
	}
	if(secili->sayilistesi->count==1){
		
		random=0;
	}else{
		 random = rand()%(secili->sayilistesi->count+1);
	}
	sayac2=18*sayac2;
	
	Node* silinecekNode=secili->sayilistesi->head;
	for(int i=0;i<random;i++){
		silinecekNode=silinecekNode->next;
	}
	cout<<setw(sayac2)<<""<<"^^^^^^^^^^"<<endl;
	if(yedek==secili){
		Node* temp;
		temp=secili->sayilistesi->head;
		do{
			if(temp==silinecekNode && kBasma==false){
				silinecekNode=temp;
				
				cout<<" "<<setw(sayac2)<<""<<temp<<endl;
				cout<<setw(sayac2)<<""<<"----------"<<endl;
				int no=temp->deger;
				int a=0;
				while(no>0)
				{
					no=no/10;
					a++;
				}
				cout<<setw(sayac2)<<""<<"|"<<setw(5-a)<<""<<temp->deger<<setw(5-a)<<""<<"|"<<"<----silinecek node"<<endl;
				cout<<setw(sayac2)<<""<<"----------"<<endl;
				cout<<" "<<setw(sayac2)<<""<<temp->next<<endl;
				cout<<setw(sayac2)<<""<<"----------"<<endl;
				temp=temp->next;
			
		
			}
			else{
			
			cout<<" "<<setw(sayac2)<<""<<temp<<endl;
			cout<<setw(sayac2)<<""<<"----------"<<endl;
			int no=temp->deger;
			int a=0;
			while(no>0)
			{
				no=no/10;
				a++;
			}
			cout<<setw(sayac2)<<""<<"|"<<setw(5-a)<<""<<temp->deger<<setw(5-a)<<""<<"|"<<endl;
			cout<<setw(sayac2)<<""<<"----------"<<endl;
			cout<<" "<<setw(sayac2)<<""<<temp->next<<endl;
			cout<<setw(sayac2)<<""<<"----------"<<endl;
			temp=temp->next;
			
			}
			
		}while(temp!=secili->sayilistesi->head);
		
	}
	yedek=sayfabas;
	
	cin>>girilen;
	
	switch(girilen){
		case'x':{
			ilk=guncelle(ilk);
			
			break;
		};
		case 'c':{ if(secili==sayfason && sayfason->next!=ilk){
						sayfabas=sayfason->next;
						sayfason=sayfabas;
						secili=sayfabas;
						sayac=0;
					}else if(secili!=sayfason){
						
						secili=secili->next;

					}
					
					kBasma=true;
					
						break;}
		case 'z':{	if(secili==sayfabas && sayfabas!=ilk){
				
						for(int i=0;i<8;i++){
							
							if(sayfabas==ilk){
								
								break;
							}
							sayfabas=sayfabas->prev;
							
						}
						
						sayac=0;
						secili=secili->prev;
						sayfason=sayfabas;
					}else if(secili!=sayfabas){
							secili=secili->prev;
					}
					kBasma=true;
						break;}
		case 'd':{		
		
						if(sayfason->next!=ilk){
						sayfabas=sayfason->next;
						sayfason=sayfabas;
						secili=sayfabas;
						sayac=0;
						}kBasma=true;
						break;}
		case 'a':{
			
					if(sayfabas!=ilk){
						for(int i=0;i<8;i++){
							
							if(sayfabas==ilk){
								kBasma=true;
								break;
							}
							sayfabas=sayfabas->prev;
							
						}
						
						sayac=0;
						secili=sayfabas;
						sayfason=sayfabas;
			
					}kBasma=true;
						break;}
		case 'p':{
						
						if(ilk->next==ilk){
							
						}
						else if(secili==ilk){
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=secili->next;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							ilk=secili;
							sayfabas=ilk;
							sayac=0;
							sayfason=sayfabas;
							free(silinecek);
						}else if(secili->next==ilk){
							
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=ilk;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							sayfabas=ilk;
							sayac=0;
							sayfason=sayfabas;
							free(silinecek);
							
						}else if(secili==sayfabas){
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=secili->next;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							free(silinecek);
							sayac=0;
							sayfabas=secili;
							sayfason=sayfabas;
							
							
						}else{ 
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=secili->next;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							free(silinecek);
							sayac=0;
							sayfason=sayfabas;
							
							
						}kBasma=true;
						break;}
		case 'k':{	if(kBasma==true){
						
						kBasma=false;
						break;
					}
					else if(kBasma==false){
						kBasma=true;
						if(secili->sayilistesi->count==1){
							
						if(ilk->next==ilk){
							
						}
						else if(secili==ilk){
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=secili->next;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							ilk=secili;
							sayfabas=ilk;
							sayac=0;
							sayfason=sayfabas;
							free(silinecek);
						}else if(secili->next==ilk){
							
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=ilk;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							sayfabas=ilk;
							sayac=0;
							sayfason=sayfabas;
							free(silinecek);
							
						}else if(secili==sayfabas){
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=secili->next;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							free(silinecek);
							sayac=0;
							sayfabas=secili;
							sayfason=sayfabas;
							
							
						}else{ 
							YoneticiListesi* silinecek;
							silinecek=secili;
							secili=secili->next;
							silinecek->prev->next=secili;
							secili->prev=silinecek->prev;
							free(silinecek);
							sayac=0;
							sayfason=sayfabas;
							
						}
						;	
					}
					else{
						
						if(secili->sayilistesi->head==silinecekNode){
							Node* temp;
							
							temp=silinecekNode;
							temp=temp->next;
							temp->prev=silinecekNode->prev;
							silinecekNode->prev->next=temp;
							secili->sayilistesi->head=temp;
							secili->sayilistesi->aritmetikOrtalama=((secili->sayilistesi->aritmetikOrtalama*secili->sayilistesi->count)-silinecekNode->deger)/(secili->sayilistesi->count-1);
							secili->sayilistesi->count--;
						
							if(secili->sayilistesi->aritmetikOrtalama<ilk->sayilistesi->aritmetikOrtalama){
								
								YoneticiListesi* temp;
								secili->prev->next=secili->next;
								secili->next->prev=secili->prev->next;
								secili->prev=ilk->prev;
								ilk->prev->next=secili;
								ilk->prev=secili;
								secili->next=ilk;
								ilk=secili;
						
								
							}
							
							free(silinecekNode);
							ilk=guncelle(ilk);
						
							
							
						}
							else{
							Node* temp;
								
							temp=silinecekNode;
							temp=temp->next;
							temp->prev=silinecekNode->prev;
							silinecekNode->prev->next=temp;
							secili->sayilistesi->aritmetikOrtalama=((secili->sayilistesi->aritmetikOrtalama*secili->sayilistesi->count)-silinecekNode->deger)/(secili->sayilistesi->count-1);
							secili->sayilistesi->count--;
	
							free(silinecekNode);
							ilk=guncelle(ilk);
							
						}
						
						
						
					}
						ilk=guncelle(ilk);
						sayfabas=ilk;
						secili=sayfabas;
						sayfason=sayfabas;
						sayac=0;
						}
					
				break;
				}
	girilen='*';
	
	}
	}
	
}
YoneticiListesi* Kontrol::DosyaIslemleri(YoneticiListesi* ilk)
{	
	
	
	ifstream dosyaoku;
	dosyaoku.open("veriler.txt");
	string satir;
	
	
		Node* iter;
		int sayac=0;
	
	while(getline(dosyaoku,satir)){
		SayiListesi* SatirSayiListesi=new SayiListesi();
		
		Node* bas=new Node();
		SatirSayiListesi->head=bas;
		iter=bas;
		SatirSayiListesi->aritmetikOrtalama=0;
		SatirSayiListesi->count=0;
		
		stringstream s(satir);
		string word;
		while (s >> word) {
			iter->deger=stoi(word);
			SatirSayiListesi->count++;
			SatirSayiListesi->aritmetikOrtalama+=stoi(word);
			Node* temp=new Node();
			iter->next=temp;
			iter->next->prev=iter;			
			iter=iter->next;
			sayac++;
			
			
		}
		SatirSayiListesi->aritmetikOrtalama=(SatirSayiListesi->aritmetikOrtalama)/sayac;
		
		iter=iter->prev;
		iter->next=bas;
		bas->prev=iter;
		sayac=0;
	 
		ilk=ekle(ilk,SatirSayiListesi);
		
		}
		YoneticiListesi* iter2;
		iter2=ilk;
		for(int i=0;i<8;i++){
			cout<<iter2<<endl;
			iter2=iter2->next;
		}
	
		return ilk;
	
}


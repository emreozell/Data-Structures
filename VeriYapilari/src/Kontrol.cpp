#include "Kontrol.h"

Node* head=NULL;
int sayac=0;


void Kontrol::NodeEkle(int numara,string isim){
	
	string str;
	Node* iter;
	Node* temp=new Node();
	if(head==NULL){
		head=temp;
		head->isim=isim;
		head->next=NULL;
		head->prev=NULL;
	}
	else if(numara>=sayac){
		iter=head;
		while(iter->next!=NULL){	
			iter=iter->next;
		};
		iter->next=temp;
		temp->next=NULL;
		temp->prev=iter;
		temp->isim=isim;
	}
	else{
		iter=head;
		while(iter->next!=NULL){	
			iter=iter->next;
			
		};
		iter->next=temp;
		temp->next=NULL;
		temp->prev=iter;
		temp->isim=isim;
		for(int i=0;i<sayac-numara-1;i++){
			str=temp->isim;
			temp->isim=iter->isim;
			iter->isim=str;
			temp=temp->prev;
			iter=iter->prev;
			if(temp->prev==NULL){	
				break;
			}
		}
		
	}
	
};
void Kontrol::NodeSil(int numara){	
	Node* iter;
	Node* temp;
	string str;
	if(sayac>numara){
		iter=head;
	for(int i=0;i<numara;i++){
		iter=iter->next;
	}
	while(iter->next!=NULL){
		str=iter->isim;
		iter->isim=iter->next->isim;
		iter->next->isim=str;
		iter=iter->next;
		
	}
	temp=iter->prev;
	temp->next=NULL;
	free(iter);
	}
	if(sayac<=numara){
		
		iter=head;
		
		while(iter->next!=NULL){
			iter=iter->next;
		}
		

	temp=iter->prev;
	temp->next=NULL;
	free(iter);
	}
	
	
};
void Kontrol::bastir(Node* r){
	Node* iter=head;
	
	while(iter!=NULL){
		cout<<iter->isim<<"  ";
		iter=iter->next;
	}
	
	
};
void Kontrol::Temizle(Node *r){
	Node* temp;
	temp=r;
	while(temp->next!=NULL){
	temp=r;
	r=r->next;
	free(temp);
	
	}
	
}
void Kontrol::DosyaIslemleri()
{	
	
	
	ifstream dosyaoku;
	dosyaoku.open("isimler.txt");
	string satir;
	
	while(getline(dosyaoku,satir)){
		string yedek="";
		string ad="";
		int index;
		if(satir[0]=='E'){
			sayac++;
			
			for(int i=2;i<satir.length();i++){
				if(satir[i]=='#'){
				
					break;

				}
				yedek=yedek+satir[i];
				
			}
			for(int i=yedek.length()+3;i<satir.length();i++){
				if(satir[i]==')'){
					
					break;

				}
				ad=ad+satir[i];
				stringstream geek(yedek);
				geek>>index;
				
			}
			
			NodeEkle(index,ad);
			
		};
		if(satir[0]=='S'){
			sayac--;
			yedek="";
			index=0;
			for(int i=2;i<satir.length();i++){
				if(satir[i]==')'){
				
					break;

				}
				yedek=yedek+satir[i];
				
			}
			stringstream geek(yedek);
			geek>>index;
			
			NodeSil(index);
			
		};
	
	}
		bastir(head);
		Temizle(head);
		
	
}


/**
* @file Dosya adı: Veri Yapıları 2. Ödev
* @description Programınızın açıklaması ne yaptığına dair.: Avl Ağacı
* @course Dersi aldığınız eğitim türü ve grup : 1 A 
* @assignment Kaçıncı ödev olduğu	:2 
* @date Kodu oluşturduğunuz Tarih:26.12.20221
* @author Gruptakilerin yazar adları ve mail adresleri: Emre Özel	emre.ozel1@ogr.sakarya.edu.tr
*/

#include "File.h"
#include "avl_tree.h"
#include "Queue.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <fstream>
#include <cmath>
#define pow2(n) (1 << (n))
using namespace std;

void File::oku()
    {
        dosyaoku.open("sayilar.txt");
		
		//Dosyadan okuyup kuyruğa atma

        while (getline(dosyaoku, satir)) {
            int sayac = 0;
		int x;
		int y;
		int z;
		
		
		Queue q;
		
        
        Node* iter;
       

		stringstream s(satir);
		string word;



		while (s >> word) {

			if (sayac % 3 == 0) {
				x = stoi(word);
				

			}
			if (sayac % 3 == 1) {
				y = stoi(word);
				
			}
			if (sayac % 3 == 2) {
				z = stoi(word);
				q.enQueue(x, y, z);
					 
                
                
			}
			sayac++;
		}
		
          iter = q.front;
		//Kurukların toplam uzunluklarını hesaplattım
        while (iter!=q.rear)
        {
			 
              q.toplamUzunluk += sqrt(pow((iter->x - iter->next->x), 2) + pow((iter->y - iter->next->y), 2) + pow((iter->z - iter->next->z), 2));
                iter = iter->next;
         
           
			  
        }
		
      
         avl.r = avl.insert(avl.r, q);
      
       
	}
	
         avl.postorder(avl.r);
    }
/**
* @file Dosya adı: Veri Yapıları 2. Ödev
* @description Programınızın açıklaması ne yaptığına dair.: Avl Ağacı
* @course Dersi aldığınız eğitim türü ve grup : 1 A 
* @assignment Kaçıncı ödev olduğu	:2 
* @date Kodu oluşturduğunuz Tarih:26.12.20221
* @author Gruptakilerin yazar adları ve mail adresleri: Emre Özel	emre.ozel1@ogr.sakarya.edu.tr
*/

#include <Queue.h>
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <fstream>
#include<cmath>


using namespace std;


Node::Node(int _x,int _y,int _z)
{
        x = _x;
        y = _y;
        z = _z;
        uzaklikOrjin = sqrt((x * x) + (y * y) + (z * z));
        next = NULL;
   }
   
 Queue::Queue(){
	
	toplamUzunluk=0;
}
void Queue::enQueue(int x, int y, int z)
    {

        Node* temp = new Node(x, y, z);

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }
	

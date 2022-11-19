
#include "Queue.h"
#include "File.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <fstream>
#include<cmath>

#define pow2(n) (1 << (n))
using namespace std;
//Avl ağaç fonksiyonlarım
avl_tree::avl_tree(){
	
	
	
	r = NULL;
}
int avl_tree::height(avl* t) {
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->ri);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avl_tree::difference(avl* t) {
    int l_height = height(t->l);
    int r_height = height(t->ri);
    int b_factor = l_height - r_height;
    return b_factor;
}
avl* avl_tree::rr_rotat(avl* parent) {
    avl* t;
    t = parent->ri;
    parent->ri = t->l;
    t->l = parent;
 
    return t;
}
avl* avl_tree::ll_rotat(avl* parent) {
    avl* t;
    t = parent->l;
    parent->l = t->ri;
    t->ri = parent;

    return t;
}
avl* avl_tree::lr_rotat(avl* parent) {
    avl* t;
    t = parent->l;
    parent->l = rr_rotat(t);
   
    return ll_rotat(parent);
}
avl* avl_tree::rl_rotat(avl* parent) {
    avl* t;
    t = parent->ri;
    parent->ri = ll_rotat(t);
  
    return rr_rotat(parent);
}
avl* avl_tree::balance(avl* t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1) {
        if (difference(t->ri) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
avl* avl_tree::insert(avl* r, Queue queue) {
    if (r == NULL) {
        r = new avl;
        r->queue = queue;
        r->l = NULL;
        r->ri = NULL;
        return r;
    }
    else if (queue.toplamUzunluk <= r->queue.toplamUzunluk) {
        r->l = insert(r->l, queue);
        r = balance(r);
    }
    else if (queue.toplamUzunluk > r->queue.toplamUzunluk) {
        r->ri = insert(r->ri, queue);
        r = balance(r);
    } return r;
}



void avl_tree::postorder(avl* t) {
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->ri);
	// Postorder dolaşıp ekrana  noktların orjine uzaklığını bastım
    Node* iter;   
    iter = t->queue.front;
    while (iter != NULL)
    {
        cout << iter->uzaklikOrjin << "  ";
        iter = iter->next;
    }
    cout << endl;
}
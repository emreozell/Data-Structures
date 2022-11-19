

#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <Queue.h>
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <fstream>
#define pow2(n) (1 << (n))
using namespace std;


struct avl {

    int d;
    struct avl* l;
    struct avl* ri;
    Queue queue;
};


class avl_tree {
public:
	avl* r;
    int height(avl*);
    int difference(avl*);
    avl* rr_rotat(avl*);
    avl* ll_rotat(avl*);
    avl* lr_rotat(avl*);
    avl* rl_rotat(avl*);
    avl* balance(avl*);
    avl* insert(avl*, Queue);
    void show(avl*, int);
    void inorder(avl*);
    void preorder(avl*);
    void postorder(avl*);
    avl_tree();
        
    
};

#endif
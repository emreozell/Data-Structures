#ifndef FILE_H
#define FILE_H
#include "avl_tree.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <fstream>
#define pow2(n) (1 << (n))
using namespace std;

class File {

	public:
		avl_tree avl;
		ifstream dosyaoku;
		string satir;

		void oku();	 
};

#endif
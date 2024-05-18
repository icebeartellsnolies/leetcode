#include<iostream>
using namespace std;
struct DNode{
	int data;
    DNode *prev;
	DNode *next;//TO point to next node, null otherwise
	//With default value of parameter, we can use the constructor with two as well as one parameter
	DNode (int d, DNode *n=NULL, DNode *p=NULL){
		data = d;
		next = n;
        prev=p;
	}
};
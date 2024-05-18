#include<cstddef>
struct Node{
	int data;
	Node *next;//TO point to next node, null otherwise
	//With default value of parameter, we can use the constructor with two as well as one parameter

	Node (int d, Node *n=NULL){
		data = d;
		next = n;
	}
};

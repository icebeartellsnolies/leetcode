#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node *next;//TO point to next node, null otherwise
	//With default value of parameter, we can use the constructor with two as well as one parameter
	Node (T d, Node *n=NULL){
		data = d;
		next = n;
	}
};

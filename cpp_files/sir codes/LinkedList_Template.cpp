#include <iostream>
#include "Node_Template.cpp"
	
using namespace std;

template <typename T>
class LinkedList{
	Node<T> *head;
public:
	LinkedList(){	head = NULL;	}
	LinkedList& addNodeAtStart(T d){
		head = new Node<T>(d, head);
		return *this;
	}
	LinkedList& addNodeAtEnd(T d){
		if (!head)
			head = new Node<T>(d);
		else{
			Node<T> *t;
			for (t = head ; t -> next != NULL ; t = t -> next);
			t -> next = new Node<T> (d);
		}
		return *this;
	}
	LinkedList& deleteNodeFromStart(){
		if (head!=NULL){
			Node<T> *t = head;
			head = head -> next;
			delete t;
		}
		return *this;
	}
	LinkedList& deleteNodeFromEnd(){
		if (!head)	return *this;	//there is no node to delete
		if (head -> next == NULL){
			delete head;
			head = NULL;
		}
		else{
			Node<T> *t = head;
			for ( ; t -> next -> next != NULL; t = t -> next );//Move to second last node
				delete t->next;
				t->next = NULL;
		}
		return *this;
	}
	
	void show() const{
		for ( Node<T> *t = head ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};


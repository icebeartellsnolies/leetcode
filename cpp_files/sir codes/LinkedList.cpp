#include <iostream>
#include "Node.cpp"
	
using namespace std;

class LinkedList{
	Node *head;
public:
	LinkedList(){	
		head = NULL;
	}
	LinkedList& addNodeAtStart(int d){
		head = new Node(d, head);//In Node constructor either next will point to NULL or some node previously pointed by head
		return *this;
	}
	LinkedList& addNodeAtEnd(int d){
		if (!head)
			head = new Node(d);
		else{
			Node *t;
			for (t = head ; t -> next != NULL ; t = t -> next);
			t -> next = new Node (d);
			// we arent doing t->next->next->data = NULL since in constructor every node's next is null
		}
		return *this;
	}
	LinkedList& deleteNodeFromStart(){
		if (head!=NULL){
			Node *t = head;
			head = head -> next;
			delete t;		
		}
		// else statement added by Naimah
		// else{
		// 	throw("linked list is already empty!");
		// }
		return *this;
	}
	LinkedList& deleteNodeFromEnd(){
		if (!head)	throw("linked list is already empty!");	//there is no node to delete
		if (head -> next == NULL){
			delete head;
			head = NULL;
		}
		else{
			Node *t = head;
			for ( ; t -> next -> next != NULL; t = t -> next );//Move to second last node
			delete t->next;
			t->next = NULL;
		}
		return *this;
	}
	void show(){
		for (Node *t = head ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

// int main(){
// 	LinkedList l1;
// 	l1.deleteNodeFromStart();
// 	l1.show();
// 	return 0;
// }
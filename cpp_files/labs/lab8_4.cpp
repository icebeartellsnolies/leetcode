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
			// we arent doing t->next->next->data = NULL since in coinstructor every node's next is null
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
    void recursive_show(Node *temp){
        if (!temp){
            return;
        }
        cout<<temp->data<<" ";
        temp = temp->next;
        recursive_show(temp);
    }
    void recursive_show(){
        Node *temp=head;
        recursive_show(temp);
    }
    void recursive_show_alternate(Node *temp){
        if (!temp){
            return;
        }
        cout<<temp->data<<" ";
        if (temp->next)
            temp = temp->next->next;
        else return;
        recursive_show_alternate(temp);
    }
    void recursive_show_alternate(){
        Node *temp=head;
        recursive_show_alternate(temp);
    }
    void recursive_removal(Node *t){
        if (!t) {
        head=NULL;
        return;
        }
        recursive_removal(t->next);
        delete t;
        
    }
    void recursive_removal(){
        recursive_removal(head);
    }
};

int main(){
	LinkedList l1;
	
    l1.addNodeAtEnd(11);
    l1.addNodeAtEnd(12);
    l1.addNodeAtEnd(13);
    l1.addNodeAtEnd(14);
    l1.addNodeAtEnd(15);
    l1.addNodeAtEnd(16);
    l1.show();
    // l1.recursive_show();
    // l1.recursive_show_alternate();
    l1.recursive_removal();
    l1.show();
	return 0;
}
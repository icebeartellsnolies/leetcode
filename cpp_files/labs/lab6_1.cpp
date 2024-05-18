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
    LinkedList& add_in_order(T d){
        if (!head){
            head = new Node <T>(d);
        }
        else if (head->next==NULL){
            if (head->data<d){
                addNodeAtEnd(d);
            }
            else{
                addNodeAtStart (d);
            }
        }
        else{
            if (head->data > d){
                addNodeAtStart(d);
            }
            else{
                Node <T>*t;
                for(t=head;t->next!=NULL && t->next->data <= d ; t=t->next);
                Node <T> *temp = t->next;
                t->next = new Node<T>(d);
                t->next->next = temp;
            }
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
    LinkedList& delete_duplicate_elems(){
        Node <T> *curr = head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->data == curr->next->data){
                Node <T> *temp = curr->next->next;
                delete curr->next;
                curr->next = temp;
            }
            else{
                curr = curr->next;
            }
        }
        return *this;
    }

    LinkedList& delete_dups(){
        Node<T> *dummy;
        dummy = new Node <T>(0);
        dummy->next=head;
        Node<T> *runner = head;
        Node<T> *curr = dummy;
        bool entered=false;
        while(runner!=NULL && runner->next!=NULL){
            bool duplicates=false;
                while(runner!=NULL && runner->data == runner->next->data){
                    Node<T> *temp = runner;
                    runner = runner->next;
                    delete temp;
                    duplicates=true;
                }
                           
            if (runner->next && duplicates){
                Node<T> *temp = runner;
                runner = runner->next;
                delete temp;
                duplicates=false;
                curr->next = runner;
            }
            else{
                curr = curr->next;
                runner = runner->next;
            }
    }
        
    head = dummy->next;
    delete dummy;
    return *this;
}

	void show() const{
		for ( Node<T> *t = head ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
	
};

int main(){
    LinkedList<int> l1;
    l1.add_in_order( 2);
    l1.add_in_order( 3);
    l1.add_in_order( 1);
    l1.add_in_order( 0);
    l1.add_in_order( 0);
    l1.add_in_order( 0);
    l1.add_in_order( 0);
    l1.add_in_order( 2);
    l1.add_in_order(10);
    l1.add_in_order(2);
    l1.show();
    // l1.delete_duplicate_elems();
    l1.delete_dups();
    l1.show();
}
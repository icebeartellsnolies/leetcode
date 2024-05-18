#include <iostream>
#include <cstddef>
	
using namespace std;
struct Node{
	int data;
	Node *next;//TO point to next node, null otherwise
	//With default value of parameter, we can use the constructor with two as well as one parameter
	Node (int d, Node *n=NULL){
		data = d;
		next = n;
	}
};

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

    LinkedList& print_duplicates(){
        if (!head ) return *this;
        Node *curr =  head;
        while(curr!=NULL){
            bool dup=false;
            for(Node *runner=head; runner!=NULL && runner!=curr; runner=runner->next){
                if (curr->data==runner->data){
                    // cout<< curr->data << " " ;
                    dup=true;
                    break;
                }
            }
            if (!dup)
                cout<<curr->data<< " ";
            curr = curr->next;
        }
        return *this;
    }
    void remove_dup_elements(){
        Node *t=head;
        while (t!=NULL){
            Node* t1=t->next;
            Node* prev=t;
            while (t1!=NULL){
                if ( t->data==t1->data){
                prev->next=t1->next;
                Node *nodetodelete=t1;
                delete nodetodelete;
                t1=prev->next;	
            }
            else{
                prev=t1;
                t1=t1->next;
            }
        }
        t=t->next;
        }
    }
    LinkedList& uunion(LinkedList& l1){
        remove_dup_elements();
        l1.remove_dup_elements();
        Node *t=head;
        Node *t1=l1.head;
        while (t->next!=NULL){
            t=t->next;
        }
        Node *tail=t;
        t1=l1.head;
        
        while(t1!=NULL){
            t=head;
            bool dup=false; 
            while(t!=NULL){
                if (t->data==t1->data){
                    dup=true;
                    break;
                }    
                t=t->next;   
            }
            if (!dup){
            tail->next=t1;
            t1=t1->next;
            tail=tail->next;
            tail->next=NULL;
            }
            else{
            Node *temp=t1;
            t1=t1->next;
            delete temp;
            }
        }
        l1.head=NULL;
        delete l1.head;
        // remove_dup_elements();
        return *this;
    }
    LinkedList& split_till_odd(){
		Node *t=head;
		while (t!=NULL){
            while(t->data%2==0){
				int d1=t->data/2;
				Node * newnode=new Node(d1);
				t ->data=d1;
				newnode ->next=t ->next;
				t ->next=newnode;	
			}
			t=t ->next;
		}
		return *this;
	}
    
	void show(){
		for (Node *t = head ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(){
	LinkedList l1;
	// l1.addNodeAtEnd(200);
    // l1.addNodeAtEnd(200);
    l1.addNodeAtEnd(20);
    // l1.addNodeAtEnd(100);
    l1.addNodeAtEnd(30);
    l1.addNodeAtEnd(5);
    // l1.addNodeAtEnd(5);
	l1.show();
    // l1.print_duplicates();
    // LinkedList l2;
    // l2.addNodeAtEnd(2);
    // l2.addNodeAtEnd(45);
    // l2.addNodeAtEnd(55);
    // l2.addNodeAtEnd(100);
    // l2.addNodeAtEnd(30);
    // l2.show();
    // l1.uunion(l2);
    // l1.show();
    // l2.show();
    l1.split_till_odd();
    l1.show();
	return 0;
}
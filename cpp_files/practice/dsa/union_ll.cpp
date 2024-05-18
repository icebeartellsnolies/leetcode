#include <iostream>
	
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
    void removeduplicateelements(){
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
        LinkedList& unionn(LinkedList& list1){
            
            Node *t=head;
            removeduplicateelements();
            list1.removeduplicateelements();
            Node* t1=list1.head;
            while(t1!=NULL){
                t=head;
                bool ans=false;
                while (t!=NULL){
                if (t->data==t1->data){
                    ans=true;
                    break;
                }
                t=t->next;
            }
            if (!ans)
            addNodeAtEnd(t1->data);
            Node *temp=t1;
            t1=t1->next;
            delete temp;
    }
    list1.head=NULL;
    delete list1.head;
    return *this;
    }
	void show(){
		for (Node *t = head ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(){
	LinkedList a;
    a.addNodeAtEnd(12);
    a.addNodeAtEnd(38);
    a.addNodeAtEnd(52);

	a.show();
    LinkedList b;
    b.addNodeAtEnd(22);
    b.addNodeAtEnd(18);
    b.addNodeAtEnd(52);

	b.show();
    a.unionn(b);
    a.show();
    b.show();
	return 0;
}
#include <iostream>

	
using namespace std;
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
    LinkedList& bubble_sort(){
        if (!head) return *this;
		Node *curr=head;
		bool swapped=false;
		while(curr!=NULL && !swapped){
			Node *runner = curr->next;
			bool swapped=false;
			while (runner!=NULL)
			{
				if (runner->data<curr->data){
					swap(runner->data, curr->data);
					swapped=true;
				}
				runner = runner->next;
			}
			curr= curr->next;
		}
		return *this;
	}
	// bisma's:
    // LinkedList& bubblesort(){
	// 	Node* end;
	// 	Node* t;
	// 	Node* t1;
	// 	for(end=NULL;end!=t->next;end=t){
	// 		for(t=head;t->next!=end;t=t->next){
	// 			t1=t->next;
	// 			if(t->data > t1->data){
	// 				int temp=t->data;
	// 				t->data=t->next->data;
	// 				t->next->data=temp;
	// 			}
	// 		}
	// 	}
	// 	return *this;
	// }
    LinkedList& selection_sort(){
        if (!head) return *this;
        Node *to_check = head; 
        while(to_check!=NULL){
            Node *curr = to_check->next;
            int min_entry = to_check->data;
            Node *to_swap_node = curr;

            bool swapping = false;
            while(curr){
                if (curr->data<min_entry){
                    min_entry = curr->data;
                    to_swap_node= curr;
                    swapping = true;
                }
                curr = curr->next;
            }
            if (swapping==true){
                to_swap_node->data = to_check->data;
                to_check->data = min_entry;
            }

            to_check = to_check->next;
        }
        return *this;
    }
    void print_unique_elems(){
        
    }
	LinkedList& reverse(){
		if (!head) return *this;
		Node *prev= NULL;
		Node *curr = head;
		Node *next = curr->next;
		while(curr!=NULL){
			next = curr->next;
			curr->next=prev;
			prev = curr;
			curr = next;
		}
		head = prev;
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
	l1.addNodeAtEnd(200);
	l1.addNodeAtEnd(2);
    l1.addNodeAtEnd(10);
    l1.addNodeAtEnd(30);
    l1.addNodeAtEnd(5);
    l1.addNodeAtEnd(100);
	l1.show();
    l1.bubble_sort();
    l1.show();
	l1.reverse();
	l1.show();
	return 0;
}
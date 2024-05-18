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

    LinkedList& split_even(){
        Node *t = head;
        while(t->next!=NULL){
            if (t->next->data %2 == 0){
                int splitted = t->next->data/2;
                int split1,split2 = 0;
                if (splitted%2==0){
                    split1 = splitted+1;
                    split2 = splitted-1;
                }
                else{
                    
                    split1=split2=splitted;
                }
                Node *n1 = new Node(split1);
                Node *n2 = new Node(split2);
                Node *temp = t->next->next;
                delete t->next;
                t->next = n1;
                n1->next=n2;
                n2->next = temp;
            }
            else{
                t=t->next;
            }
        }
        return *this;
    }
    LinkedList& merge_elems(){
		Node *dummy=new Node(NULL);
		dummy->next=head;
        Node *runner = head;
        Node *curr = dummy;

        while(curr && runner && runner->next){
            if (runner->data<=50){

				int sum=0;
                do 
                {
					sum += runner->data;
					Node *temp= runner->next;
					delete runner;
                    runner= temp;
					curr->next = runner;

                }
				while (runner!=NULL  && (runner->data<=50 || sum<=50));
				curr->next=new Node(sum);
				curr->next->next = runner;
				if (runner && runner->next) runner=runner->next;	

            }
			else{
				if (curr->data==NULL)
				curr = curr->next;
				runner = runner->next;
			}
        }
		if (curr->data==NULL)
			curr=curr->next;
		head=curr;
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
    l1.addNodeAtEnd(10);
    l1.addNodeAtEnd(30);
    l1.addNodeAtEnd(5);
    l1.addNodeAtEnd(100);
	l1.show();
    l1.merge_elems();
    l1.show();
	return 0;
}
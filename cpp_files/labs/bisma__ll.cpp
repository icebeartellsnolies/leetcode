#include <iostream>
#include "Node.cpp"
	
using namespace std;

class LinkedList{
	Node *head;
public:
	LinkedList(){	head = NULL;	}
	LinkedList& addNodeAtStart(int d){
		head = new Node(d, head);//In Node constructor either next will point to NULL or some node previously pointed by head
		return *this;
	}
	LinkedList& addNodeAtEnd(int d){
		if (!head)
			head =new Node(d);
		else{
			Node *t;
			for (t = head ; t -> next != NULL ; t = t -> next);
			t -> next = new Node (d);
		}
		return *this;
	}
	LinkedList& deleteNodeFromStart(){
		if (head!=NULL){
			Node *t = head;
			head = head -> next;
			delete t;
		}
		return *this;
	}
	LinkedList& insertafter(int key,int element){
		Node *t=head;
		while (t!=NULL){
			if (t->data==key){
				Node* newnode=new Node(element);
				newnode->next=t->next;
				t->next=newnode;
				break;
			}
			t=t->next;
		}
	return *this;
	}
	LinkedList& insertbefore(int key,int element){
		Node *t=head;
		if (t->data==key && t!=NULL){
			Node* newnode=new Node(element);
			newnode->next=head;
			head=newnode;
		}
		else{
		while (t!=NULL && t->next!=NULL){
			if (t->next->data==key){
				Node* newnode=new Node(element);
				newnode->next=t->next;
				t->next=newnode;
				break;
			}
			t=t->next;
		}
		}
		return *this;
	}
	LinkedList& reverselist(){
		Node*current=head;
		Node *next=NULL;
		Node *previous=NULL;
    
    while (current!=NULL){
		next=current->next;
		current->next=previous;
		previous=current;
		current=next;	

	}
	head=previous;
	return *this;
}
LinkedList& removeafter(int key){
	Node* t=head;
	while(t!=NULL){
		if (t->data==key && t->next!=NULL){
			Node* temp=t->next;
			t->next=t->next->next;
			delete temp;
		}
		t=t->next;
	}
	return *this;
}
LinkedList& removebefore(int key){
	Node *t=head;
	if (t->data==key){
		return *this;
	}
	while (t!=NULL){
		if(t->next->data==key){
			Node* temp=t;
			t->next=t->next->next;
			delete temp;
			break;
		}
		t=t->next;
	}
	return *this;
}
LinkedList& combinelist(LinkedList& list){
	Node* t=head;
	for(;t->next!=NULL;t=t->next);
	
	t->next=list.head;
	list.head=NULL;
	return *this;

}
LinkedList& removeelements(int val){
	while (head!=NULL && head->data==val){
		head=head->next;
	}
	if (head){
	Node* p =head;
	Node* q =head->next;
	while (q!=NULL){
		if (q->data==val){
			Node* temp=q;
			p->next=q->next;
			delete temp;
		}
		p=p->next;
		q=p->next;		
	}
	return *this;
}


}
	LinkedList& deleteNodeFromEnd(){
		if (!head)	return *this;	//there is no node to delete
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
	LinkedList& addinorder(int  d){
		Node *t=head;
		for (; t->next!=NULL;t=t->next){
			if (t->data>=d){
				Node *temp=t->next;
				t->next=new Node (d);
				t->next->next=temp;
				break;}
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
// LinkedList& removeduplicates(){
// 	Node *t=head;
// 	int d;
// 	bool isduplicate=false;
// 	while (t!=NULL){
// 		Node* t1=t->next;
// 		while (t1!=NULL){
// 			if (t->data==t1->data){
// 				isduplicate=true;
// 				d=t->data;
// 				break;
// 			}
// 			else t1=t1->next;
// 		}
// 		if (isduplicate){
// 		Node *t=head;
// 		while (t!=NULL){
// 			if (d==head->data){
// 				Node *temp=head;
// 				head=head->next;
// 				delete temp;
// 			}
// 			if (t->data==d){
// 				Node* temp=t;
// 				t=t->next;
// 				delete temp;
// 			}
// 			else
// 			t=t->next;
// 		}
// 	}
// 	else
// 	t=t->next;
// }
// return *this;
// }
LinkedList& removeduplicates(){
        Node *t=head;
        Node *prev=NULL;
		while(t!=NULL){
			bool isduplicate=false;
			Node *t1=t;
			while(t1!=NULL && t1->next!=NULL){
				if (t1->next->data==t->data){
					Node *todelete=t1->next;
					t1->next=t1->next->next;
					delete todelete;
					isduplicate=true;
				}
				else{
				t1=t1->next;
			}
			}
			if (isduplicate){
				if (prev==NULL){
					Node* todelete=t;
					head=t->next;
					delete todelete;
					t=head;
				}
				else{
				Node *todelete=t;
				prev->next=t->next;
				delete todelete;
				t=prev->next;
			}
			}
			else{
				
			prev=t;
			t=t->next;
			}
		} 
		return *this;  
    }
	

LinkedList& splitevenelements(){
		Node *t=head;
		while (t!=NULL){
			if (t ->data%2==0){
				int d1=t ->data/2;
				int d2=t ->data/2;
				if (d1%2==0){
					d1=d1-1;
					d2+=1;
					
				}
				Node * newnode=new Node(d2);
				t ->data=d1;
				newnode ->next=t ->next;
				t ->next=newnode;
				t=newnode;
				

	}
	t=t ->next;

	}
		return *this;
	}
	LinkedList& mergeelements(){
		Node *t=head;
		while (t!=NULL && t ->next!=NULL){
			if (t ->data<50 && t ->next ->data<50){
				t ->data+=t ->next ->data;
				Node *temp=t ->next;
				t ->next=t ->next ->next;
				delete temp;
			}
			else
			t=t ->next;
		}
		return *this;
	}
	void show(){
		for ( Node *t = head ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}
};

int main(){
    LinkedList l1;
    l1.addNodeAtStart( 2);
    l1.addNodeAtStart( 3);
    l1.addNodeAtStart( 1);
    // l1.addNodeAtStart( 0);
    // l1.addNodeAtStart( 0);
    // l1.addNodeAtStart( 0);
    // l1.addNodeAtStart( 0);
	l1.addNodeAtStart(20);
    l1.addNodeAtStart( 2);
    l1.addNodeAtStart(10);
	l1.addNodeAtStart(20);
	l1.addNodeAtStart(20);
    l1.addNodeAtStart(2);
    l1.show();
	// l1.removeduplicates();
	l1.mergeelements();
	l1.show();
}
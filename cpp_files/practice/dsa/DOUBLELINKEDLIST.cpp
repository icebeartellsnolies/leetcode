#include<iostream>
#include "dnode.cpp"
using namespace std;

class LinkedList{
public:
      DNode* head;
      DNode* tail;
    LinkedList(){ 
      head=NULL;
      tail=NULL;}
      LinkedList& addnodeatstart(int d){
        DNode *newnode=new DNode(d,head);
        if (!head && !tail){
        tail=head=newnode;}
        else{
            newnode->prev=NULL;
            newnode->next=head;
            head=newnode;
        }
        return *this; 
      }
      LinkedList& addnodeatend(int d){
        DNode *newnode=new DNode(d);
        if (!head && !tail){
          head=tail=newnode;
        }
        else if (head!=NULL && tail!=NULL){
          tail->next=newnode;
          newnode->prev = tail;
          tail=newnode;
        }
        else{
          head->next = newnode;
          newnode->prev = head;
        }
    return *this;
    }
    LinkedList& deletenodefromstart(){
		if (!head)
		return *this;
		else if (head==tail){
		delete head;
		head=tail=NULL;
		}
		else{
		DNode *temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
		}
  	return *this; 
}
LinkedList& reverselist(){
    DNode *prev = NULL;
    DNode* next=NULL;
    DNode *current=head;
    while (current != NULL){
        next = current->next;
        current->next=prev;
        current->prev=next;
        prev=current;
        current=next;      
}
head=prev;
return *this;
}
	LinkedList& reverse(){
		if (!head) return *this;
		DNode *curr = head;
		DNode *next = curr->next;
		while(curr!=NULL){
			next = curr->next;
			curr->next = curr->prev;
			curr->prev = next;
			curr = next;
		}
		// DNode *temp = head;
		head = tail;
		tail = curr;
		return *this;
	}
LinkedList& combineNodes(){
	DNode *t=head;
	while(t!=NULL && t->next!=NULL){
		if (t->data<50 && t->next->data<50){
			DNode *todelete=t->next;
			t->data=t->data+t->next->data;
			t->next=todelete->next;
			if (todelete->next!=NULL)
			todelete->next->prev=t;
			delete todelete;
		}
		else{
			t=t->next;
		}
	}
	return *this;
}
LinkedList& shufflemerge(LinkedList& list){
	DNode *t=head;
	DNode *t1=list.head;
	DNode *temp;
	while (t!=NULL && t1!=NULL){
		if (t->next)
		temp=t->next;
		else{
			t->next=t1;
			t1->prev=t;
			break;
		}
		t->next=t1;
		t1->prev=t;
		t=t->next;
		t1=t1->next;
		t->next=temp;
		
		temp->prev=t;
		t=t->next;
	}
return *this;
}
	LinkedList& deletenodefromend(){
		if (!head)
		return *this;
		else if (head ==tail){
		delete head;
		head=tail=NULL;
		}
		else{
		DNode* temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete temp;
		}
		return *this;
	}
	LinkedList& del_dups(){
		if(!head) return *this;
		DNode *curr = head;
		DNode *runner = head->next;
		while(curr!=NULL){
			runner=curr->next;
			while(runner!=NULL){
				if(curr->data == runner->data){
					DNode *temp=runner;
					runner = runner->next;
                    if (temp->prev)
					runner->prev=temp->prev;
                    else 
                    runner->prev=NULL;
					delete temp;
				}
				runner = runner->next;
			}
			curr= curr->next;
		}
		return *this;
	}
  void show(){
		for ( DNode *t = head ; t != NULL ; t = t -> next )
		cout << t -> data << ' ';
		cout << '\n' ;
	}
};
int main(){
	LinkedList l1;
	// l1.addnodeatstart(3);
	l1.addnodeatend(4);
	l1.addnodeatstart(5);
	l1.addnodeatend(10);
	l1.addnodeatend(6);
	l1.addnodeatend(10);
	
	l1.addnodeatend(8);
	l1.addnodeatend(10);
	l1.addnodeatend(6);
	l1.addnodeatend(10);
	
	l1.addnodeatend(8);
	l1.addnodeatend(10);
	l1.addnodeatend(6);
	l1.addnodeatend(10);
	
	l1.addnodeatend(8);
	l1.show();
	// l1.reverse();
	// l1.show();
    l1.del_dups().show();
    // l1.reverselist().show();
	// LinkedList l;
	// l.addnodeatend(10);
	
	// l.addnodeatend(4);
	// l.addnodeatstart(5);
	// l.addnodeatend(10);
	// l.addnodeatend(6);
	// l.addnodeatend(10);
	// l.addnodeatend(8);
	// l.addnodeatend(10);

	return 0;
}
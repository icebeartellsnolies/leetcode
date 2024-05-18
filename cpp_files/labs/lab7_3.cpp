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
					runner = runner->prev;
					runner->next=temp->next;
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
	l1.addnodeatend(4);
	
	l1.addnodeatend(5);
	l1.addnodeatend(5);
	
	l1.addnodeatend(10);
	l1.addnodeatend(6);
	l1.addnodeatend(10);
	// l1.addnodeatstart(7);
	l1.addnodeatend(8);
	// l1.addnodeatstart(9);
	l1.addnodeatend(8);
	l1.show();
	// l1.deletenodefromstart();
	// l1.deletenodefromend();
	// l1.show();
	l1.del_dups();
	l1.show();
	return 0;
}
#include <iostream>

using namespace std;

//Double Header Circular Linked List
template <typename type>
class DHCLinkedList{
	//template <typename type>
	class DNode{			//This is an inner class implementation available for this outer class only
		public:
			type val;
			DNode *next, *prev;
			DNode(type v, DNode *n = NULL, DNode *p = NULL){
				val = v;
				next = n;
				prev = p;
			}
	};
	DNode *head;
public:
	DHCLinkedList(){	head = new DNode(0);	head->next = head->prev = head;	}//I have taken first node as int; where other nodes may have different type
	//return the data of the first element, if exist
	type front(){
		if (head->next == head)	throw ("NONODE");
		return head->next->val;
	}
	//return the data of the last element, if exist
	type back(){
		if (head->prev == head)	throw ("NONODE");
		return head->prev->val;
	}
	//Add element at head
	void push_front(const type& d){
		head->next = new DNode(d, head->next, head);
		head->next->next->prev = head->next;
	}
	//Add element at tail
	void push_back(const type& d){
		head->prev = new DNode(d, head, head->prev);
		head->prev->prev->next = head->prev;
	}
	//remove front or first node, if exist
	void pop_front(){
		if (head->next != head){
			head -> next = head -> next -> next;
			delete head -> next -> prev;
			head->next->prev = head;
		}
	}
	DHCLinkedList&  insert_after(const type& key,const type& value){
		DNode* temp = head->next;
		while(temp != head){
			if (temp->val==key){
				DNode * temp1=new DNode (value,temp->next,temp);
				temp->next->prev=temp1;
				temp->next=temp1;
				return *this;
			}
			temp=temp->next;
	}
    throw("Key not found");
	}
    DHCLinkedList&  insert_before(const type& key,const type& value){
		DNode* curr = head->next;
		while(curr != head){
			if (curr->val==key){
				DNode *temp = curr->prev;
				DNode * added_node=new DNode (value,curr);
				added_node->prev = temp;
				curr->prev = added_node;
				temp->next = added_node;
				
			}
			curr=curr->next;
	}
	// else
    // 	throw("Key not found");
	return *this;
	}
    DHCLinkedList& removekthnode(int k){
        DNode *temp=head->next;
        int count=1;
        while (temp!=head){
            if (count==k){
                DNode *todelete=temp;
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                delete todelete;
                return *this;
            }
            count++;
            temp=temp->next;
        }

        return *this;
    }
	//remove tail or last node, if exist
	void pop_back(){
		if (head->prev != head){
			head -> prev = head -> prev -> prev;
			delete head -> prev -> next;
			head->prev->next = head;
		}
	}
	void show() const{
		for (DNode *temp = head->next ; temp != head ; temp = temp -> next)
			cout << temp->val << ' ';
		cout << '\n';
	}
	bool haveNodes() const{	return head->next != head;}
};

int main(){
	DHCLinkedList<int> list;
	list.push_front(23);
	list.push_front(13);
	list.push_front(53);
    	
	list.show();
	list.push_back(20);
	list.push_back(30);
	list.push_back(50);	
    // list.removekthnode(2);
	// list.insert_after(23,90);
	// list.show();
	// while (list.haveNodes()){
	// 	cout << list.front() << '\n';
	// 	list.pop_front();
	// }
	// list.push_front(23);
	// list.push_front(13);
	// list.push_front(53);	
	// list.show();
	// list.push_back(20);
	// list.push_back(30);
	// list.push_back(50);	
	// list.show();
	// while (list.haveNodes()){
	// 	cout << list.back() << '\n';
	// 	list.pop_back();
	// }
	list.show();
	list.insert_before(13,100);
	list.show();
	return 0;
}

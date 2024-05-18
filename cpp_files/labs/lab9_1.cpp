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
	DHCLinkedList(){	head = new DNode(0);	
	head->next = head->prev = head;	}//I have taken first node as int; where other nodes may
	// have different type return the data of the first element, if exist
	type front(){
		if (head->next == head)	throw ("NO NODE");
		return head->next->val;
	}
	//return the data of the last element, if exist
	type back(){
		if (head->prev == head)	throw ("NO NODE");
		return head->prev->val;
	}
	//Add element at head
	void push_front(const type& d){
		head->next = new DNode(d, head->next, head);
		head->next->next->prev = head->next;
	}
	//Add element at tail
	void push_back(const type& d){
		//tail = head->prev
		head->prev = new DNode(d, head, head->prev);
		// head->prev->prev: the old prev. not the new one
		head->prev->prev->next = head->prev;
	}
	//remove front or first node, if exist
	void pop_front(){
		if (head->next != head){
			head -> next = head -> next -> next;
			delete head -> next -> prev;
			head->next->prev = head;
		}
		else throw("the queue is empty");
	}
	//remove tail or last node, if exist
	void pop_back(){
		if (head->prev != head){
			head -> prev = head -> prev -> prev;
			delete head -> prev -> next;
			head->prev->next = head;
		}
		else throw("the queue is empty");
	}
	void show() const{
		for (DNode *temp = head->next ; temp != head ; temp = temp -> next)
			cout << temp->val << ' ';
		cout << '\n';
	}
	bool haveNodes() const{	return head->next != head;}
	
	int size_of_dhcll(){
		int count=0;
		for (DNode *temp=head->next; temp!=head; temp=temp->next)
			count++;
		return count;
	}

	bool is_empty(){
		int ll_size=size_of_dhcll();
		if (ll_size==0) return true;
		else return false;
	}

	DHCLinkedList clear(){
		if (haveNodes()){
			for(DNode *curr=head->next; curr!=head; curr=curr->next){
				DNode *temp=curr;
				curr=curr->next;
				delete temp;
			}
		}
		else{
			throw("queue already empty");
		}	
	}	
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
	list.show();
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
	cout<<"the size of queue is: "<<list.size_of_dhcll()<<endl;
	cout<<"is empty?: "<<list.is_empty();
	
	return 0;

}

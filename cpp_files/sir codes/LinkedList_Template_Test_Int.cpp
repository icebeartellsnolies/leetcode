#include <iostream>
#include "LinkedList_Template.cpp"
	
//using namespace std;

int main(){
	LinkedList<int> list;
	list.addNodeAtStart(23);
	list.addNodeAtStart(31);
	list.addNodeAtEnd(45);
	list.addNodeAtEnd(13).show();
	list.addNodeAtStart(11);
	list.addNodeAtEnd(63).show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromStart().show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromEnd().show();
	list.addNodeAtEnd(13).show();
	list.addNodeAtStart(21);
	list.addNodeAtEnd(36).show();
	return 0;
}

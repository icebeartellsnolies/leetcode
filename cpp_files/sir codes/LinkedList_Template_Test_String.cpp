#include <iostream>
#include "LinkedList_Template.cpp"
	
//using namespace std;

int main(){
	LinkedList<string> list;
	list.addNodeAtStart("Python");
	list.addNodeAtStart("JAVA");
	list.addNodeAtEnd("CSharp");
	list.addNodeAtEnd("C++").show();;
	list.addNodeAtStart("JavaScript");
	list.addNodeAtEnd("COBOL").show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromStart().show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromEnd().show();
	list.deleteNodeFromEnd().show();
	list.addNodeAtEnd("SQL").show();
	list.addNodeAtStart("PHP");
	list.addNodeAtEnd("Swift").show();
	return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

class Bag{
	int *elements;
	int cSize, size;
	// Bag& is the return type meaning that the function will return an obj of type bag
	Bag& copy(const Bag& b){
		size = b.size;
		cSize = b.cSize;
		elements = new int[size];
		for (int i = 0 ; i < cSize ; i++)
			elements[i] = b.elements[i];
		return *this; // added line; not in sir's code
	}
public:
	Bag(int size = 10){	
		this->size = size;	//use of this pointer
		cSize = 0;
		elements = new int[size];
	}
	Bag(const Bag& b){
		copy(b);
	}
	Bag& operator =(const Bag& b){
		delete []elements;
		copy(b);
		return *this; // added line; not in sir's code
	}
	~Bag(){	delete []elements;	}	//Destructor
	Bag& addElement(const int ELEMENT){
		if (cSize < size)
			elements[cSize++] = ELEMENT;
		return *this; 
	}
	Bag& modify(const int& ELEMENT, const int& index){
		if (index < cSize)
			elements[index] = ELEMENT;
		return *this;
	}
	void show() const{	
		for (int i=0 ; i < cSize; i++)
			cout << elements[i] << ' ';
		cout << '\n';
	}
};
int main(){
	Bag bag1;
	bag1.addElement(23);
	bag1.addElement(18);
	bag1.addElement(34).show();
	Bag bag2 = bag1;
	bag2.show();
	bag2.modify(20, 1);
	bag2.modify(30, 2).show();
	bag1.show();
	bag1 = bag2;		//Again Shallow Copy
	bag1.modify(50, 2);
	bag2.show();
	return 0;
}

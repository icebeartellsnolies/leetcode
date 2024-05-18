// NOTE: why is elements dynamic with new int?
// it is because you cant make a copy of a static array! since arrays are actually just pointers where 
// the name of array is actually a pointer of array's first element therefore we cant use assignment
// operator to make a copy of one array to another.
// but DYNAMIC ARRAY can be copied from one to another using assignment operator but it makes a shallow
// copy like this. WHY? because the pointer which points to array's first element i.e its name , that
// pointer's copy is made and the copy var is assigned a copy of that pointer. since it is not a new
// pointer but the same old one so changes in one reflect in another
#include <iostream>
#include <fstream>

using namespace std;

class Bag{
	int *elements;
	int cSize, size;
public:
	Bag(int size = 10){	
		this->size = size;	//use of this pointer
		cSize = 0;  // current size i.e number of elements in the bag
		elements = new int[size];
	}
	Bag& addElement(const int ELEMENT){
		if (cSize < size)
			elements[cSize++] = ELEMENT;
		return *this;
	}
	// const says that its read only. a const element's value cant be modified once set
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
	return 0;
}

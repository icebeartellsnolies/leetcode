#include <iostream>

using namespace std;

#define SEN 0

void preOrder(const char *x, int i, const int& END){
	if (i >= END || x[i] == SEN)	return;
	cout << x[i] << ' '; //parent
	preOrder(x, i * 2, 14);
	// preOrder(x, i * 2, 14):gives the left node
	preOrder(x, i * 2 + 1, 14);
	// preOrder(x, i * 2 + 1, 14):gives the right node
}

void inOrder(const char *x, int i, const int& END){
	if (i >= END || x[i] == SEN)	return;
	inOrder(x, i * 2, 14);
	cout << x[i] << ' ';
	inOrder(x, i * 2 + 1, 14);
}

void postOrder(const char *x, int i, const int& END){
	if (i >= END || x[i] == SEN)	return;
	postOrder(x, i * 2, 14);
	postOrder(x, i * 2 + 1, 14);
	cout << x[i] << ' ';
}

int main(){
	char x[] = {SEN,'a','b','c','d','e','f',SEN, SEN, 'g','h',SEN,'i','j'};
	cout << "Pre Order: ";
	preOrder(x, 1, 14);
	cout << "\nIn Order: ";
	inOrder(x, 1, 14);
	cout << "\nPost Order: ";
	postOrder(x, 1, 14);
	return 0;
}

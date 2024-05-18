#include <iostream>

using namespace std;

int main(){  
	int x = 23, y = 45, *a = &x;
	cout << "X: " << x << " Y: " << y << '\n';
	cout << "Address of X: " << &x << " Value of pointer: " << a << '\n';
	cout << "Value of X using pointer: " << *a << '\n';
	a = &y;
	cout << "Value of Y using pointer: " << *a << '\n';
	return 0;
}
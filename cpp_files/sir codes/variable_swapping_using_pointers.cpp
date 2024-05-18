#include <iostream>

using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){  
	int x = 23, y = 45, *a = &x;
	cout << "X: " << x << " Y: " << y << '\n';
	// if address of x and y is not passed to swap function then swapped elements wont be available in main 
	// if they arent stored in any variable in main just like py
	swap(&x, &y);
	cout << "X: " << x << " Y: " << y << '\n';
	return 0;
}
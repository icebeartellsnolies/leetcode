#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int a[], int size){
	for (int i = 0 ; i < size ; i++)
		cout << a[i] << ' ';
	cout << '\n';

}
int main(){  
	srand(time(0));
	int *x = new int[10], i;
	for (i = 0 ; i < 10 ; i++)
		x[i] = rand();
	printArray(x, 10);
	int *t = new int[20];
	for (i = 0 ; i < 10 ; i++)
		t[i] = x[i];
	delete []x;
	x = t;
	for (i = 10 ; i < 20 ; i++)
		x[i] = rand();
	printArray(x, 20);
	delete []x;
	return 0;
}
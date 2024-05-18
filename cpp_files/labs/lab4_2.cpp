#include <iostream>
#include<ctime>
using namespace std;

int main() {
	int indexes[10];
	for (int i = 1; i < 11; i++) {
		indexes[i- 1] = i;
	}
	cout << "original array: ";
	int random_arr[10];
	for (int i = 0; i < 10; i++) {
		random_arr[i] = rand()%100;
		cout << random_arr[i] << " ";
		
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (random_arr[i] < random_arr[j]) {
				int temp = random_arr[i];
				random_arr[i] = random_arr[j];
				random_arr[j] = temp;
				int another = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = another;
			}
		}
	}
	cout << "\n";
	cout << "sorted array: ";
	for (int i = 0; i < 10; i++) {
		cout << random_arr[i] << " ";
	}
	
	for (int i = 0; i < 10; i++) {
		cout << "\n";
		cout << random_arr[i] << " at position " << indexes[i];
	}
	return 0;
}
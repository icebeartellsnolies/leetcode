#include <iostream>
using namespace std;

int main() {
	int arr_1[10];
	int arr_2[10];
	int prev_a = 0;
	int prev_b = 0;
	for (int i = 0; i < 10; i++) {

		arr_1[i] = (rand() % 5 + prev_a);
		arr_2[i] = (rand() % 5 + prev_b);
		prev_a = arr_1[i];
		prev_b = arr_2[i];

	}
	for (int i = 0; i < 10; i++) {
		cout << arr_1[i] << " ";

	}
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout << arr_2[i] << " ";

	}
	int sorted_arr[20];
	int pt_1 = 0;
	int pt_2 = 0;
	int i = 0;
	while (pt_1 < 10 && pt_2 < 10) {
		if (arr_1[pt_1] < arr_2[pt_2]) {
			sorted_arr[i] = arr_1[pt_1];
			pt_1++;
		}
		else {
			sorted_arr[i] = arr_2[pt_2];
			pt_2++;
		}

		i++;
		
	}
	while (pt_1 < 10) {
		sorted_arr[i] = arr_1[pt_1];
		i++;
		pt_1++;
	}
	while(pt_2<10) {
		sorted_arr[i] = arr_2[pt_2];
		i++;
		pt_2++;
	}
	cout << "\n";
	for (int i = 0; i < 20; i++) {
		cout << sorted_arr[i] << " ";
	}
}
//void generate_arrays() {
//	int arr_1[10];
//	int arr_2[10];
//	int prev_a = 0;
//	int prev_b = 0;
//	for (int i = 0; i < 10; i++) {
//		
//		arr_1[i] = (rand() % 5 + prev_a);
//		arr_2[i] = (rand() % 5 + prev_b);
//		prev_a = arr_1[i];
//		prev_b = arr_2[i];
//
//	}
//	for (int i = 0; i < 10; i++) {
//		cout << arr_1[i] << " ";
//
//	}
//	cout << "\n";
//	for (int i = 0; i < 10; i++) {
//		cout << arr_2[i] << " ";
//
//	}
//	
//	
//}
//
//int main() {
//	generate_arrays();
//	return 0;
//}
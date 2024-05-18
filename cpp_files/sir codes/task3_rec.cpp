#include <iostream>
#include <vector>

using namespace std;

int vESumNegativeOne (vector<int>& v, int i){
	if (i == v.size())	return -1;
	int sum = vESumNegativeOne(v, i+1);
	if (v[i] % 2) return sum;
	if (sum == -1)	return v[i];
	return v[i] + sum;
}
//The function will return -1 if there is no even value
int vESumNegativeOne (vector<int>& v){
	return vESumNegativeOne(v, 0);
}
int main(){
	// vector<int> v1 = {2,3,1,4,6,9};
	// cout << vESumNegativeOne(v1) << '\n';
	vector<int> v2 = {3,1,9,5};
	cout << vESumNegativeOne(v2) << '\n';
	return 0;
}
// this code calculats the sum of even numbers in an array. if there is no even element then returns -1
#include <iostream>
#include <vector>

using namespace std;

int vESumNegativeOne(int arr[], int size, int i) {
    if (i == size) return -1;
    int sum = vESumNegativeOne(arr, size, i + 1);
    if (arr[i] % 2) 
		return sum;
    if (sum == -1) 
		return arr[i];
    return arr[i] + sum;
}

// Overloaded function to start recursion from index 0
int vESumNegativeOne(int arr[], int size) {
    return vESumNegativeOne(arr, size, 0);
}

int main() {
//     int arr1[] = {2, 3, 1, 4, 6, 9};
//     int size1 = sizeof(arr1) / sizeof(arr1[0]);
//     cout << vESumNegativeOne(arr1, size1) << '\n';

    int arr2[] = {3, 2, 9, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << vESumNegativeOne(arr2, size2) << '\n';

    return 0;
}

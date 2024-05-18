// #include <iostream>
// #include <vector>

// using namespace std;

// bool targetSum(vector<int>& v, const int& TSUM, int cSum, int i){
// 	if (TSUM == cSum)	return true;
// 	if (TSUM < cSum)	return false;
// 	if (i == v.size())	return false;
// 	bool isFound = targetSum(v, TSUM, cSum + v[i], i+ 1);
// 	if (isFound)	return true;
// 	return targetSum(v, TSUM, cSum, i + 1);
// }
// bool targetSum(vector<int>& v, const int& TSUM){
// 	return targetSum(v, TSUM, 0, 0);
// }
// int main(){
// 	vector<int> v1 = {72,23,31,44,56,69,72,83,91,84,76,69,52,43,31,94,86,93};
// 	for (int i = 106 ; i < 138 ; i++)
// 		cout << i << '\t' << targetSum(v1, i) << '\n';
// 	return 0;
// }

#include <iostream>

using namespace std;

bool targetSum(int v[], int size, const int& TSUM, int cSum, int i) {
	if (TSUM == cSum) return true;
	if (TSUM < cSum) return false;
	if (i == size) return false;
	
	bool isFound = targetSum(v, size, TSUM, cSum + v[i], i + 1);
	if (isFound) return true;
	
	return targetSum(v, size, TSUM, cSum, i + 1);
}

bool targetSum(int v[], int size, const int& TSUM) {
	return targetSum(v, size, TSUM, 0, 0);
}

int main() {
	int v1[] = {72, 23, 31, 44, 56, 69, 72, 83, 91, 84, 76, 69, 52, 43, 31, 94, 86, 93};
	int size = sizeof(v1) / sizeof(v1[0]);
	
	for (int i = 106; i < 138; i++) {
		cout << i << '\t' << targetSum(v1, size, i) << '\n';
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool ternarySearch(vector<int>& v, const int& TARGET, int start, int end){
	if (start > end)	return false;
	int p1 = start + (end - start) / 3;
	int p2 = start + (end - start) / 3 * 2;
	if (v[p1] == TARGET)	return true;
	if (v[p2] == TARGET)	return true;
	bool isFound = ternarySearch(v, TARGET, start, p1 - 1);
	if (isFound)	return true;
	isFound = ternarySearch(v, TARGET, p1 + 1, p2 - 1);
	if (isFound)	return true;
	return ternarySearch(v, TARGET, p2 + 1, end);
}

bool ternarySearch(vector<int>& v, const int& TARGET){
	return ternarySearch(v, TARGET, 0, v.size() - 1);
}
int main(){
	vector<int> v1 = {12,23,31,44,56,69,72,83,91,84,76,69,52,43,31,24,16,9};
	cout << ternarySearch(v1, 31) << '\n';
	cout << ternarySearch(v1, 85) << '\n';
	return 0;
}
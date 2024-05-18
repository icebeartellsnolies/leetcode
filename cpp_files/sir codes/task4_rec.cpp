#include <iostream>
#include <vector>

using namespace std;

bool linearSearch(vector<int>& v, const int& TARGET, int i){
	if (i == v.size())	return false;
	if (v[i] == TARGET)	return true;
	return linearSearch(v, TARGET, i + 1);
}
bool linearSearch(vector<int>& v, const int& TARGET){
	return linearSearch(v, TARGET, 0);
}
int main(){
	vector<int> v1 = {2,3,1,4,6,9};
	cout << linearSearch(v1, 6) << '\n';
	cout << linearSearch(v1, 5) << '\n';
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int vSum (vector<int>& v, int i){
	if (i == v.size())	return 0;
	return v[i] + vSum(v, i+1);
}
int vSum (vector<int>& v){
	return vSum(v, 0);
}
int main(){
	vector<int> v = {2,3,1,4,6,9};
	cout << vSum(v) << '\n';
	return 0;
}
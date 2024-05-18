#include <iostream>
#include <vector>

using namespace std;

// int vESum (vector<int>& v, int i){
// 	if (i == v.size())	return 0;
// 	int sum = vESum(v, i+1);
// 	if (v[i] % 2) return sum;
// 	return v[i] + sum;
// }
// int vESum (vector<int>& v){
// 	return vESum(v, 0);
// }
// int main(){
// 	vector<int> v = {2,3,1,4,6,9};
// 	cout << vESum(v) << '\n';
// 	return 0;
// }

// // same code with array:

// int vESum (int arr[], int i, int size){
// 	if (i == size)	return 0;
// 	int sum = vESum(arr, i+1, size);
// 	if (arr[i] % 2) return sum;
// 	return arr[i] + sum;
// }
// int vESum (int arr[],int size){
// 	return vESum(arr, 0, size);
// }
// int main(){
// 	const int size = 6;
// 	int arr[size] = {2,3,1,4,6,9};
// 	cout << vESum(arr, size) << '\n';
// 	return 0;
// }

// int evensum(vector<int> v,int i,int sum){
//     if (i==v.size()) return 0;
//     if(v[i]%2==0){
//         sum+=v[i]+evensum(v,i+1,sum);
//     }
//     else
//     sum+=evensum(v,i+1,sum);
// return sum;
// }
int evensum(vector<int> v,int i){
	if (i==v.size()) return 0;
	return (v[i]%2==0? v[i]:0)+evensum(v,i+1);
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6}; // Sample vector with numbers
    int result = evensum(v, 0);      // Call evensum with starting index 0 and sum 0
    cout << "Sum of even numbers: " << result << endl;
    return 0;
}
#include<iostream>
using namespace std;

int cumulative_sum(int n){
    int sum=n;
    if(n==0){
        // cout<<sum;
        return sum;
    }    
    
    sum=n+cumulative_sum(n-1);
    cout<<sum<<endl;
    return sum;
}

int main(){
    cumulative_sum(5);
    return 0;
}

// arooj's
// void printSumHelper(int n, int s, int i) {
//     if (i > n) return; 
//     s += i;
//     cout << s << "\n";
//     printSumHelper(n, s, i + 1); 
// }
// void printSum(int n){
// 	printSumHelper(n, 0, 1);
// }
// int main() {
//     printSum(6);
//     return 0;
// }
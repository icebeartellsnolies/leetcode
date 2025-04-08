#include <iostream>
#include <queue>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
int minimumOperations(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int n:nums){
        if (n!=0)
            min_heap.push(n);
    }
    bool all_zeros=false;
    int count=0;
    while (!all_zeros){
        int num = min_heap.top();
        min_heap.pop();
        int zero=0;
        for(int i=0; i<min_heap.size();i++){
            int to_subtract = min_heap.top();
            min_heap.pop();
            to_subtract=to_subtract-num;
            if (to_subtract==0)
                zero++;
            min_heap.push(to_subtract);
        }
        count++;
        if (zero==nums.size())
            all_zeros=true;
        
    }
    return count;
}

int main(){
    vector<int> v={1,5,0,3,5};
    int a = minimumOperations(v);
    cout<<a;
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& s) {
    // Create a priority queue from vector as max heap (default)
    priority_queue<int> pq(s.begin(), s.end());  
    
    // to create min heap:              
    // priority_queue<int, vector<int>, greater<int>> pq(s.begin(), s.end());
    int x, y;
    while (pq.size() > 1){
        y = pq.top();          
        pq.pop();
        x = pq.top();            
        pq.pop();
        if (x != y)     pq.push(y - x);
    }
    if (pq.size() == 0) return 0;
    return pq.top();
    }
int main(){
    return 0;
}

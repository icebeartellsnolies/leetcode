#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int fillCups(vector<int>& amount) {
    priority_queue<int> pq(amount.begin(), amount.end());
    int moves=0;
    while(pq.top()!=0){
        int n1=pq.top();
        pq.pop();
        n1--;
        moves++;
        
        if(pq.top()!=0){
            int n2=pq.top();
            pq.pop();
            n2--;
            pq.push(n2);
        }
        
        pq.push(n1);
    }
    return moves;
}
int main(){
    vector<int> v={1,4,2};
    int m = fillCups(v);
    cout<< m;
    return 0;
}
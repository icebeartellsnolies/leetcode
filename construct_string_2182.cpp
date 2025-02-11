#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
string repeatLimitedString(string s, int repeatLimit){

    vector<pair<int,int>> freq(26,pair<int,int>(0,0));
    for(int i=0;i<s.size();i++){
        freq[abs(s[i]-122)].first = s[i];
        freq[abs(s[i]-122)].second++;
    }
    priority_queue<pair<int, int>> max_heap;

    for(auto&pair:freq){
        max_heap.push(pair);
    }
    string ans="";
    while(!max_heap.empty()){

        char chr = max_heap.top().first;
        int f = max_heap.top().second;
        max_heap.pop();
        if (f>repeatLimit){
            int remaining = f-repeatLimit;
            for(int i=0;i<repeatLimit;i++){
                ans+=chr;
            }
            if(!max_heap.empty()){
                char another = max_heap.top().first;
                int f2 = max_heap.top().second;
                max_heap.pop();
                ans+=another;
                max_heap.push({another,f2-1});
            }
            max_heap.push({chr,remaining});
        }

        else{
            for(int i=0;i<f;i++){
                ans+=chr;
            }
        }
    }
    return ans;
}

int main(){
    // string s="cczazcc";
    string s="aababab";
    string a = repeatLimitedString(s,2);
    cout<<a<<endl;
    return 0;
}
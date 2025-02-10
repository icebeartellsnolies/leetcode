#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int> > pq; 
    for(int s=0; s<score.size();s++){
        pq.push(make_pair(score[s],s));
    }
    vector<string>final(score.size());
    int count = 1;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop(); 
        if (count==1)
            final[top.second]="Gold Medal";
        else if (count==2)
            final[top.second]="Silver Medal";
        else if (count==3)
            final[top.second]="Bronze Medal";
        else
            final[top.second]=to_string(count);
        count++;
    }
    return final;
}
int main(){
    // vector<int> s={5,4,3,2,1};
    vector<int> s={10,3,8,9,4};
    vector<string> f=findRelativeRanks(s);
    for(string s:f){
        cout<<s<<" ";
    }
    return 0;
}
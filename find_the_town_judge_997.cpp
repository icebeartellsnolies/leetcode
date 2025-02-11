#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    unordered_map<int, vector<int>> adjacency_list;
    set<int> all;
    set<int> trustees;
    for(auto& edge:trust){
        adjacency_list[edge[0]].push_back(edge[1]);
        all.insert(edge[0]);
        all.insert(edge[1]);
        trustees.insert(edge[1]);
    }
    set<int> difference;
    set_difference(all.begin(), all.end(), 
                   trustees.begin(), trustees.end(), 
                   inserter(difference, difference.begin()));
    int to_check;
    for (int x : difference) {
        to_check=x;
    }
    int total=trust.size();
    int count=0;
    for(auto& pair:adjacency_list){
        vector<int>& neighbors = pair.second;
        for(int i=0;i<neighbors.size();i++){
            if(neighbors[i]==to_check)
                count++;
        }
    }
    if(count==trustees.size())
        return to_check;
    else return -1;
}

int main(){
    vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
    int n=3;
    int a = findJudge(n,trust);
    cout<<a<<endl;
    return 0;
}
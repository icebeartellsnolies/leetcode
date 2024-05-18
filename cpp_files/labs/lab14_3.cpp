#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;

unordered_map<int, vector<int>> graph(vector<vector<int>>& edges){

    unordered_map<int, vector<int>> adj_lst;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj_lst[u].push_back(v);
    }
    return adj_lst;
}

int longest_path(vector<vector<int>>& edges){
    unordered_map<int, vector<int>> adj_list=graph(edges);
    int max_d=1;
    for(auto &[node, neighs]:adj_list){
        queue<pair<int,int>> q;
        set<int>visited;
        q.push({node,1});
        while (!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            for(int n:adj_list[node]){
                if(visited.find(n)==visited.end()){
                    q.push({n,d+1});
                    max_d=max(max_d, d+1);
                    visited.insert(n);
                }
            }
        }
    }
    return max_d;
}
int main(){
    cout<<"how many inputs?";
    int num;
    cin>>num;
    vector<vector<int>> edges;
    int first;
    for(int i=0;i<num;i++){
        vector<int> curr;
        int a;
        int b;
        cin >>a;
        cin >>b;
        if (i==0)
            first=a;
        curr.push_back(a);
        curr.push_back(b);
        edges.push_back(curr);
    }
    cout<<longest_path(edges);
    return 0;
}
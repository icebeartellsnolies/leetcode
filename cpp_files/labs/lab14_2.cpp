#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> adj_list(vector<vector<int>>& edges){

    unordered_map<int, vector<int>> adj_lst;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj_lst[u].push_back(v);
        adj_lst[v].push_back(u);
       
    }
    return adj_lst;
}
void leaves(){
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
    vector <int> final;
    unordered_map<int, vector<int>> adj_lst=adj_list(edges);
    for (const auto& [node, neighbors] : adj_lst) {
        if (neighbors.size() == 1)
            cout << node << " ";
    }
    
}
int main(){
    leaves();
    return 0;
}
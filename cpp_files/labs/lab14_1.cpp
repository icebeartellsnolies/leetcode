#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>
#include <set>
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
vector<int> bfs_shortest_path(unordered_map<int, vector<int>>& graph, int start, int k) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({start, 0});
    vector<int> final;
    visited.insert(start);
    while (!q.empty()) {
        int node = q.front().first;
        int path = q.front().second;
        q.pop(); 
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor)==visited.end()){
                if (path+1<k){
                    int new_path=path+1;
                    q.push({neighbor, new_path});
                }
                else if(path+1==k){
                    final.push_back(neighbor);
                }
                visited.insert(neighbor);
            }
        }
    }
    return final;
}
void kth_distance(vector<vector<int>> edges,int k){
    unordered_map<int, vector<int>> adj_lst=adj_list(edges);
    for (auto& [node, list] : adj_lst) {
        vector<int> final = bfs_shortest_path(adj_lst,node,k);
        for (int neighbor : final) {
            cout<<node<<" "<<neighbor<<endl;
        }
    }
}

void findPairs(int n, int e, vector<vector<int>>edges, int k) {
    unordered_map<int, vector<int>> adj=adj_list(edges);

    set<pair<int, int>> result;

    for (int i = 1; i <= n; i++) {
        queue<pair<int, int>> q; 
        vector<bool> visited(n + 1, false);
        q.push({i, 0});
        visited[i] = true;

        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();

            if (distance == k) {
                result.insert({i, current});
                continue;
            }

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, distance + 1});
                }
            }
        }
    }

 
    for (auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }
}
int main(){
    cout<<"how many nodes?";
    int nodes;
    cin>>nodes;
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
    cout<<"enter k";
    int k;
    cin>>k;
    kth_distance(edges,k);
    // findPairs(nodes, num,edges,k);
    // kth_distance(edges,k);
    // for(int i=0;i<list.size();i++){
    //     cout<<list[i]<<" ";
    // }
    cout<<endl;
}
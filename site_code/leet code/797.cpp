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

vector<vector<int>> longest_path(vector<vector<int>>& edges){
    int source=0;
   
    unordered_map<int, vector<int>> adj_list=graph(edges);
    int destination=adj_list.size()-1;
    vector<vector<int>> routes;

    queue<pair<int,vector<int>>> q;
    set<int>visited;
    q.push({source,{source}});
    while (!q.empty()){
        int node=q.front().first;
        vector<int> d=q.front().second;
        q.pop();
        for(int n:adj_list[node]){
            if(visited.find(n)==visited.end()){
                vector<int> new_d=d;
                new_d.push_back(n);
                q.push({n,new_d});
                if (new_d[0] == source && new_d.back() == destination)
                    routes.push_back(new_d);
                visited.insert(n);
            }
        }
    }
    
    return routes;
}

// Function to find all paths from source to destination
vector<vector<int>> longest_path_gpt(vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> adj_list = graph(edges);
    int source = 0;                        // Start node
    int destination = adj_list.size() - 1; // Destination node
    vector<vector<int>> routes;            // To store all valid paths

    queue<pair<int, vector<int>>> q;       // BFS queue: pair of current node and path
    q.push({source, {source}});            // Start BFS from source node

    while (!q.empty()) {
        int node = q.front().first;        // Current node
        vector<int> path = q.front().second; // Current path
        q.pop();

        // If we reach the destination, store the path
        if (node == destination) {
            routes.push_back(path);
            continue;
        }

        // Traverse neighbors of the current node
        for (int neighbor : adj_list[node]) {
            vector<int> new_path = path;   // Create a new path by copying the current path
            new_path.push_back(neighbor);  // Add the neighbor to the path
            q.push({neighbor, new_path});  // Push neighbor and updated path into the queue
        }
    }

    return routes; // Return all paths from source to destination
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
    vector<vector<int>> routes=longest_path_gpt(edges);
    for(int i=0; i<routes.size(); i++){
        cout<<"<";
        for(int j=0; j<routes[i].size();j++){
            cout<<routes[i][j]<<" ";
        }
        cout<<">"<<endl;
    }
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

void dfs_from_stack(unordered_map<int, vector<int>>& graph, int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
void bfs_from_adjlist(unordered_map<int, vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

}

bool dfs(int node, int destination, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited,vector<int>&path) {
    path.push_back(node);
    if (node == destination) {
        // path.push_back(node);
        return true;
    }
    visited.insert(node);
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, destination, graph, visited, path)) {
                // path.push_back(neighbor);
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination,vector<int>&path) {
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    unordered_set<int> visited;
    
    return dfs(source, destination, graph, visited,path);
}
    
    

// Example Walkthrough:
// Consider the following graph and a search from source 0 to destination 4:

// edges = [[0, 1], [0, 2], [1, 3], [2, 4]]
// source = 0, destination = 4
// Execution Flow:
// Start at 0:

// Neighbors: 1, 2.
// Call dfs(1).
// At 1:

// Neighbors: 0, 3.
// 0 is already visited.
// Call dfs(3).
// At 3:

// Neighbors: 1.
// 1 is already visited.
// No path found here; backtrack to 1.
// Back at 1:

// All neighbors explored; backtrack to 0.
// Back at 0:

// Call dfs(2).
// At 2:

// Neighbors: 0, 4.
// 0 is already visited.
// Call dfs(4).
// At 4 (Base Case Triggered):

// node == destination, so return true.
// Back at 2:

// The recursive call dfs(4) returned true, so dfs(2) immediately returns true.
// Back at 0:

// The recursive call dfs(2) returned true, so dfs(0) immediately returns true.

vector<int> bfs_shortest_path(unordered_map<int, vector<int>>& graph, int start, int end) {
    queue<pair<int, vector<int>>> q;
    unordered_set<int> visited;

    q.push({start, {start}});
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front().first;
        vector<int> path = q.front().second;
        q.pop();

        if (node == end) {
            return path;
        }
        
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                vector<int> new_path = path;
                new_path.push_back(neighbor);
                q.push({neighbor, new_path});
                visited.insert(neighbor);
            }
        }
    }

    return {}; // No path found
}
int main() {
    // Example adjacency list
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0}},
        {3, {1}},
        {4, {1}}
    };
    vector<vector<int>> edges=
    {
    {0, 1},
    {0, 2},
    {1, 3},
    {1, 4}};
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    vector<int>path;
    cout<<validPath(0,edges,0,4,path)<<endl;
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    // Perform DFS starting from node 0
    dfs_from_stack(graph, 0, visited);
    cout<<endl;
    bfs_from_adjlist(graph,0);
    cout<<endl;
    vector<int> a = bfs_shortest_path(graph,0,4);
    for (int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
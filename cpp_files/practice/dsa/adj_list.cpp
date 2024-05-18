#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<int,vector<int>> adj_lst(vector<vector<int>>& edges){
    unordered_map<int,vector<int>> adj;
    for(int i=0; i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return adj;
}

bool is_valid_path(unordered_map<int,vector<int>> list, int source, int destination, set<int> &visited){
    if (source==destination)
        return true;
    visited.insert(source);
    for(auto & neigh:list[source]){
        if(visited.find(neigh)==visited.end()){
            bool valid=is_valid_path(list,neigh,destination,visited);
            if (valid)
                return true;
        }
    }
    return false;
}
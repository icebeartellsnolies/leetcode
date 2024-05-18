#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// Structure to represent a weighted graph
class WeightedGraph {
public:
    unordered_map<int, vector<pair<int, int>>> adj; // Adjacency list: node -> [(neighbor, weight)]

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
      

        for (const auto& [neighbor, w] : adj[u]) { 
            cout << "node: " << u <<", Neighbor: " << neighbor << ", Weight: " << w << endl; 
        }
       
    }

    // Calculate the total weight of a given path
    int calculatePathWeight(vector<int> path) {
        int totalWeight = 0;

        for (int i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i + 1];
            bool edgeFound = false;

            // Search for the edge (u, v)
            for (const auto& neighbor : adj[u]) {
                if (neighbor.first == v) {
                    totalWeight += neighbor.second;
                    edgeFound = true;
                    break;
                }
            }

            if (!edgeFound) {
                cout << "Path not possible between nodes " << u << " and " << v << endl;
                return -1;
            }
        }

        return totalWeight;
    }
    tuple<int, int> lightest_heaviest(){
        int max_w = INT_MIN;
        int max_node;
        int min_node;
        int min_w = INT_MAX;
        for(int n=0;n<adj.size();n++){
            for(auto &[neigh, weight]:adj[n]){
                if (max_w<weight){
                    max_w=max(max_w,weight);
                    max_node=n;
                }
                if (min_w>weight){
                    min_w=min(min_w,weight);
                    min_node=n;
                }
            }
        }

        return {min_node, max_node};
    }
    bool balanced_graph(){
        bool balanced = true;
        for(int n=0;n<adj.size();n++){
            for(auto&[neigh, weight]:adj[n]){
                for(auto&[n,corr_w]:adj[neigh]){
                    if (corr_w==weight){
                        cout<<n<<" and "<<neigh<<" have equal weights i.e "<<weight;
                    }
                    else
                        balanced=false;
                }
            }
        }
        if(!balanced)
            return false;
        return true;
    }
};

int main() {
    WeightedGraph graph;

    // Add edges to the graph
    graph.addEdge(1, 2, 4);
    graph.addEdge(2, 3, 3);
    graph.addEdge(3, 4, 4);
    graph.addEdge(4, 5, 6);

    // Define the path to check
    vector<int> path = {1, 2, 3, 4, 5};

    // Calculate and display the total path weight
    int totalWeight = graph.calculatePathWeight(path);

    if (totalWeight != -1) {
        cout << "Total weight of the path is: " << totalWeight << endl;
    }
    auto [lightest, heaviest]=graph.lightest_heaviest();
    cout<<"lightest: "<<lightest<<" heaviest "<<heaviest<<endl;
    cout<<graph.balanced_graph();
    return 0;
}

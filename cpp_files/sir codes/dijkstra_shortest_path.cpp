#include <iostream>
#include <limits.h>

using namespace std;

#define V 9
int minDistance(int dist[], bool sptSet[]){	
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printSolution(int dist[]){
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}
void dijkstra(int graph[V][V], int src){
    int dist[V]; // array of shortest distances from the source vertex to all vertices 
    bool sptSet[V]; //boolean array that tracks vertices that are included in the shortest path tree (SPT)
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    // v:vertices, edges= v-1, loop to v-1: since first vertex is considered as source
    for (int count = 0; count < V - 1; count++) {
        // u:index of min node
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] //!sptSet[v] means the edge is unvisited
                && dist[u] != INT_MAX //graph[u][v] means that there is an edge so only neighbors allowed
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}
int main(){
	// This is an adjacency matrix where each row represents the edges to other vertices
	// 0 means no edge and otherwise non-zero is an edge and number is showing the weight
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 0);
    return 0;
}

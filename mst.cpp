/*
    Fill in this block comment before submitting.
    Name: Syed Yasoob Ali
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std;

// Uses Prim's algorithm to find the minimum spanning tree of a graph
void minimumSpanningTree(int** graph, int** mst, int V) 
{
    // Initialize MST to 0 at the start
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            mst[i][j] = 0;
        }
    }

    // Creates 3 vectors, one is to store min weight edge of each vertex
    // Next is to store whether or not the parent of each vertex is in the MST
    // Last one is to check whether or not the vertex itself is in the MST
    
    vector<int> key(V, INT_MAX);   
    vector<int> parent(V, -1);    // -1 means that it does not have a parent
    vector<bool> inMST(V, false); 

    // Priority queue is used to select the vertex with the smallest key value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Start with vertex 0
    key[0] = 0;
    // Pushes the vertex 0 into the priority queue
    pq.push({0, 0}); 

    // Loops until the priority queue is empty
    while (!pq.empty()) 
    {
        int u = pq.top().second; // Get the vertex with the minimum weight
        pq.pop();

        // If vertex u is already in the MST, skip it
        if (inMST[u]) continue;
        inMST[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) 
        {
            // If there is an edge between u and v and v is not already in MST, update the key value to the new minimum.
            // Additionally, update the parent of v to u and push it to prio queue.
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) 
            {
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Build the MST adjacency matrix
    for (int i = 1; i < V; i++) 
    {
        if (parent[i] != -1) 
        { 
            mst[i][parent[i]] = graph[i][parent[i]];
            mst[parent[i]][i] = graph[i][parent[i]]; 
        }
    }
}
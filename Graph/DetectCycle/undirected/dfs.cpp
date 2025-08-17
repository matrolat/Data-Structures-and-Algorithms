#include <bits/stdc++.h>
#include "../../graph_generator.h"
using namespace std;

// make use of parent variable to avoid false cycle in undirected graph

bool isCycle(unordered_map<int,vector<int>> &graph, int u, vector<bool> &visited, int parent)
{

    visited[u] = true;

    for(auto &v : graph[u])
    {
        if(visited[v] && v != parent) return true; // If the adjacent node is visited and is not the parent, a cycle is detected.
        if(!visited[v] && isCycle(graph,v,visited,u))
        {
            return true;
        }
     
    }
    return false;
}

int main() {
    int n = 10; // number of nodes in the graph

    RandomGraph gen(n, 0.3, false );             
    auto graph = gen.generate();   
    
    // to mark visited
    
    vector<bool> visited(n,false);


    for(int i=0;i<n;i++)
    {
        if(!visited[i] && isCycle(graph, i , visited, -1))
        {
            cout << "Cycle detected in the graph." << endl;
            return 0;
        }
    }

    cout << "No cycle detected in the graph." << endl;

    return 0;
}


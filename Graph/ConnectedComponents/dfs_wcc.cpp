#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

void dfs(unordered_map<int,vector<int>> &graph, int u, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " " ;
    for(auto &v : graph[u])
    {
        if(!visited[v])
        {
            dfs(graph,v,visited);
        }
    }
}

int main() {
    int n = 10; // number of nodes in the graph

    RandomGraph gen(n, 0.3, false );             
    auto graph = gen.generate();   
    
    // to mark visited
    vector<bool> visited(n,false);

    int connected_components = 0;
    // for each call to dfs, we will handle a connected component
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            connected_components++;
            dfs(graph, i , visited);
        }
    }
    cout << "\nTotal connected components: " << connected_components << endl;

    return 0;
}


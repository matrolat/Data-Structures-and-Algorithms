#include <bits/stdc++.h>
#include "../../graph_generator.h"
using namespace std;

bool isCycle(unordered_map<int,vector<int>> &graph, int u, vector<bool> &visited, vector<bool> &inRecurr)
{
    inRecurr[u] = true;
    visited[u] = true;

    for(auto &v : graph[u])
    {
        if(!visited[v] && isCycle(graph,v,visited,inRecurr))
        {
            return true;
        }
        else if( inRecurr[v])
        {
            return true;
        }
    }
    inRecurr[u] = false;
    return false;
}

int main() {
    int n = 10; // number of nodes in the graph

    RandomGraph gen(n, 0.3, true );             
    auto graph = gen.generate();   
    
    // to mark visited
    
    vector<bool> visited(n,false);
    vector<bool> inRecurr(n,false);


    // since graph component are not necessarily connected, we need to handle each component separately
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && isCycle(graph, i , visited, inRecurr))
        {
            cout << "Cycle detected in the graph." << endl;
            return 0;
        }
    }

    cout << "No cycle detected in the graph." << endl;

    return 0;
}


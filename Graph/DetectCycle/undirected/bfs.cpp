#include <bits/stdc++.h>
#include "../../graph_generator.h"
using namespace std;

// make use of parent variable to avoid false cycle in undirected graph

bool isCycle(unordered_map<int,vector<int>> &graph, int src, vector<bool> &visited, int par)
{

    visited[src] = true;

    // storing node and its parent
    queue<pair<int,int>> q;
    q.push({src, par});

    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second; 
        q.pop();

        for(auto &v : graph[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push({v,u});
            }
            else if(v != parent)
            {
                return true;
            }
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


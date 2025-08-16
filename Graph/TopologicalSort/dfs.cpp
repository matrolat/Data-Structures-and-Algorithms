#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

void dfs(unordered_map<int,vector<int>> &graph, int u, vector<bool> &visited,  stack<int> &st)
{
    visited[u] = true;
    
    for(auto &v : graph[u])
    {
        if( !visited[v])
        {
            dfs(graph, v, visited, st);
        }
    }
    st.push(u);
}

int main() {
    int n = 10; // number of nodes in the graph

    RandomGraph gen(n, 0.3, true );             
    auto graph = gen.generate();   
    
    // to mark visited
    vector<bool> visited(n,false);

    // this stack will contain topo sort in reverse order
    stack<int> st;

    // multisource dfs
    for(int i = 0;i<n;i++)
    {
        if( !visited[i])
        {
            dfs(graph, i , visited, st);
        }
    }

    // printing topo sort
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}


#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

bool checkBipartite(unordered_map<int,vector<int>> &graph, int src, vector<int> &colors, int currColor)
{
    queue<int> q;

    q.push(src);
    colors[src] = currColor;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for( auto &v : graph[u])
        {
            if( colors[u] == colors[v]) return false;
            if(colors[v]== -1)
            {
                int newColor = 1 - colors[u];
                colors[v] = newColor;
                q.push(v);
            }
        }

    }
    


    return true;
}

int main() {
    int n = 10; 
    // it is only for undirected graph
    RandomGraph gen(n, 0.3, false );             
    auto graph = gen.generate();   
    
    vector<int> colors(n, -1);

    for(int i=0;i<n;i++)
    {
        if(colors[i]==-1 && !checkBipartite(graph, i, colors, 1))
        {
            cout<< "NOT Bipartite"<< endl;
            break;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

bool checkBipartite(unordered_map<int,vector<int>> &graph, int u, vector<int> &colors, int currColor)
{
    colors[u] = currColor;

    for( auto &v : graph[u])
    {
        int newColor= 1 - currColor;
        if( colors[v] == colors[u]) return false;
        if(colors[v] == -1 && !checkBipartite(graph, v, colors,newColor ))
        {
            return false;
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


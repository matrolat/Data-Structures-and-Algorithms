#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

void bfs(unordered_map<int,vector<int>> &graph, int n)
{
    int connected_components = 0;

    vector<bool> visited(n,false);
    for(int src=0;src<n;src++)
    {
        if(!visited[src])
        {
            connected_components++;
            queue<int> q;
            q.push(src);
            visited[src] = true;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                cout << u << " ";
                
                for(auto &v:graph[u])
                {
                    if(!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
        
            }
            

        }
    }

    cout << "\nTotal connected components: " << connected_components << endl;

}

int main() {

    int n = 10;
    RandomGraph gen(n, 0.6, false );             
    auto graph = gen.generate();   

    bfs(graph, n);

    return 0;
}
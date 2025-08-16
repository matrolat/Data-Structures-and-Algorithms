

// For multisource you can traverse through same bfs/dfs for every node possible
#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, int n)
{
    vector<bool> visited(n, false);

    for (int src = 0; src < n; ++src)
    {
        if (visited[src]) continue;

        queue<int> q;
        q.push(src);
        visited[src] = true;

        cout << "Level order from node " << src << ":\n";

        while (!q.empty())
        {
            int level = q.size();
            while (level--)
            {
                int u = q.front();
                q.pop();
                cout << u << " ";

                for (auto &v : graph[u])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            cout << "\n";
        }
    }
}

int main()
{
    int n = 10;
    RandomGraph gen(n, 0.6, true);
    auto graph = gen.generate();

    cout << "Generated Graph:\n";
    for (auto &[u, adj] : graph)
    {
        cout << u << ": ";
        for (int v : adj)
            cout << v << " ";
        cout << "\n";
    }

    cout << "\nBFS Traversal:\n";
    bfs(graph, n);

    return 0;
}

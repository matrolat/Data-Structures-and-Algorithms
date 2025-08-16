#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, int n)
{
    vector<bool> visited(n, false);

    int src = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;

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

int main()
{

    int n = 10;
    RandomGraph gen(n, 0.6, true);
    auto graph = gen.generate();

    bfs(graph, n);

    return 0;
}
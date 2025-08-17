#include <bits/stdc++.h>
#include "../../graph_generator.h"
using namespace std;
// DSU with RANK and PATH COMPRESSION
struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);
    }

    int find(int x)
    {
        if( parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        int a_parent = find(a);
        int b_parent = find(b);

        if( rank[a_parent] == rank[b_parent] )
        {
            rank[b_parent]++;
            parent[a_parent] = b_parent;
        }
        else if( rank[a_parent] > rank[b_parent])
        {
            // smaller ones parent is greater
            parent[b_parent] = a_parent;
        }
        else{
            parent[a_parent] = b_parent;
        }

    }
};

// Cycle is detected if both nodes have the same parent in DSU
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    double p = 0.6;

    RandomGraph gen(n, p, false);
    auto graph = gen.generate();

    vector<pair<int, int>> edges;
    for (auto &kv : graph)
    {
        int u = kv.first;
        for (int v : kv.second)
        {
            if (u < v)
                edges.emplace_back(u, v);
        }
    }

    cout << "Edges (" << edges.size() << "): ";
    for (auto &e : edges)
        cout << "(" << e.first << "," << e.second << ") ";
    cout << "\n";

    DSU dsu(n);
    for(auto it: edges)
    {
        if(dsu.find(it.first) == dsu.find(it.second))
        {
            cout << "Cycle detected between nodes: " << it.first << " and " << it.second << "\n";
            return 0;
        }
        dsu.unite(it.first, it.second);

    }

    return 0;
}

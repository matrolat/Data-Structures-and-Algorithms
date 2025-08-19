#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

// DSU with path compression and union by rank
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }
};

// Kruskal's algorithm function
pair<int, vector<pair<int, int>>> kruskalMST(int n, vector<tuple<int, int, int>>& edges) {
    // edges: (weight, u, v)
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int totalCost = 0;
    vector<pair<int, int>> mst;

    for (auto& [wt, u, v] : edges) {
        if (dsu.unite(u, v)) {
            totalCost += wt;
            mst.emplace_back(u, v);
        }
    }

    return {totalCost, mst};
}

// Driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    double p = 0.6;

    RandomGraph gen(n, p, false); // undirected graph
    auto graph = gen.generate();

    // Build edges with random weights
    mt19937 rng(42);
    uniform_int_distribution<int> dist(1, 20);

    vector<tuple<int, int, int>> edges;
    for (auto& [u, neighbors] : graph) {
        for (int v : neighbors) {
            if (u < v) {
                int wt = dist(rng);
                edges.emplace_back(wt, u, v);
            }
        }
    }

    // Print edges
    cout << "Graph Edges:\n";
    for (auto& [wt, u, v] : edges) {
        cout << u << " - " << v << " : weight = " << wt << "\n";
    }

    // Run Kruskal's Algorithm
    auto [cost, mstEdges] = kruskalMST(n, edges);

    // Output result
    cout << "\nMST Edges:\n";
    for (auto& [u, v] : mstEdges) {
        cout << u << " - " << v << "\n";
    }
    cout << "Total cost of MST: " << cost << "\n";

    return 0;
}

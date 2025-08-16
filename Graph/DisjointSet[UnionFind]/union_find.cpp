#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }


    int find(int x) {
        if( parent[x] == x ) return x;
        
        return find(parent[x]); 
    }

    void unite(int a, int b) {
        int a_parent = find(a);
        int b_parent = find(b);

        parent[a_parent] = b_parent;

    }
};

// driver function to demonstrate Union-Find for connected components
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    double p = 0.6;

    // false => undirected (Union–Find is for undirected connectivity)
    RandomGraph gen(n, p, false);
    auto graph = gen.generate();

    // Build a deduplicated edge list (u < v to avoid doubles)
    vector<pair<int,int>> edges;
    for (auto &kv : graph) {
        int u = kv.first;
        for (int v : kv.second) {
            if (u < v) edges.emplace_back(u, v);
        }
    }

    cout << "Edges (" << edges.size() << "): ";
    for (auto &e : edges) cout << "(" << e.first << "," << e.second << ") ";
    cout << "\n";

    // Run Union–Find
    DSU dsu(n);
    for (auto &e : edges) dsu.unite(e.first, e.second);

    // Group nodes by root to print components
    unordered_map<int, vector<int>> comps;
    for (int i = 0; i < n; ++i) {
        int r = dsu.find(i);
        comps[r].push_back(i);
    }

    int idx = 0;
    for (auto &kv : comps) {
        cout << "Component " << (++idx) << ": ";
        for (int v : kv.second) cout << v << " ";
        cout << "\n";
    }
    cout << "Total connected components: " << comps.size() << "\n";

    return 0;
}

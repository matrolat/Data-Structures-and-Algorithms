#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Build adjacency list
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto &it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Using set instead of priority_queue
        set<pair<int,int>> st;  // {dist, node}
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *(st.begin()); // Get element with smallest distance
            st.erase(st.begin());

            int cost = it.first;
            int u = it.second;

            for (auto &[v, w] : graph[u]) {
                if (cost + w < dist[v]) {
                    // If v already in set, erase old entry
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = cost + w;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
};

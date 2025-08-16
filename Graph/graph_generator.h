#pragma once
#include <bits/stdc++.h>
using namespace std;

class RandomGraph {
    int n;
    double p;
    bool directed;
    mt19937 rng;

public:
    RandomGraph(int nodes = 5, double prob = 0.3, bool isDirected = false) {
        n = nodes;
        p = prob;
        directed = isDirected;
        rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    }

    unordered_map<int, vector<int>> generate() {
        unordered_map<int, vector<int>> adj;
        uniform_real_distribution<double> dist(0.0, 1.0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist(rng) < p) {
                    adj[i].push_back(j);
                    if (!directed) {
                        adj[j].push_back(i);
                    }
                }
            }
        }
        return adj;
    }
};

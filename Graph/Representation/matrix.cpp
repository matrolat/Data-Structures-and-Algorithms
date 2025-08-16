
#include<bits/stdc++.h>
using namespace std;
// Adjacency list consist of unordered_map of vectors, where each key is a vertex and the value is a vector of adjacent vertices.
 
int main() {
    vector<vector<int>> adjMatrix = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    unordered_map<int, vector<int>> adjList;

    int n = adjMatrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    // Print adjacency list
    for (auto &p : adjList) {
        cout << p.first << ": ";
        for (int v : p.second) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 4-directional movement: right, down, left, up
    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    void multiSourceBFS(vector<vector<int>>& grid, vector<pair<int, int>>& sources) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Push all sources into queue
        for (auto& src : sources) {
            int x = src.first, y = src.second;
            q.push({x, y});
        }

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // Boundary and condition check
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        // Example condition: only visit cells with value 0
                        if (grid[nx][ny] == 0) {
                            // Mark as visited or update value
                            grid[nx][ny] = grid[x][y] + 1;

                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
};

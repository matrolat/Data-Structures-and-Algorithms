#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Floyd Warshall Algorithm
    int main(int n, vector<vector<int>>& edges) {
        

        // shortest path matrix
        vector<vector<int>> spm(n , vector<int>(n, INT_MAX));
        // generating graph matrix
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt= it[2];
            spm[u][v] = wt;
            spm[v][u] = wt;
        }
        // self travel should be zero
        for (int i = 0; i < n; i++) {
            spm[i][i] = 0;
        }

        for(int via = 0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if (spm[i][via] != INT_MAX && spm[via][j] != INT_MAX) {
                        spm[i][j] = min(spm[i][j], spm[i][via] + spm[via][j]);
                    }
                   
                }
            }
        }

        // Print the shortest path matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (spm[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << spm[i][j] << " ";
                }
            }
            cout << endl;
        }

    
    }
};
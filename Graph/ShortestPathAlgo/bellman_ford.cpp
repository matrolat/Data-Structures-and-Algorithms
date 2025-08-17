
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
       
        vector<int> result(V, 1e8);
        result[src] = 0;
        for(int i = 0;i < V-1;i++)
        {
            for(auto it : edges)
            {
                int u  = it[0];
                int v  = it[1];
                int wt = it[2];
                if(result[u] != 1e8)
                {
                    int newDist = result[u] + wt;
                    if(newDist < result[v])
                    {
                        result[v] = newDist;
                    }
                }
            }
        }
        
        // detect negative cycle
         for(int i = 0;i < V-1;i++)
        {
            for(auto it : edges)
            {
                int u  = it[0];
                int v  = it[1];
                int wt = it[2];
                if(result[u] != 1e8)
                {
                    int newDist = result[u] + wt;
                    if(newDist < result[v])
                    {
                        return {-1};
                    }
                }
            }
        }
        
        return result;
        
    }
};

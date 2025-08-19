
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        int sum = 0;
        
        vector<bool> inMST(V, false);
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            // this is where u put it in mst
            if (inMST[u]) continue;
            sum += wt;
            inMST[u] = true;
            
            for(auto &[v, vCost]: graph[u] )
            {
                // only push vcost
                if(!inMST[v])
                {
                    pq.push( {vCost ,v} );
                }
            }
            
        }
        
        
        
        
        return sum;
    }
};
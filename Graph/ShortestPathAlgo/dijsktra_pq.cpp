// User Function Template
#include <bits/stdc++.h>
using namespace std;
// Function to find the shortest path using Dijkstra's algorithm
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
       
        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto it:edges)
        {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
       
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            
        pq.push( { 0 , src} );
        dist[src] = 0;
        
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto &[v, vCost]: graph[u] )
            {
                int newCost = cost + vCost;
                if( newCost < dist[v])
                {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
            
        }
        return dist;
       
       
       
        
    }
};
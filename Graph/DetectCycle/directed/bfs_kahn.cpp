#include <bits/stdc++.h>
#include "../../graph_generator.h"
using namespace std;

bool isCycle(unordered_map<int,vector<int>> &graph,int n)
{
    
    vector<int> indegree(n, 0);

    // counted indegree of each node
    for(auto it:graph)
    {
        auto u = it.first;
        auto arr = it.second;

        for(int i : arr)
        {
            indegree[i]++;
        }
    }

    // starting from nodes with indegree 0
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if( indegree[i]==0)
        {
            q.push(i);
        }
    }


    vector<int> result;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);


       auto arr =  graph[curr];
       for( int v: arr)
       {
            indegree[v]--;
            if( indegree[v] == 0)
            {
                q.push(v);
            }
       }
    }
    return result.size() != n; // if the size of the result is not equal to the number of nodes, there is a cycle
}

int main() {
    int n = 10; // number of nodes in the graph

    RandomGraph gen(n, 0.3, true );             
    auto graph = gen.generate();   
    
    if(isCycle(graph, n))
    {
        cout << "Cycle detected in the graph." << endl;
        return 0;
    }
    
    cout << "No cycle detected in the graph." << endl;

    return 0;
}


#include <bits/stdc++.h>
#include "../graph_generator.h"
using namespace std;

// Kahn's algorithm is a method for topological sorting of a directed acyclic graph (DAG) using the concept of in-degrees.
int main() {

    int n = 10;
    RandomGraph gen(n, 0.6, true );             
    auto graph = gen.generate();   

    // 1->2,3,4
    // 2->4

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

    if( result.size() != n )
    {
        cout << "Graph has cycle, topological sort not possible" << endl;
        return 0;
    }

    cout << "Topological sorting";
    for(auto it:result)
    {
        cout << it << endl;
    }


    

    

   

    return 0;
}
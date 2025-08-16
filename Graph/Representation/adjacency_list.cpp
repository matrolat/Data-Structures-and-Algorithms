
#include<bits/stdc++.h>
using namespace std;
// Adjacency list consist of unordered_map of vectors, where each key is a vertex and the value is a vector of adjacent vertices.
 
int main()  
{
    unordered_map<int, vector<int>> adjList;
    // directed graph
    adjList[1].push_back(3);
    // For bidirectional graph, we add edges in both directions.
    adjList[1].push_back(2);
    adjList[2].push_back(1);
        
    return 0;
}
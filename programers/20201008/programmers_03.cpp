#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int minEdgeBFS(vector <int> edges[], int u, 
                              int v, int n) 
{ 
    // visited[n] for keeping track of visited 
    // node in BFS 
    vector<bool> visited(n, 0); 
  
    // Initialize distances as 0 
    vector<int> distance(n, 0); 
  
    // queue to do BFS. 
    queue <int> Q; 
    distance[u] = 0; 
  
    Q.push(u); 
    visited[u] = true; 
    while (!Q.empty()) 
    { 
        int x = Q.front(); 
        Q.pop(); 
  
        for (int i=0; i<edges[x].size(); i++) 
        { 
            if (visited[edges[x][i]]) 
                continue; 
  
            // update distance for i 
            distance[edges[x][i]] = distance[x] + 1; 
            Q.push(edges[x][i]); 
            visited[edges[x][i]] = 1; 
        } 
    } 
    return distance[v]; 
} 

// function for addition of edge 
void addEdge(vector <int> edges[], int u, int v) 
{ 
   edges[u].push_back(v); 
   edges[v].push_back(u); 
} 

int solution(int n, vector<vector<int>> edges) {
    vector <int> myEdges[n]; 
    for (int i = 0; i < edges.size(); i++) {
        addEdge(myEdges, edges[i][0] - 1, edges[i][1] - 1);
    }
    
    int maxDistance = -1;
    int a, b;
    // 최대 거리를 먼저 구한다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int val = minEdgeBFS(myEdges, i, j, n);
            if (val > maxDistance) {
                maxDistance = val;
                a = i;
                b = j;
            }
        }
    }
    cout << "최대: " << a << ", " << b << endl;
    
    int fMax = -1;
    for (int c = 0; c < n; c++) {
        if (c == a || c == b) continue;
        int dist1 = minEdgeBFS(myEdges, c, a, n);
        int dist2 = minEdgeBFS(myEdges, c, b, n);
        int tmp_fMax;
        if (dist1 <= dist2 && dist2 <= maxDistance) tmp_fMax = dist2;
        else tmp_fMax = dist1;
        if (tmp_fMax > fMax) fMax = tmp_fMax;
    }
    
    return fMax;
}
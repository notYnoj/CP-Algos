#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    int n, m;
    cin >> n >> m;
    int source;
    cin >> source;  // Assuming the source node is provided as input
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> adj(n); // Storing pairs (neighbor, weight)
    
    // Reading the graph's edges and weights
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        adj[a].pb({b, weight});
        adj[b].pb({a, weight}); // Remove this line if the graph is directed
    }
    
    vector<int> d(n, INT_MAX); // Distance vector initialized with infinity
    d[source] = 0;
    
    pq.push({0, source}); // Push source node with distance 0
    
    while (!pq.empty()) {
        int u = pq.top().second; // Current node
        int dist = pq.top().first; // Distance to current node
        pq.pop();
        
        if (dist > d[u]) continue; // Skip if we've already found a shorter path
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                pq.push({d[v], v});
            }
        }
    }
    
    // Output the shortest distances from the source to all nodes
    for (int i = 0; i < n; i++) {
        if (d[i] == INT_MAX) 
            cout << "INF" << " ";
        else 
            cout << d[i] << " ";
    }
    cout << endl;
    
    return 0;
}

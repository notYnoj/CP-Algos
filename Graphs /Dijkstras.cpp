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

/*Ex:
Hard - Leetcode - 2699. Modify Graph Edge Weights

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        } //making adj

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;
        //dijkstras intial, we keep distances to make sure that we .
        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        //run it twice one with only miniomum
        int difference = target - distances[destination][0];
        if (difference < 0) return {}; //check if we can even get to the target with smallest path if not then return
        runDijkstra(adjacencyList, edges, distances, source, difference, 1); //oterhwesi do whats down there
        if (distances[destination][1] < target) return {}; //check to make sure were good

        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1; // make all other ones 1  and return
        }
        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty()) {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue;

            for (auto& neighbor : adjacencyList[currentNode]) {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1) weight = 1; 

                if (run == 1 && edges[edgeIndex][2] == -1) {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1]; //make sure taht we only give things 1 (think abt it if its all 1s like 3 paths of 1s and difference is 3 we increase first one by 3 then we get to 3rd we get 0-1 = 1 1-2 = 1 2-3 = 1 and 0-1 = 4 1-2 = 1 which ends up giving us 3 + 3-5  = 1 whcih is good 
                    if (newWeight > weight) {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                if (distances[nextNode][run] > distances[currentNode][run] + weight) {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};
static const auto mynameisbarryallen = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(weight, v));
        adj[v].push_back(make_pair(weight, u));
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto &neighbor : adj[u]) {
                int weight = neighbor.first;
                int v = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Shortest distances from source vertex " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " \tDistance: " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.dijkstra(0);

    return 0;
}

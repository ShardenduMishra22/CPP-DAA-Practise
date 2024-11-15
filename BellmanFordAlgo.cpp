#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 1; i < V; i++) {
            for (auto &edge : edges) {
                if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
        }

        for (auto &edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                cout << "Graph contains negative weight cycle!" << endl;
                return;
            }
        }

        cout << "Shortest distances from source vertex " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " \tDistance: " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 5, E = 8;
    Graph g(V, E);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}

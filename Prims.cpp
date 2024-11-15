#include<bits/stdc++.h>
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

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        pq.push(make_pair(0, 0));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto &neighbor : adj[u]) {
                int weight = neighbor.first;
                int v = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \tWeight: " << key[i] << endl;
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

    g.primMST();

    return 0;
}
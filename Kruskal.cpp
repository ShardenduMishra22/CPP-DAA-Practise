#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

bool cmp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<Edge> kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), cmp);

    DisjointSet ds(V);
    vector<Edge> mst;

    for (Edge &edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            mst.push_back(edge);
            ds.unite(edge.src, edge.dest);
        }
    }

    return mst;
}

int main() {
    vector<Edge> edges;

    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    vector<Edge> mst = kruskalMST(V, edges);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge &edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void vertexCover(vector<pair<int, int>>& edges, int V) {
    vector<bool> visited(V, false);
    vector<pair<int, int>> result;

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (!visited[u] && !visited[v]) {
            visited[u] = visited[v] = true;
            result.push_back(edge);
        }
    }

    cout << "The vertex cover is: ";
    for (auto& edge : result) {
        cout << edge.first << " " << edge.second << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges(E);
    
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vertexCover(edges, V);
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int tsp(int pos, vector<vector<int>>& dist, vector<bool>& visited, int n) {
    bool allVisited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }

    if (allVisited) {
        return dist[pos][0];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if (!visited[city] && city != pos) {
            visited[city] = true;
            int newAns = dist[pos][city] + tsp(city, dist, visited, n);
            ans = min(ans, newAns);
            visited[city] = false;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<bool> visited(n, false);
    visited[0] = true;
    cout << tsp(0, dist, visited, n) << endl;
    return 0;
}

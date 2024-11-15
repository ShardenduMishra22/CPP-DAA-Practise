#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (dp[m][n] != -1) {
        return dp[m][n];  // Return the cached result
    }

    if (X[m - 1] == Y[n - 1]) {
        dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    } else {
        dp[m][n] = max(lcs(X, Y, m - 1, n, dp), lcs(X, Y, m, n - 1, dp));
    }

    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int m = X.length();
    int n = Y.length();

    // Create a DP table initialized to -1 (to indicate that no solution has been calculated yet)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << "Length of Longest Common Subsequence: " << lcs(X, Y, m, n, dp) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int Knapsack(int w, vector<int>& wgt, vector<int>& val, int n) {
    if (n == 0 || w == 0) {
        return 0;
    }

    if (wgt[n - 1] > w) {
        return Knapsack(w, wgt, val, n - 1); // Skip the current item if its weight is more than the remaining capacity
    }

    int include = val[n - 1] + Knapsack(w - wgt[n - 1], wgt, val, n - 1);
    int exclude = Knapsack(w, wgt, val, n - 1);

    return max(include, exclude);
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wgt = {10, 20, 30};
    int W = 50;

    cout << "Maximum value: " << Knapsack(W, wgt, val, val.size()) << endl;
    return 0;
}

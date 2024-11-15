#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& arr, int sum, int n) {
    if (sum == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }

    if (arr[n - 1] > sum) {
        return subsetSum(arr, sum, n - 1);
    }

    return subsetSum(arr, sum - arr[n - 1], n - 1) || subsetSum(arr, sum, n - 1);
}

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (subsetSum(arr, sum, n)) {
        cout << "Yes, there is a subset with the given sum." << endl;
    } else {
        cout << "No, there is no subset with the given sum." << endl;
    }

    return 0;
}

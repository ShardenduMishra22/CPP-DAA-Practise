#include <bits/stdc++.h>
using namespace std;

int minCoinsRecursive(vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    int result = INT_MAX;
    
    for (int coin : coins) {
        if (amount >= coin) {
            int subResult = minCoinsRecursive(coins, amount - coin);
            if (subResult != INT_MAX) {
                result = min(result, subResult + 1);
            }
        }
    }
    
    return result;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = minCoinsRecursive(coins, amount);
    if (result == INT_MAX) {
        cout << "It's not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum coins needed: " << result << endl;
    }

    return 0;
}

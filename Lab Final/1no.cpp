#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp, vector<bool>& included) {
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtracking
    int remainingWeight = W;
    for (int i = n; i > 0 && remainingWeight > 0; --i) {
        if (dp[i][remainingWeight] != dp[i - 1][remainingWeight]) {
            included[i - 1] = true;
            remainingWeight -= wt[i - 1];
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> profit(n), weight(n);
    cout << "Enter the profits and weights of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Profit of item " << i + 1 << ": ";
        cin >> profit[i];
        cout << "weight of item " << i + 1 << ": ";
        cin >> weight[i];
    }

    int W;
    cout << "Enter the maximum capacity of knapsack: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    vector<bool> included(n, false);

    int max_profit = knapsack(W, weight, profit, n, dp, included);

    cout << "Maximum profit: " << max_profit << endl;

    cout << "\nDP Table:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nItems included in the knapsack:" << endl;
    for (int i = 0; i < n; ++i) {
        if (included[i]) {
            cout << "Item " << i + 1 << ": Profit = " << profit[i] << ", Weight = " << weight[i] << endl;
        }
    }

    return 0;
}

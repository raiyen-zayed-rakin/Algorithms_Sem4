#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for std::setw

using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
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
        cout << "Profit and weight of item " << i + 1 << ": ";
        cin >> profit[i] >> weight[i];
    }

    int W;
    cout << "Enter the maximum capacity of knapsack: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    int max_profit = knapsack(W, weight, profit, n, dp);

    // Display the maximum profit
    cout << "Maximum profit: " << max_profit << endl;

    // Display the DP table
    cout << "\nDP Table:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            cout << setw(2) << setfill('0') << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

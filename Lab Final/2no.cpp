#include <iostream>
#include <vector>
#include <string>

using namespace std;

string LCS(string X, string Y, vector<vector<int>>& dp) {
    int m = X.length();
    int n = Y.length();

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs; 
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string X = "ANACONDA";
    string Y = "RAIYEN";

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    string lcs = LCS(X, Y, dp);

    cout << "Longest Common Subsequence: " << lcs << endl;

    cout << "DP Table:" << endl;
    cout << "   ";
    for (char c : Y) {
        cout << c << " ";
    }
    cout << endl;
    for (int i = 0; i <= m; ++i) {
        if (i > 0)
            cout << X[i - 1] << " ";
        else
            cout << "  ";
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

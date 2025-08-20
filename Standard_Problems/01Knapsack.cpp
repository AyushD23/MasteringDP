#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

// Solves 0/1 Knapsack problem for max value
// T: O(n*W), S: O(n*W)
int knapsack01(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i-1] <= w) { // Can include item i
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            } else { // Cannot include item i
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << "Max value (0/1 Knapsack): " << knapsack01(W, wt, val, n) << endl; // Expected: 220
    return 0;
}

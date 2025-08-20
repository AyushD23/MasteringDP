#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

// Solves Unbounded Knapsack problem (e.g., Rod Cutting) for max value
// T: O(n*W), S: O(W)
int unboundedKnapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) { // Iterate through items
        for (int w = wt[i]; w <= W; ++w) { // Iterate through capacities
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main() {
    // Example: Rod cutting problem (lengths as weights, prices as values)
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20}; // val
    vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8};   // wt
    int rodLength = 8; // W
    int n = prices.size();
    cout << "Max value (Rod Cutting): " << unboundedKnapsack(rodLength, lengths, prices, n) << endl; // Expected: 22
    return 0;
}

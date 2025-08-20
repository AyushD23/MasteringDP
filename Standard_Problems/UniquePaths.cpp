#include <iostream>
#include <vector>

using namespace std;

// Calculates number of unique paths from top-left to bottom-right in m x n grid
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int j = 0; j < n; ++j) dp[0][j] = 1;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    cout << "Unique Paths (3x7 grid): " << uniquePaths(3, 7) << endl; 
    cout << "Unique Paths (3x2 grid): " << uniquePaths(3, 2) << endl; 
    return 0;
}

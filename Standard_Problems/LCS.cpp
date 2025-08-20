#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For max

using namespace std;

// Calculates length of LCS
// T: O(m*n), S: O(m*n)
int lcs(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "LCS Length: " << lcs(s1, s2) << endl; // Expected: 4 (GTAB)
    return 0;
}

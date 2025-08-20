#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For min

using namespace std;

// Calculates edit distance (min operations to convert s1 to s2)
// T: O(m*n), S: O(m*n)
int editDist(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) { // s1 is empty, insert all chars of s2
                dp[i][j] = j;
            } else if (j == 0) { // s2 is empty, delete all chars of s1
                dp[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) { // Characters match
                dp[i][j] = dp[i-1][j-1];
            } else { // Characters don't match
                dp[i][j] = 1 + min({dp[i][j-1],   // Insert
                                    dp[i-1][j],   // Delete
                                    dp[i-1][j-1]}); // Replace
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "kitten";
    string s2 = "sitting";
    cout << "Edit Distance: " << editDist(s1, s2) << endl; // Expected: 3
    return 0;
}

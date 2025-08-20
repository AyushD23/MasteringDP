#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Checks if s3 is an interleaving of s1 and s2
bool isInterleave(const string& s1, const string& s2, const string& s3) {
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    if (n1 + n2 != n3) return false;

    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            if (i > 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                dp[i][j] = true;
            }
            if (j > 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                dp[i][j] = true;
            }
        }
    }
    return dp[n1][n2];
}

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << "Is interleaving ('aabcc', 'dbbca', 'aadbbcbcac'): " << (isInterleave(s1, s2, s3) ? "True" : "False") << endl;
    string s4 = "aabcc", s5 = "dbbca", s6 = "aadbbbaccc";
    cout << "Is interleaving ('aabcc', 'dbbca', 'aadbbbaccc'): " << (isInterleave(s4, s5, s6) ? "True" : "False") << endl;
    return 0;
}

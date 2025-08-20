#include <iostream>
#include <vector>

using namespace std;

// Calculates nth Catalan number using DP
// T: O(n^2), S: O(n)
int catalan(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main() {
    cout << "Catalan(0): " << catalan(0) << endl; // Expected: 1
    cout << "Catalan(1): " << catalan(1) << endl; // Expected: 1
    cout << "Catalan(2): " << catalan(2) << endl; // Expected: 2
    cout << "Catalan(3): " << catalan(3) << endl; // Expected: 5
    cout << "Catalan(5): " << catalan(5) << endl; // Expected: 42
    return 0;
}

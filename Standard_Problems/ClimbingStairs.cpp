#include <iostream>
#include <vector>

using namespace std;

// Calculates number of ways to climb n stairs (1 or 2 steps at a time)
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    cout << "Ways to climb 2 stairs: " << climbStairs(2) << endl; 
    cout << "Ways to climb 3 stairs: " << climbStairs(3) << endl; 
    return 0;
}

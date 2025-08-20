#include <iostream>
#include <vector>
#include <algorithm> // For min

using namespace std;

// Calculates minimum coins to make amount
// T: O(amount * num_coins), S: O(amount)
int coinChangeMin(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1); // Initialize with impossible value
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Min coins for 11: " << coinChangeMin(coins, amount) << endl; // Expected: 3

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Min coins for 3: " << coinChangeMin(coins2, amount2) << endl; // Expected: -1
    return 0;
}

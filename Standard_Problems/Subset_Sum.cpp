#include <iostream>
#include <vector>
#include <numeric> // For accumulate

using namespace std;

// Checks if a subset with given sum exists
// T: O(n*sum), S: O(sum)
bool subsetSum(const vector<int>& nums, int sum) {
    int n = nums.size();
    vector<bool> dp(sum + 1, false);
    dp[0] = true; // Sum 0 is always possible (empty set)

    for (int num : nums) {
        // Iterate backwards to avoid using an item multiple times in current row
        for (int j = sum; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[sum];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << "Subset with sum " << sum << " exists: " << (subsetSum(nums, sum) ? "True" : "False") << endl; // Expected: True ({4, 5})
    
    int sum2 = 30;
    cout << "Subset with sum " << sum2 << " exists: " << (subsetSum(nums, sum2) ? "True" : "False") << endl; // Expected: False
    return 0;
}

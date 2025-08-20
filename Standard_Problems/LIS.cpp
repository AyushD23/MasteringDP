#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

// Calculates length of LIS (O(n^2) DP)
int lis(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1); // Each element is LIS of length 1

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lis(nums) << endl; // Expected: 4 ({2,3,7,18})
    return 0;
}

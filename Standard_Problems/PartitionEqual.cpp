#include <iostream>
#include <vector>
#include <numeric> 

using namespace std;

// Checks if array can be partitioned into two subsets with equal sum
bool canPartition(const vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum % 2 != 0) return false;
    int targetSum = totalSum / 2;

    vector<bool> dp(targetSum + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = targetSum; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[targetSum];
}

int main() {
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Can partition {1,5,11,5}: " << (canPartition(nums1) ? "True" : "False") << endl;
    
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Can partition {1,2,3,5}: " << (canPartition(nums2) ? "True" : "False") << endl; 
    return 0;
}

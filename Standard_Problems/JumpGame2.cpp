#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits> 

using namespace std;

// Calculates minimum jumps to reach last index
int jump(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;

    vector<int> dp(n, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= nums[i] && i + j < n; ++j) {
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    return dp[n-1];
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Min jumps for {2,3,1,1,4}: " << jump(nums1) << endl; 
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Min jumps for {2,3,0,1,4}: " << jump(nums2) << endl;
    return 0;
}

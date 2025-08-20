#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Checks if last index can be reached
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reachable = 0; 

    for (int i = 0; i < n; ++i) {
        if (i > reachable) {
            return false;
        }
        reachable = max(reachable, i + nums[i]);
        if (reachable >= n - 1) {
            return true;
        }
    }
    return true;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Can jump to end for {2,3,1,1,4}: " << (canJump(nums1) ? "True" : "False") << endl;
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Can jump to end for {3,2,1,0,4}: " << (canJump(nums2) ? "True" : "False") << endl;
    return 0;
}

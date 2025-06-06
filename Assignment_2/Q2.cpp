class Solution {
public:

    int solve(const vector<int>& nums) {
        
        int i = 0;
        int n = nums.size();

        if(n==1)
            return nums[0];

        vector<int> dp(n,-1);

        dp[n-1] = nums[n-1];

        if(n>=2)
        dp[n-2] = max(nums[n-1],nums[n-2]);

        for(int i = n-3 ; i>=0; i--)
        {
            int a = nums[i] + dp[i+2];
            int b = dp[i+1];

            dp[i] = max(a,b);
        }

        return dp[0];

    }

    int rob(vector<int>& nums) {

        if(nums.size() ==1)
            return nums[0];

        return max(solve(vector<int>(nums.begin()+1,nums.end())),solve(vector<int>(nums.begin(),nums.end()-1)));
    }
};
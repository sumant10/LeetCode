class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy(n+2,1);
        for(int i=0;i<n;i++){
            copy[i+1] = nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int k=1;k<=n;k++){
            for(int left=1;left<=n-k+1;left++){
                int right = left+k-1;
                for(int i=left;i<=right;i++){
                    dp[left][right]= max(dp[left][right], copy[left-1]*copy[i]*copy[right+1]+dp[left][i-1]+dp[i+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int mod = 1000000007;
        vector<vector<int>> dp(d+1, vector<int>(target+1));
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int sum=1;sum<=target;sum++){
                for(int k=1;k<=f;k++){
                    if(sum>=k){
                        dp[i][sum] = (dp[i][sum]%mod)+(dp[i-1][sum-k]%mod);
                        dp[i][sum] = dp[i][sum]%mod;
                    }
                }
            }
        }
        return dp[d][target];
    }
};

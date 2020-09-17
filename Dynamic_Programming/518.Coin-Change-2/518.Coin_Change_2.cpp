class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int sum=1;sum<amount+1;sum++){
                    int op1 = dp[i-1][sum];
                    int op2 = (sum<coins[i-1]) ? 0 : dp[i][sum-coins[i-1]];
                    dp[i][sum] = op1+op2;
            }
        }
        return dp[n][amount];
    }
};

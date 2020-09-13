class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m =dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)
                    dp[i][j] = min(0, dungeon[i][j]);
                else if(i==m-1)
                    dp[i][j] = min(0, dp[i][j+1]+dungeon[i][j]);
                else if(j==n-1)
                    dp[i][j] = min(0, dp[i+1][j]+dungeon[i][j]);
                else
                    dp[i][j] = min(0, max(dp[i][j+1],dp[i+1][j])+dungeon[i][j]);
            }
        }
        return abs(dp[0][0])+1;
    }
};

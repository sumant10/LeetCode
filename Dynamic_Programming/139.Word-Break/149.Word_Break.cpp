class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n]=1;
        set<string> dict;
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }
        for(int i=n-1;i>=0;i--){
            string word;
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end()){
                    if(dp[j+1]){
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[0];
    }
};

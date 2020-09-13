class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& temp,vector<int>& candidates, int target,int start){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            backtrack(temp,candidates,target-candidates[i],i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(temp,candidates,target,0);
        return result;
    }
};

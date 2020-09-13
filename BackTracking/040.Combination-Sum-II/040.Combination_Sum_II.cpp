class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& temp, vector<int>& candidates, int target, int start){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            backtrack(temp, candidates, target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(temp, candidates, target, 0);
        return result;
    }
};

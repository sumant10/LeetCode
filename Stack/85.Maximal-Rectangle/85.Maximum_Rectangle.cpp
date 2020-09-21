class Solution {
private:
    vector<int> nsl(vector<int> &arr){
        vector<int> left;
        stack<int> s;
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
                left.push_back(-1);
            }
            else if(arr[s.top()]<arr[i]){
                left.push_back(s.top());
            }
            else{
                while(!s.empty()&&arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(!s.empty())
                    left.push_back(s.top());
                else
                    left.push_back(-1);
            }
            s.push(i);
        }
        return left;
    }
    vector<int> nsr(vector<int> &arr){
        vector<int> right;
        stack<int> s;
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                right.push_back(arr.size());
            }
            else if(arr[s.top()]<arr[i]){
                right.push_back(s.top());
            }
            else{
                while(!s.empty()&&arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(!s.empty())
                    right.push_back(s.top());
                else
                    right.push_back(arr.size());
            }
            s.push(i);
        }
        reverse(right.begin(), right.end());
        return right;
    }
    int max_hist(vector<int> &arr){
        vector<int> left = nsl(arr);
        vector<int> right = nsr(arr);
        int maxArea = 0;
        for(int i=0;i<arr.size();i++){
            int base = right[i]-left[i]-1;
            maxArea = max(maxArea, base*arr[i]);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> grid(m, vector<int>(n,0));
        for(int i=0;i<n;i++)
            if(matrix[0][i]=='1')
                grid[0][i] = 1;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='0'){
                    grid[i][j] = 1+grid[i-1][j];
                }
            }
        }
        int res = 0;
        for(int i=0;i<m;i++){
            res = max(res, max_hist(grid[i]));
        }
        return res;
    }
};

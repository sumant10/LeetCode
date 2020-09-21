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
public:
    int largestRectangleArea(vector<int>& arr) {
        vector<int> left = nsl(arr);
        vector<int> right = nsr(arr);
        int maxArea = 0;
        for(int i=0;i<arr.size();i++){
            int base = right[i]-left[i]-1;
            maxArea = max(maxArea, base*arr[i]);
        }
        return maxArea;
    }
};

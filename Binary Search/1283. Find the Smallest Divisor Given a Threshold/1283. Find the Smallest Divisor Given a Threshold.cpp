class Solution {
public:
    bool isLess(vector<int>& nums, int threshold, int mid){
        int res =0;
        for(int i=0;i<nums.size();i++){
            int rem = nums[i]%mid;
            res += nums[i]/mid;
            res += rem==0 ? 0 :1;
        }
        return res <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1, end=1e6+1;
        int res = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isLess(nums, threshold, mid)){
                end = mid-1;
                res = min(res, mid);
            }
            else{
                start = mid+1;
            }
        }
        return res;
    }
};

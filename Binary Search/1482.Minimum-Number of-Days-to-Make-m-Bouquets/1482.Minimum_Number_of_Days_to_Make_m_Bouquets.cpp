class Solution {
public:
    bool isBouque(vector<int>& bloomDay, int m, int k, int day){
        int i=0;
        while(i<bloomDay.size()){
            int flower=0;
            while(i < bloomDay.size() && bloomDay[i]<=day){
                flower++;
                i++;
            }
            int possible = flower/k;
            m = m-possible;
            if(m<=0) return true;
            i++;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < m*k) return -1;
        int end=0;
        for(int i=0;i<n;i++){
            end = max(end, bloomDay[i]);
        }
        int start=0;
        int min_day = INT_MAX;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isBouque(bloomDay,m,k,mid)){
                end = mid-1;
                min_day = min(min_day,mid);
            }
            else{
                start = mid+1;
            }
        }
        return min_day;
    }
};

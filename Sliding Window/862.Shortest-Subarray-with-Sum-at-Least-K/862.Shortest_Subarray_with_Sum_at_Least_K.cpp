class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> B(A.size()+1);
        B[0]=A[0];
        for(int i=1;i<A.size();i++){
            B[i]=B[i-1]+A[i];
        }
        deque<int> d;
        int res = INT_MAX;
        for(int i=0;i<B.size();i++){
            if(B[i]>=K)
                res = min(res, i+1);
            while(!d.empty() && B[i] <= B[d.back()]){
                d.pop_back();
            }
            while(!d.empty() && B[i] - B[d.front()]>=K){
                res = min(res,i-d.front());
                d.pop_front();
            }
            d.push_back(i);
        }
        return res==INT_MAX ? -1 : res;
    }
};

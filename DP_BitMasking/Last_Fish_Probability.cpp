[Problem Link](https://codeforces.com/contest/16/problem/E)

#include <bits/stdc++.h>
using namespace std;
double prob[20][20];
double dp[(1<<19)];
 
double pMove(int prev_mask, int j,int &n){
    int k = __builtin_popcount(prev_mask);
    long long den = (k*(k-1))/2;
    double move_prob=0;
    for(int fish=0;fish<n;fish++){
        if(prev_mask&(1<<fish)){
            move_prob+=prob[fish+1][j+1];
        }
    }
    return move_prob/(1.0*den);
}
double solve(int bit_mask, int& n){
    int alive = __builtin_popcount(bit_mask);
    if(alive==n) return 1;
    if(dp[bit_mask]>-0.9) return dp[bit_mask];
    double ans = 0;
    for(int fish=0;fish<n;fish++){
        bool f = bit_mask & ((1<<fish));
        if(!f){
            int prev_mask = bit_mask ^ (1<<fish);
            double prev_prob = solve(prev_mask,n);
            ans+=prev_prob*pMove(prev_mask,fish,n);
        }
    }
    return dp[bit_mask] = ans;
}
 
int main(){
    int n; cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> prob[i][j];
        }
    }
    for(int i=0;i<n;i++)
        cout << fixed << setprecision(10) << solve((1<<i),n) << " ";
    
}

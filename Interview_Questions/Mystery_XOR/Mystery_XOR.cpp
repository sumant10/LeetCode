#include <bits/stdc++.h>
using namespace std;

vector<int> factsof2(100001,0);                             //factsof2[i] represent power of twos in i!
void preprocess(){
    for(int i=1;i<100000;i++){
        factsof2[i] = factsof2[i-1];
        int temp=i;
        while(temp%2==0){
            factsof2[i]++;
            temp/=2;
        }
    }
}
                                                          //given the subarray l,r what is top of pyramid
int topOfTriangle(vector<int> arr, int l, int r){
    int ans = 0;
    int total = r-l;
    for(int i=l;i<=r;i++){
        int twoPower = factsof2[total] - factsof2[i-l]-factsof2[total-(i-l)];
        if(!twoPower){
            ans^=arr[i];
        }
    }
    return ans;
}
int main() {
    preprocess();
    vector<int> arr;
    int n,m,k;
    cin >> n >> m >>k;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    cout << topOfTriangle(arr,m-1,k+m-1);
}

class Solution {
public:
    int timer = 0;
    vector<vector<int>> res;
    int vis[100001]; int in[100001]; int low[100001]; 
    void dfs(int node, int par, vector<vector<int>>& arr){
        vis[node]=1;
        in[node] = low[node] = timer;
        timer++;
        
        for(int child : arr[node]){
            if(child==par) continue;
            if(vis[child]==1){
                low[node]= min(low[node], in[child]);
            }
            else{
                dfs(child,node,arr);
                if(low[child]>in[node]){
                    res.push_back({node,child});
                }
                low[node] = min(low[child], low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> arr(n+1);
        for(int i=0;i<connections.size();i++){
            int a = connections[i][0], b = connections[i][1];
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        dfs(0,-1,arr);
        return res;
    }
};

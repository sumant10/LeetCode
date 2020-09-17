class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,int m,int n){
        if(x<0||x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m+1,vector<int>(n+1,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==2)
                    q.push({{i,j},0});
        int time = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            time = dist;
            vis[x][y]=1;
            q.pop();
            for(int i=0;i<4;i++){
                int r = x+dx[i];
                int c = y+dy[i];
                if(isValid(r,c,m,n) && vis[r][c]==0){
                    if(grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({{r,c},dist+1});
                    }
                }
            }
        }
        bool flag = true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag) return time;
        else return -1;
    }
};

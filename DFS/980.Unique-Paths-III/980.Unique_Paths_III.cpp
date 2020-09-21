class Solution {
public:
    int paths =0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>& grid, int r, int c,int zeros){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()|| grid[r][c]==-1 || grid[r][c]==-2){
            return;
        }
        if(grid[r][c]==2){
            if(zeros!=0) return;
            else paths++;
        }
        if(grid[r][c]==0) zeros--;
        int temp = grid[r][c];
        grid[r][c] = -2;
        for(int i=0;i<4;i++){
            dfs(grid, r+dx[i], c+dy[i], zeros);
        }
        grid[r][c] = temp;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m= grid.size(), n = grid[0].size();
        int sx,sy;
        int zeros=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    zeros++;
                else if(grid[i][j]==1){
                    sx = i, sy = j;
                }
            }
        }
        dfs(grid, sx, sy, zeros);
        return paths;
    }
};

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,int m,int n){
        if(x<0||x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>& board,int x, int y,int m, int n){
        board[x][y] = 'C';
        for(int i=0;i<4;i++){
            int r = x+dx[i];
            int c = y+dy[i];
            if(isValid(r,c,m,n)&&board[r][c]=='O')
                dfs(board,r,c,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==m-1||j==n-1){
                    if(board[i][j]=='O')
                        dfs(board, i, j, m, n);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='C')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};

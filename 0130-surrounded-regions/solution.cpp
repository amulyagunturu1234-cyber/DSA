class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        vector<vector<char>> vis(n,vector<char>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //first row and last row
               if(i==0 || i==n-1 ||j==0 ||j==m-1){
                if(board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
               }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                   && board[nrow][ncol]=='O' && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                   }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }

            }
        }
    }
};

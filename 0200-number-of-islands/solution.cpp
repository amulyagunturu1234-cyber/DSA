class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<char>> vis(n,vector<char>(m,0));
        queue<pair<int,int>>q;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,+1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    q.push({i,j});
                    vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
                }
            }
        }
        return cnt; 
    }
};

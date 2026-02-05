class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //bfs,queue
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,1,0,-1};
        int maxCnt=0;
        //connected components
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                            int cnt=1;
                
                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nrow=row+drow[i];
                        int ncol=col+dcol[i];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                        && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                            cnt++;
                        }
                    }
                }
                                        maxCnt=max(maxCnt,cnt);
            }
        }
        }
        return maxCnt;
    }
};

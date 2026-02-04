class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
            int n=grid.size();
            int m=grid[0].size();
            int og=grid[row][col];
            vector<pair<int,int>>border;
            vector<vector<int>>vis(n,vector<int>(m,0)); 
            queue<pair<int,int>>q;
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            q.push({row,col});
            vis[row][col]=1;
            while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    bool isBorder=false;
                    for(int k=0;k<4;k++){
                        //adj nodes prepared
                        int nrow=r+drow[k];
                        int ncol=c+dcol[k];
                        if(nrow<0 || nrow>=n || ncol<0 || ncol>=m ){
                        isBorder=true;
                        }
                        //its touching at least one square from outside the component
                        // i.e belongs to ther component
                        else if(grid[nrow][ncol]!=og){
                            isBorder=true;
                        }
                        else if(!vis[nrow][ncol]){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                        if(isBorder){
                            border.push_back({r,c});
                        }
            }
                    for(auto it:border){
                        grid[it.first][it.second]=color;
                    }
                    return grid;
    }
};

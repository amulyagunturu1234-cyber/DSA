class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>colo=image;
        int inicolor=image[sr][sc];
        if(inicolor==color) return image;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            colo[row][col]=color;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && colo[nrow][ncol]==inicolor){
                        colo[nrow][ncol]=color;
                        q.push({nrow,ncol});
                }
            }
        }
        return colo;
    }
};

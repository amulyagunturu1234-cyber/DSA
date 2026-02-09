class Solution {
public://dijkstaras algorithm
    int swimInWater(vector<vector<int>>& grid) {
        //we hv to wait till the elevation pt in present box is at most the value of their adj boxes
        //we need to choose the min
        //bfs
        int n=grid.size();
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,+1,0,-1};
       priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        pq.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        while(!pq.empty()){
            auto it=pq.top();
                int time=it.first;
                int row=it.second.first;
                int col=it.second.second;
                pq.pop();
                if(row==n-1 && col==n-1) return time;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n ){
                        //checked for constarints of neighbours
                        int newTime=max(time,grid[nrow][ncol]);//to return minm time
                        if(newTime<dis[nrow][ncol]){
                            dis[nrow][ncol]=newTime;
                            pq.push({newTime,{nrow,ncol}});
                        }
                    }
                }
        }
        return -1;
    }
};

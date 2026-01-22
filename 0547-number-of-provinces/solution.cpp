class Solution {
    private:
    void dfs(vector<vector<int>>& isConnected,vector<vector<int>>& adj,vector<int>& vis,
                int node,int cnt){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
            dfs(isConnected,adj,vis,it,cnt);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
            int n=isConnected.size();
            vector<vector<int>>adj(n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(isConnected[i][j]==1 && i!=j){
                        adj[i].push_back(j);
                    }
            }
            }
            vector<int>vis(n,0);
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(isConnected,adj,vis,i,cnt);
                }
            }
            return cnt;
    }
};

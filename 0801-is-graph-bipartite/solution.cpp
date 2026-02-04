class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //adjc list is given
        int n=graph.size();
        vector<int>color(n,-1);
                queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push({i});
        color[0]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                int adjNode=it;
                if(color[adjNode]==-1){
                    color[adjNode]=!color[node];
                    q.push(it);
                }
                else if(color[adjNode]==color[node]) return false;
            }
        }
            }
        }
                        return true;
    }
};

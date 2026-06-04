class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        for(auto &it:richer){
            int a=it[0];
            int b=it[1];
            graph[a].push_back(b);
            indegree[b]++;
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
       while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y:graph[x]){
            if(quiet[ans[x]]<quiet[ans[y]]) ans[y]=ans[x];
            indegree[y]--;
            if(indegree[y]==0) q.push(y);
        }
       }
       return ans; 
    }
};

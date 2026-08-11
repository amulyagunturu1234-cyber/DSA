class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        vector<long long>dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                long long edgWt=it.second;
                if(dist+edgWt<dis[adjNode]){
                    dis[adjNode]=dist+edgWt;
                    pq.push({dist+edgWt,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dist+edgWt==dis[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
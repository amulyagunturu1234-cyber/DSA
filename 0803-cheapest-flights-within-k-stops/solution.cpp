class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>>adj(n);
             for(auto it:flights){
                adj[it[0]].push_back({it[1],it[2]});
             }
             queue<pair<pair<int,int>,int>>q;
             q.push({{src,0},0});//node,cost,stops
             vector<int>dist(n,1e9);
             dist[src]=0;
             while(!q.empty()){
                int node=q.front().first.first;
                int cost=q.front().first.second;
                int stops=q.front().second;
                q.pop();
                if(stops>k) continue;
                for(auto it:adj[node]){
                    int adjNode=it.first;
                    int edgWt=it.second;
                    if(cost+edgWt<dist[adjNode]){
                        dist[adjNode]=cost+edgWt;
                        q.push({{adjNode,cost+edgWt},stops+1});

                    }
                }
             }
             if(dist[dst]==1e9) return -1;
             return dist[dst];
    }
};

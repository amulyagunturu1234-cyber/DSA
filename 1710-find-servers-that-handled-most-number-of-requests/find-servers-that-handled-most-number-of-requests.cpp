class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        // {time server becomes free, server id}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            int t = arrival[i];

            // Release all servers that have finished by time t
            while (!busy.empty() && busy.top().first <= t) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }

            // All servers busy: drop the request
            if (freeServers.empty()) continue;

            // First free server with id >= i % k, else wrap to the smallest
            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) it = freeServers.begin();

            int id = *it;
            freeServers.erase(it);
            busy.push({t + load[i], id});
            count[id]++;
        }

        int mx = *max_element(count.begin(), count.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (count[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};
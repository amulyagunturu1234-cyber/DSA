
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;

        priority_queue<tuple<long long,int,int>,
        vector<tuple<long long,int,int>>,
        greater<tuple<long long,int,int>>> busy;

        queue<int> waiting;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;
        int j = 0;

        while(j < m || !waiting.empty()) {

            if(waiting.empty() && j < m && time < j) {
                time = j;
            }

            // Add newly arrived tasks
            while(j < m && j <= time) {
                waiting.push(j);
                j++;
            }

            // Release free servers
            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();

                available.push({w, idx});
            }

            // Assign waiting tasks
            while(!available.empty() && !waiting.empty()) {

                int task = waiting.front();
                waiting.pop();

                auto [weight, idx] = available.top();
                available.pop();

                ans[task] = idx;

                busy.push({time + tasks[task], weight, idx});
            }

            // Move to the next available time
            if(!waiting.empty()) {
                time = get<0>(busy.top());
            }
            else if(j < m) {
                time = j;
            }
        }

        return ans;
    }
};

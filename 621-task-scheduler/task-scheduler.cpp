class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int freq[26] = {};

        for (char ch : tasks)
            freq[ch - 'A']++;

        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;

            for (int i = 0; i < n + 1; i++) {

                if (!pq.empty()) {

                    int f = pq.top();
                    pq.pop();

                    f--;

                    if (f > 0)
                        temp.push_back(f);

                    time++;
                }
                else {
                    // CPU is idle
                    if (!temp.empty())
                        time++;
                }
            }

            for (int f : temp)
                pq.push(f);
        }

        return time;
    }
};
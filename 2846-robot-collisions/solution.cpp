class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Create index array sorted by position
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> st; // stack of indices of right-moving robots
        
        for (int i : indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // directions[i] == 'L', handle collisions
                while (!st.empty() && healths[i] > 0) {
                    int top = st.top();
                    
                    if (healths[top] > healths[i]) {
                        // R wins, L dies
                        healths[top]--;
                        healths[i] = 0;
                    } else if (healths[top] < healths[i]) {
                        // L wins, R dies
                        healths[i]--;
                        healths[top] = 0;
                        st.pop();
                    } else {
                        // Both die
                        healths[top] = 0;
                        healths[i] = 0;
                        st.pop();
                    }
                }
            }
        }
        
        // Collect survivors in original order
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};

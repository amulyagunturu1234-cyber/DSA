class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort according to value
        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;

        while(i < n) {

            int j = i;

            // Find one connected component
            while(j + 1 < n && v[j+1].first - v[j].first <= limit) {
                j++;
            }

            // Values from i to j belong to same component
            vector<int> values;
            vector<int> indices;

            for(int k = i; k <= j; k++) {
                values.push_back(v[k].first);
                indices.push_back(v[k].second);
            }

            // Sort original indices
            sort(indices.begin(), indices.end());

            // values are already sorted because v is sorted

            // Put smallest values at smallest indices
            for(int k = 0; k < values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            i = j + 1;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int, greater<int>> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // k = 0 (single cell rhombus)
                st.insert(grid[i][j]);

                for(int k = 1; ; k++) {

                    int top_r = i - k;
                    int bottom_r = i + k;
                    int left_c = j - k;
                    int right_c = j + k;

                    if(top_r < 0 || bottom_r >= m || left_c < 0 || right_c >= n)
                        break;

                    int sum = 0;

                    int r = top_r, c = j;

                    // top -> right
                    while(r < i && c < right_c) {
                        sum += grid[r][c];
                        r++;
                        c++;
                    }

                    // right -> bottom
                    while(r < bottom_r && c > j) {
                        sum += grid[r][c];
                        r++;
                        c--;
                    }

                    // bottom -> left
                    while(r > i && c > left_c) {
                        sum += grid[r][c];
                        r--;
                        c--;
                    }

                    // left -> top
                    while(r > top_r && c < j) {
                        sum += grid[r][c];
                        r--;
                        c++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(int x : st) {
            ans.push_back(x);
            if(ans.size() == 3) break;
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>temp(k,vector<int>(k));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                temp[i][j]=grid[x+i][y+j];
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                grid[x+i][y+j]=temp[k-1-i][j];
            }
        }
        return grid;
    }
};

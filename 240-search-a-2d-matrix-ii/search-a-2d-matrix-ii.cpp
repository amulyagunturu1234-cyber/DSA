class Solution {
    private:
    bool f(vector<vector<int>>& mat,int target){
        int n=mat.size();
        int m=mat[0].size();
        int row=0;
        int col=m-1;
        while(row<n && col>=0){
            if(mat[row][col]==target) return true;
            else if(mat[row][col]>target) col--;
            else row++;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return f(matrix,target);
    }
};
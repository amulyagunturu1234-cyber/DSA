class Solution {
    private:
    vector<vector<int>>rotate(vector<vector<int>>&mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>res(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    res[i][j]=mat[n-1-j][i];
        return res;
    }
private:
    bool isEqual(vector<vector<int>>&a,vector<vector<int>>&b){
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]!=b[i][j])return false;
                    return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int r=0;r<4;r++){
            if(isEqual(mat,target)) return true;
            mat=rotate(mat);
        }
        return false;
    }
};

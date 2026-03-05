class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
            int n=mat.size();
            int m=mat[0].size();
            int special=0;
            vector<int>row(n,0);
            vector<int>col(m,0);
            //precomputing the no of 1s in a row and col by row and col lists
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]==1){
                        row[i]++;
                        col[j]++;
                    }
                }
            }    
            //checking where the element whos e value is 1 is having 1 one in its row and column
           for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                        special++;
                    }
                }
           }
           return special;
    }
};

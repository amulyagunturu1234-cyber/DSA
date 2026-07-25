class Solution { 
    private:
    bool checkRow(int row,int col,vector<vector<char>>& board,char tmp){
            for(int j=0;j<9;j++){
                if(j!=col && board[row][j]==tmp) return true;
            }
            return false;
        } 

        bool checkCol(int row,int col,vector<vector<char>>& board,char tmp){
            for(int i=0;i<9;i++){
                if(i!=row && board[i][col]==tmp) return true;
            }
            return false;
        }
         bool checkSq(int row,int col,vector<vector<char>>& board,char tmp){
            int strow=(row/3)*3;
            int stcol=(col/3)*3;
            for(int i=strow;i<strow+3;i++){
                for(int j=stcol;j<stcol+3;j++){
                    if((i!=row || j!=col) && board[i][j]==tmp) return true;
                }
            }
            return false;
         }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char tmp=board[i][j];
                if(checkRow(i,j,board,tmp)==true || checkCol(i,j,board,tmp)==true || 
                checkSq(i,j,board,tmp)==true) return false;
            }
        } 
        return true;
    }
};

class Solution {
    private:
    bool check(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
                i++;
                j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return check(i+1,j,s) || check(i,j-1,s);
            }
        }
        return true;
    }
};
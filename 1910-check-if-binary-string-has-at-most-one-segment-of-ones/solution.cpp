class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        //only these strings are acceptable here 1110000
        //11100
        for(int i=1;i<n;i++){
                if(s[i]=='1' && s[i-1]=='0'){
                    return false;
                }
        }
        return true;
    }
};

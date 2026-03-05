class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int start0=0;
        int start1=0;
        //possible paterns 01010101...
        //10101010....
        for(int i=0;i<n;i++){
            //1st pattern
           if(s[i]!=(i%2==0?'0':'1')) start0++;
           if(s[i]!=(i%2==0?'1':'0'))start1++;
        }
        return min(start0,start1);
    }
};

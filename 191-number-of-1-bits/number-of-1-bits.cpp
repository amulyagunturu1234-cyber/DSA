class Solution {
    private:
    string convert2Binary(int n){
        string res="";
        while(n!=1){
            if(n%2==1) res+='1';
            else res+='0';
            n=n/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
public:
    int hammingWeight(int n) {
        string s=convert2Binary(n);
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
        }
        return cnt+1;
    }
};
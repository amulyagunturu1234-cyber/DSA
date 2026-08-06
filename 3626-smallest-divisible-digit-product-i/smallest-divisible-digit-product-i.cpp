class Solution {
    int pro(int n){
        int ans=1;
        while(n>0){
            int dig=n%10;
            ans*=dig;
            n=n/10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        if(pro(n)%t==0) return n;
        else{
            int tmp=n;
            while(pro(tmp)%t!=0){
                tmp++;
            }
            return tmp;
        }
        return 0;
    }
};
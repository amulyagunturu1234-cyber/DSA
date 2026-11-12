class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))) cnt++;//d* 2 powwer cnt+1
            ans += (1LL << cnt);//2 power cnt+1;
            n=n-(d<<(cnt));
        }
        if(sign && ans > INT_MAX) return INT_MAX;
if(!sign && ans >= (1LL << 31)) return INT_MIN;

return sign ? (int)ans : -(int)ans;
    }
};
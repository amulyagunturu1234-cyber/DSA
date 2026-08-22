class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int pro=1;
        while(temp){
            int digit=temp%10;
            sum+=digit;
            pro*=digit;
            temp=temp/10;
        }
        if(n%(sum+pro)==0) return true;
         return false;
    }
};
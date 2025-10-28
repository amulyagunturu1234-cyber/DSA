class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long reverseNum=0;
        int lastDigit;
        while(x>0){
            lastDigit=x%10;
            reverseNum=reverseNum*10+lastDigit;
            x=x/10;
        }
        if(reverseNum==temp) return true;
        else return false;
        
    }
};

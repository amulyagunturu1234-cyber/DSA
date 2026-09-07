class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;//checking sign
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+'){
            i++;
        }
        long long num=0;
        while(i<n && s[i]>='0' && s[i]<='9'){
            num=num*10+(s[i]-'0');
            if(sign == 1 && num > INT_MAX) return INT_MAX;
            if(sign == -1 && -num < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(num * sign);
    }
};
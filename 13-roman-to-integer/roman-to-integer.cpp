class Solution {
public:
    int romanToInt(string s) {
        //largest to smallest we add
        //smallest to largest we subtract
        //if current val<nxt val subtract
         unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.length() && mp[s[i]]<mp[s[i+1]]){
                ans-=mp[s[i]];
            }
            else ans+=mp[s[i]];
        }
        return ans;
    }
};
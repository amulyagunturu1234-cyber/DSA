class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>ans;
        int n=strs.size();
        for(int i=0;i<strs[0].size();i++){//this loop for the characters inside a word
            for(int j=1;j<n;j++){//this loop for the words
            if(strs[j].size()<i || strs[j][i]!=strs[0][i]) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};

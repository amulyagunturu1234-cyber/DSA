class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for(char c : s)
            if(c == '1')
                ones++;

        string t = "1" + s + "1";

        vector<pair<char,int>> blocks;

        int i = 0;
        while(i < t.size()){

            int j = i;

            while(j < t.size() && t[j] == t[i])
                j++;

            blocks.push_back({t[i], j - i});

            i = j;
        }

        int ans = ones;

        // Every removable 1-block
        for(int i = 1; i + 1 < blocks.size(); i++){

            if(blocks[i].first == '1' &&
               blocks[i-1].first == '0' &&
               blocks[i+1].first == '0'){

                int gain = blocks[i-1].second + blocks[i+1].second;

                ans = max(ans, ones + gain);
            }
        }

        return ans;
    }
};

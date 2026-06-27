class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> cnt;

        for(int x: nums)
            cnt[x]++;

        int ans = 1;

        // Special handling for 1
        if(cnt.count(1)){
            ans = max(ans, cnt[1] % 2 ? cnt[1] : cnt[1]-1);
        }

        for(auto &[start,f] : cnt){

            if(start==1) continue;

            long long cur = start;
            int len = 0;

            while(true){

                if(!cnt.count(cur)){
                    len--;
                    break;
                }

                if(cnt[cur] >= 2){

                    len += 2;

                    if(cur > 1000000000LL/cur){
                        len--;
                        break;
                    }

                    cur = cur*cur;
                }
                else{

                    len++;
                    break;
                }
            }

            ans = max(ans,len);
        }

        return ans;
    }
};

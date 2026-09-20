class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        //pulse value=altrnating sum
        
        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++){
            if(i%2==0)
            pref[i+1]=pref[i]+nums[i];
            else pref[i+1]=pref[i]-nums[i];
        }
        long long pulse=pref[n];
        long long maxPref[2]={LLONG_MIN,LLONG_MIN};
        long long ans=pulse;
        for(int q=2;q<=n;q++){
            int x=q-2;
            maxPref[x%2]=max(maxPref[x%2],pref[x]);
            ans=max(ans,pulse+2*(maxPref[q%2]-pref[q]));
        }
        return ans;
    }
};
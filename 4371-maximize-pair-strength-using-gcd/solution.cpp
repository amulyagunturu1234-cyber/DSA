class Solution {
    private:
    int gcd(int a,int b){
    while(b){
        int t=a%b;
        a=b;
        b=t;
    }
return a;
    }
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int g=gcd(nums[i],nums[j]);
                 long long val = 1LL * nums[i] * nums[j] / (1LL * g * g);
                ans=max(ans,val);
            }
        }
            return ans;
    }
};

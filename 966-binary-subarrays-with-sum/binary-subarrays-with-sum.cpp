class Solution {
    private:
    int f(vector<int>&nums,int k){
        if(k<0) return 0;
        int n=nums.size();
        int l=0,r=0;
        int sum=0,cnt=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k) {
                sum-=nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        //f(nums,k)-f(nums,k-1) // f(nums,k) gives subarrays with sum less than or equal to k
        return f(nums,goal)-f(nums,goal-1);
    }
};